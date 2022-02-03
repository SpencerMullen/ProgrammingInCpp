// Spencer Mullen
// 11/22/2021
// Assignment 9 - Predator Prey Simulation

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <cstring>
#include <typeinfo>
#include <time.h> 
#include <stdlib.h>

using namespace std;

class Organism {
public:
	Organism() {
		//cout << "Organism ";
	}
	virtual void move(vector<vector<Organism*>>& world) {
		//cout << "OrganismMove ";
	}
	virtual void breed(vector<vector<Organism*>>& world) {
		//cout << "OrganismBreed ";
	}
	virtual void starve(vector<vector<Organism*>>& world) {

	}
	virtual string print_val() {
		return " ";
	}
	Organism operator++() {
		return *this;
	};
	virtual int gety() {
		return -1;
	}
	virtual int getx() {
		return -1;
	}
	virtual int getstep() {
		return -1;
	}
	virtual void setMove() {

	}
};

class DoodleBug : public Organism {
private:
	int steps;
	int eat_steps;
	int x;
	int y;
	bool moved;
public:
	DoodleBug(int y, int x, int steps, int eat_steps, bool moved) {
		//cout << "DoodleBug ";
		this->y = y;
		this->x = x;
		this->steps = steps;
		this->eat_steps = eat_steps;
		this->moved = moved;
	}
	DoodleBug operator++() {
		steps++;
		eat_steps++;
		return *this;
	}
	bool isSurrounded(vector<vector<Organism*>>& world) {
		return ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
			&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "));
	}
	void move(vector<vector<Organism*>>& world) {
		if (moved == true)
			return;
		// Eat above
		if (this->y != 0) {
			if (world[y - 1][x]->print_val() == "o") {
				world[y - 1][x] = new DoodleBug(y - 1, x, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		else {
			if (world[99][x]->print_val() == "o") {
				world[99][x] = new DoodleBug(99, x, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		// Eat below
		if (this->y != 99) {
			if (world[y + 1][x]->print_val() == "o") {
				world[y + 1][x] = new DoodleBug(y + 1, x, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		else {
			if (world[0][x]->print_val() == "o") {
				world[0][x] = new DoodleBug(0, x, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		// Eat left
		if (this->x != 0) {
			if (world[y][x - 1]->print_val() == "o") {
				world[y][x - 1] = new DoodleBug(y, x - 1, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		else {
			if (world[y][99]->print_val() == "o") {
				world[y][99] = new DoodleBug(y, 99, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		// Eat right
		if (this->x != 99) {
			if (world[y][x + 1]->print_val() == "o") {
				world[y][x + 1] = new DoodleBug(y, x + 1, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}
		else {
			if (world[y][0]->print_val() == "o") {
				world[y][0] = new DoodleBug(y, 0, ++steps, 0, false);
				world[y][x] = new Organism();
				return;
			}
		}

		// If surrounded
		if (this->y != 0 && this->x != 0 && this->y != 99 && this->x != 99) {
			if (this->isSurrounded(world)) {
				return;
			}
		}
		if (this->y == 0 && this->x != 0 && this->x != 99) {
			if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->y == 99 && this->x != 0 && this->x != 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 0 && this->y != 0 && this->y != 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 99 && this->y != 0 && this->y != 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
				return;
		}
		if (this->x == 0 && this->y == 0) {
			if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 0 && this->y == 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
				&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 99 && this->y == 0) {
			if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
				return;
		}
		if (this->x == 99 && this->y == 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
				return;
		}
		int rand_step = rand() % 4;
		// Up
		if (rand_step == 0) {
			if (this->y != 0) {
				if (world[y - 1][x]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(y - 1, x, ++steps, ++eat_steps, false);
					world[y - 1][x] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
			// If at top row
			else {
				if (world[99][x]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(99, x, ++steps, ++eat_steps, false);
					world[99][x] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
		}
		// Right
		else if (rand_step == 1) {
			if (this->x != 99) {
				if (world[y][x + 1]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(y, x + 1, ++steps, ++eat_steps, false);
					world[y][x + 1] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
			// If at right most row
			else {
				if (world[y][0]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(y, 0, ++steps, ++eat_steps, false);
					world[y][0] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
		}
		// Left
		else if (rand_step == 2) {
			if (this->x != 0) {
				if (world[y][x - 1]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(y, x - 1, ++steps, ++eat_steps, false);
					world[y][x - 1] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
			// If at left most row
			else {
				if (world[y][99]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(y, 99, ++steps, ++eat_steps, false);
					world[y][99] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
		}
		// Down
		else if (rand_step == 3) {
			if (this->y != 99) {
				if (world[y + 1][x]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(y + 1, x, ++steps, ++eat_steps, false);
					world[y + 1][x] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
			// If at bottom row
			else {
				if (world[0][x]->print_val() == " ") {
					Organism* new_ant = new DoodleBug(0, x, ++steps, ++eat_steps, false);
					world[0][x] = new_ant;
					world[y][x] = new Organism();
				}
				else move(world);
			}
		}
	};
	void breed(vector<vector<Organism*>>& world) {
		if (this->steps >= 10) {
			if (this->y == 0 && this->x != 0 && this->x != 99) {
				if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->y == 99 && this->x != 0 && this->x != 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 0 && this->y != 0 && this->y != 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 99 && this->y != 0 && this->y != 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
					return;
			}
			if (this->x == 0 && this->y == 0) {
				if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 0 && this->y == 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
					&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 99 && this->y == 0) {
				if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
					return;
			}
			if (this->x == 99 && this->y == 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
					return;
			}
			int rand_step = rand() % 4;
			// Up
			if (rand_step == 0) {
				if (this->y != 0) {
					if (world[y - 1][x]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(y - 1, x, 0, 0, false);
						world[y - 1][x] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0, eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at top row
				else {
					if (world[99][x]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(99, x, 0,0, false);
						world[99][x] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
			// Right
			else if (rand_step == 1) {
				if (this->x != 99) {
					if (world[y][x + 1]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(y, x + 1, 0,0, false);
						world[y][x + 1] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at right most row
				else {
					if (world[y][0]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(y, 0, 0,0, false);
						world[y][0] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
			// Left
			else if (rand_step == 2) {
				if (this->x != 0) {
					if (world[y][x - 1]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(y, x - 1, 0,0, false);
						world[y][x - 1] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at left most row
				else {
					if (world[y][99]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(y, 99, 0,0, false);
						world[y][99] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
			// Down
			else if (rand_step == 3) {
				if (this->y != 99) {
					if (world[y + 1][x]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(y + 1, x, 0,0, false);
						world[y + 1][x] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at bottom row
				else {
					if (world[0][x]->print_val() == " ") {
						Organism* new_ant = new DoodleBug(0, x, 0,0, false);
						world[0][x] = new_ant;
						world[y][x] = new DoodleBug(y, x, 0,eat_steps, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
		}
	}
	void starve(vector<vector<Organism*>>& world) {
		if (this->eat_steps >= 5) {
			world[y][x] = new Organism();
			delete(this);
		}
	};
	string print_val() {
		return "X";
	}
	int gety() {
		return this->y;
	}
	int getx() {
		return this->x;
	}
	void setMove() {
		this->moved = false;
	}
};

class Ant : public Organism {
private:
	int steps;
	int x;
	int y;
	bool moved;
public:
	Ant(int y, int x, int steps, bool moved) {
		//cout << "Ant ";
		this->y = y;
		this->x = x;
		this->steps = steps;
		this->moved = moved;
	}
	bool isSurrounded(vector<vector<Organism*>>& world) {
		return ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
			&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "));
	}
	void starve(vector<vector<Organism*>>& world) {}
	void move(vector<vector<Organism*>>& world) {
		if (this->moved == true)
			return;
		// Handle surrounded cases
		if (this->y != 0 && this->x != 0 && this->y != 99 && this->x != 99) {
			if (this->isSurrounded(world)) {
				return;
			}
		}
		if (this->y == 0 && this->x != 0 && this->x!=99) {
			if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->y == 99 && this->x != 0 && this->x != 99) {
			if ((world[y-1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 0 && this->y != 0 && this->y != 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 99 && this->y != 0 && this->y != 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][x-1]->print_val() != " ") && (world[y][0]->print_val() != " "))
				return;
		}
		if (this->x == 0 && this->y == 0) {
			if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][99]->print_val() != " ") && (world[y][x+1]->print_val() != " "))
				return;
		}
		if (this->x == 0 && this->y == 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
				&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
				return;
		}
		if (this->x == 99 && this->y == 0) {
			if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
				return;
		}
		if (this->x == 99 && this->y == 99) {
			if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
				&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
				return;
		}
		int rand_step = rand() % 4;
		// Up
		if (rand_step == 0) {
			if (this->y != 0) {

				if (world[y - 1][x]->print_val() == " ") {
					Organism* new_ant = new Ant(y - 1, x, (steps + 1), true);
					world[y - 1][x] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
			// If at top row
			else {
				if (world[99][x]->print_val() == " ") {
					Organism* new_ant = new Ant(99, x, (steps + 1), true);
					world[99][x] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
		}
		// Right
		else if (rand_step == 1) {
			if (this->x != 99) {
				if (world[y][x + 1]->print_val() == " ") {
					Organism* new_ant = new Ant(y, x + 1, (steps + 1), true);
					world[y][x + 1] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
			// If at right most row
			else {
				if (world[y][0]->print_val() == " ") {
					Organism* new_ant = new Ant(y, 0, (steps + 1), true);
					world[y][0] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
		}
		// Left
		else if (rand_step == 2) {
			if (this->x != 0) {
				if (world[y][x - 1]->print_val() == " ") {
					Organism* new_ant = new Ant(y, x - 1, (steps + 1), true);
					world[y][x - 1] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
			// If at left most row
			else {
				if (world[y][99]->print_val() == " ") {
					Organism* new_ant = new Ant(y, 99, (steps + 1), true);
					world[y][99] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
		}
		// Down
		else if (rand_step == 3) {
			if (this->y != 99) {
				if (world[y + 1][x]->print_val() == " ") {
					Organism* new_ant = new Ant(y + 1, x, (steps + 1), true);
					world[y + 1][x] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
			// If at bottom row
			else {
				if (world[0][x]->print_val() == " ") {
					Organism* new_ant = new Ant(0, x, (steps + 1), true);
					world[0][x] = new_ant;
					world[y][x] = new Organism();
					steps = INT_MIN;
					delete(this);
				}
				else {
					move(world);
					return;
				}
			}
		}
	}
	Ant operator++() {
		steps++;
		return *this;
	}

	void breed(vector<vector<Organism*>>& world) {
		if (this->steps >= 5) {
			if (this->y == 0 && this->x != 0 && this->x != 99) {
				if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->y == 99 && this->x != 0 && this->x != 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 0 && this->y != 0 && this->y != 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 99 && this->y != 0 && this->y != 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
					return;
			}
			if (this->x == 0 && this->y == 0) {
				if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 0 && this->y == 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
					&& (world[y][99]->print_val() != " ") && (world[y][x + 1]->print_val() != " "))
					return;
			}
			if (this->x == 99 && this->y == 0) {
				if ((world[99][x]->print_val() != " ") && (world[y + 1][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
					return;
			}
			if (this->x == 99 && this->y == 99) {
				if ((world[y - 1][x]->print_val() != " ") && (world[0][x]->print_val() != " ")
					&& (world[y][x - 1]->print_val() != " ") && (world[y][0]->print_val() != " "))
					return;
			}
			int rand_step = rand() % 4;
			// Up
			if (rand_step == 0) {
				if (this->y != 0) {
					if (world[y - 1][x]->print_val() == " ") {
						Organism* new_ant = new Ant(y - 1, x, 0, false);
						world[y - 1][x] = new_ant;
						world[y][x] = new Ant(y, x, 0, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at top row
				else {
					if (world[99][x]->print_val() == " ") {
						Organism* new_ant = new Ant(99, x, 0, false);
						world[99][x] = new_ant;
						world[y][x] = new Ant(y, x, 0, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
			// Right
			else if (rand_step == 1) {
				if (this->x != 99) {
					if (world[y][x + 1]->print_val() == " ") {
						Organism* new_ant = new Ant(y, x + 1, 0, false);
						world[y][x + 1] = new_ant;
						world[y][x] = new Ant(y, x, 0,false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at right most row
				else {
					if (world[y][0]->print_val() == " ") {
						Organism* new_ant = new Ant(y, 0, 0,false);
						world[y][0] = new_ant;
						world[y][x] = new Ant(y, x, 0,false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
			// Left
			else if (rand_step == 2) {
				if (this->x != 0) {
					if (world[y][x - 1]->print_val() == " ") {
						Organism* new_ant = new Ant(y, x - 1, 0,false);
						world[y][x - 1] = new_ant;
						world[y][x] = new Ant(y, x, 0,false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at left most row
				else {
					if (world[y][99]->print_val() == " ") {
						Organism* new_ant = new Ant(y, 99, 0,false);
						world[y][99] = new_ant;
						world[y][x] = new Ant(y, x, 0,false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
			// Down
			else if (rand_step == 3) {
				if (this->y != 99) {
					if (world[y + 1][x]->print_val() == " ") {
						Organism* new_ant = new Ant(y + 1, x, 0,false);
						world[y + 1][x] = new_ant;
						world[y][x] = new Ant(y, x, 0,false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
				// If at bottom row
				else {
					if (world[0][x]->print_val() == " ") {
						Organism* new_ant = new Ant(0, x, 0, false);
						world[0][x] = new_ant;
						world[y][x] = new Ant(y, x, 0, false);
						steps = INT_MIN;
						delete(this);
					}
					else breed(world);
				}
			}
		}
	};
	string print_val() {
		return "o";
	}
	int gety() {
		return this->y;
	}
	int getx() {
		return this->x;
	}
	int getstep() {
		return this->steps;
	}
	void setMove() {
		this->moved = false;
	}
};

void step_world(vector<vector<Organism*>>& world, vector<Organism*> &doodle_bugs, vector<Organism*> &ants) {
	/*
	vector<Organism*> new_doodle_bugs;
	for (Organism* o : doodle_bugs) {
		o->move(world);
		o++;
	}
	vector<Organism*> new_ants;
	for (Organism* o : ants) {
		o->move(world);
		Organism* new_ant = world[o->gety()][o->getx()];
		new_ants.push_back(new_ant);
		o++;
	}
	ants.clear();
	ants = new_ants;*/
	// DoodleBugs Move
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (world[i][j]->print_val() == "X") {
				world[i][j]->move(world);
			}
		}
	}
	// Ants Move
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (world[i][j]->print_val() == "o") {
				world[i][j]->move(world);
			}
		}
	}
	// Breed
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			world[i][j]->starve(world);
			world[i][j]->breed(world);
		}
	}

	// Reset vals
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (world[i][j]->print_val() == "o" || world[i][j]->print_val() == "X") {
				world[i][j]->setMove();
			}
		}
	}
}

void print_world(vector<vector<Organism*>>& world) {
	//for (vector<vector<Organism*>>::iterator row = world.begin(); row != world.end(); ++row) {
	//	for (vector<Organism*>::iterator col = row->begin(); col != row->end(); ++col) {
	//		cout << col.print_val();
	//	}
	//}
	cout << "------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (j == 0) cout << "|";
			cout << world[i][j]->print_val();
			if (j == 99) cout << "|";
		} 
		cout << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------\n";
}

int main() {
	srand(time(NULL));

	vector<Organism*> doodle_bugs;
	vector<Organism*> ants;
	vector<vector<Organism*>> world;

	// Set values to default
	for (int i = 0; i < 100; i++) {
		vector<Organism*> row = {};
		world.push_back(row);
		for (int j = 0; j < 100; j++) {
			Organism* o = new Organism();
			world[i].push_back(o);
		}
	}

	// Add doodle bugs + ants
	for (int i = 0; i < 10; i++) {
		Organism* d = new DoodleBug(i*10, i * 10 + 1, 0, 0, false);
		world[i*10][i * 10 + 1] = d;
		doodle_bugs.push_back(d);
	}

	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			Organism* a = new Ant(j * 10, k * 10, 0, false);
			world[j * 10][k * 10] = a;
			ants.push_back(a);
		}
	}

	print_world(world);
	cout << "\nPress enter to continue...\n";
	bool doodles = true, found_doodle = false;
	while (doodles) {
		try {
			cin.ignore();
			// Step
			step_world(world, doodle_bugs, ants);
			print_world(world);
			cout << "\nPress enter to continue...\n";
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					if (world[i][j]->print_val() == "X") {
						found_doodle = true;
					}
					if (found_doodle == false && i == 99 && j == 99 && world[i][j]->print_val() != "X")
						doodles = false;
				}
			}
			found_doodle = false;
		}
		catch(const std::exception& e) {
			return EXIT_SUCCESS;
		}
	}

	cout << "No more doodle bugs";
}