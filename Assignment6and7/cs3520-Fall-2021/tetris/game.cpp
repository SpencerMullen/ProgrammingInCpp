/* game.cpp --- 
 * 
 * Filename: game.cpp
 * Description: 
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 20
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2016 IUB
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */
#include <unistd.h>

#include <ncurses.h>

#include <ctime>

#include <iostream>	

#include <cstdlib>

#include <string.h>

#include <fstream>

#include <string>

#include "game.hpp"

#include "well.hpp"

#include "tetris.hpp"

#include "tetromino.hpp"

#include "key.hpp"

#include "score.hpp"

using namespace std;

void init_game(void) {
  int x, y;
}



int game(void) {
  static int state = INIT;
  tetromino_t * next = NULL;
  tetromino_t * current = NULL;
  well_t * w;
  int x, y;
  int c;
  int arrow;
  int score;
  int curr_time;
  int lives = 2;
  char username[10];
  int scores[10];
  int score_index;
  int curr_color = 1;
  struct timespec tim = {
    0,
    1000000
  }; // Each execution of while(1) is approximately 1mS
  struct timespec tim_ret;
  int move_counter = 0;
  int move_timeout = BASE_FALL_RATE;

    ifstream infile("scores.txt");
    string line;
		if (!infile) {
      for(int i = 0; i < 10; i++) {
        scores[i] = 0;
      }
    } else {
      for(int i = 0; i < 10; i++) {
        getline(infile, line);
        scores[i] = atoi(line.c_str());
      }
    }

    ofstream outfile("scores.txt");

  while (1) {
    switch (state) {
    case INIT: // Initialize the game, only run one time 
      initscr();
      start_color();

      init_pair(1, COLOR_RED, COLOR_BLACK);
      init_pair(2, COLOR_GREEN, COLOR_BLACK);
      init_pair(3, COLOR_YELLOW, COLOR_BLACK);
      init_pair(4, COLOR_BLUE, COLOR_BLACK);
      init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
      init_pair(6, COLOR_CYAN, COLOR_BLACK);
      init_pair(7, COLOR_WHITE, COLOR_BLACK);

      nodelay(stdscr, FALSE); // wait for characters using getch.  
      noecho(); // Do not echo input characters 
      getmaxyx(stdscr, y, x); // Get the screen dimensions 

      mvprintw(5, 0, "Enter a username");
      mvprintw(6, 0, "and press enter");
      getstr(username);
      
      nodelay(stdscr, TRUE); // Do not wait for characters using getch. 
      mvprintw(5, 0, "                ");
      mvprintw(6, 0, "               ");
      score = 0;
      score_index = 10;
      curr_time = 0;
      w = init_well(((x / 2) - (WELL_WIDTH / 2)), 1, WELL_WIDTH, WELL_HEIGHT);
      draw_well(w);
      mvprintw(7, ((x / 2) - (WELL_WIDTH / 2)) + 1, "####");
      mvprintw(8, ((x / 2) - (WELL_WIDTH / 2)) + 1, "####");
      mvprintw(9, ((x / 2) - (WELL_WIDTH / 2)) + 1, "####");
      mvprintw(10, ((x / 2) - (WELL_WIDTH / 2)) + 1, "####");
      mvprintw(10, ((x / 2) + (WELL_WIDTH / 2)) - 2, "####");
      mvprintw(11, ((x / 2) + (WELL_WIDTH / 2)) - 2, "####");
      mvprintw(12, ((x / 2) + (WELL_WIDTH / 2)) - 2, "####");
      mvprintw(13, ((x / 2) + (WELL_WIDTH / 2)) - 2, "####");
      srand(time(NULL)); // Seed the random number generator with the time. Used in create tet. 
      state = ADD_PIECE;
      
      break;
    case ADD_PIECE: // Add a new piece to the game
      if (next) {
        current = next;
        next = create_tetromino((w -> upper_left_x + (w -> width / 2)), w -> upper_left_y);
      } else {
        current = create_tetromino((w -> upper_left_x + (w -> width / 2)), w -> upper_left_y);
        next = create_tetromino((w -> upper_left_x + (w -> width / 2)), w -> upper_left_y);
      }
      display_tetromino(current);

      state = MOVE_PIECE;
      break;
      // Handle moving the piece
    case MOVE_PIECE: // Move the current piece 
      // display next piece
      mvprintw(15, 5, "Next Piece");
      for (int x=0;x<4;x++) {
         for (int y=0;y<+4;y++) {
           if (next->piece[x][y]) {
             mvprintw(16+y, 5+x,"%c",next->draw_char);
            } else {
              mvprintw(16+y, 5+x," ");
            }
          }
        }
        mvprintw(2, 2, "Username: %s", username);
        mvprintw(4, 2, "Lives: %d", lives);
        mvprintw(6, 2, "Time: %d", curr_time/1000);
      if ((arrow = read_escape( & c)) != NOCHAR) {
        switch (arrow) {
          // Up key (rotate clockwise)
        case UP:
          mvprintw(10, 10, "UP            ");
          undisplay_tetromino(current);
          rotate_cw(current);
          display_tetromino(current);
          break;
          // Down key (rotate coutner clockwise)
        case DOWN:
          mvprintw(10, 10, "DOWN          ");
          undisplay_tetromino(current);
          rotate_ccw(current);      
          display_tetromino(current);
          break;
          // Left key (move left)
        case LEFT:
          undisplay_tetromino(current);
          move_tet(current, current -> upper_left_x - 1, current -> upper_left_y);
          display_tetromino(current);
          mvprintw(10, 10, "LEFT          ");
          break;
          // Right key (move right)
        case RIGHT:
          undisplay_tetromino(current);
          move_tet(current, current -> upper_left_x + 1, current -> upper_left_y);
          display_tetromino(current);
          mvprintw(10, 10, "RIGHT         ");
          break;
          // Case if reg character
        case REGCHAR:
          mvprintw(10, 10, "REGCHAR 0x%02x", c);
          // Quit
          if (c == 'q') {
            state = EXIT;
          }
          if (c == ' ') {
            move_timeout = DROP_RATE;
          }
        }
      }
      if (move_counter++ >= move_timeout) {
        undisplay_tetromino(current);
        if (move_tet(current, current -> upper_left_x, current -> upper_left_y + 1) == MOVE_FAILED) {
          display_tetromino(current);
		  score = compute_score(score, prune_well(w));
		  if(current->upper_left_y == w->upper_left_y)
			state = GAME_OVER;
		  else
          	state = ADD_PIECE;
        } else 
      display_tetromino(current);
      move_timeout = BASE_FALL_RATE;
      move_counter = 0;
      }
      break;
	case GAME_OVER:
		clear();
		mvprintw(10, 10, "GAME OVER");
		mvprintw(20, 10, "SCORE: %d", score);

    if(score > scores[9]){
      for(int i = 8; i > -1; i--) {
        if(i == 0) {
          score_index = 0;
        }
        if(score < scores[i])
          score_index = i + 1;
      }
    }

    if(score_index < 10) {
      for(int i = 9; i > score_index - 1; i--) {
        if(i == score_index)
          scores[i] = score;
        else
          scores[i] = scores[i - 1];
      }
    }

    for(int i = 0; i < 10; i++) {
      outfile << scores[i] << endl;
    }

    lives -= 1;
    if(lives > 0)
      mvprintw(22, 10, "Press a key to continue.");
    else 
      mvprintw(22, 10, "No more lives.");
    nodelay(stdscr, FALSE);
    getch();
    nodelay(stdscr, TRUE);
    if(lives > 0) {
      clear();
      state = INIT;
    }
		break;
  case EXIT:
    endwin();
    return (0);
    break;
  }      
    curr_time ++;
    curr_color = (curr_time % 1000) % 7 + 1;
    refresh();
    nanosleep( & tim, & tim_ret);
    
  }
}

/* game.cpp ends here */