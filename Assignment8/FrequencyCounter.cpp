// Spencer Mullen
// 11/15/2021
// Assignment 8 Frequency Counter

#include <iostream>
#include <string>
#include<limits>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include <algorithm>
#include<array>
#include<cstring>
#include<typeinfo>
#include<map>
#include<utility>

using namespace std;

bool sort_end(string i, string j) { 
	return (static_cast<int>(i[i.length()-1]) < static_cast<int>(j[j.length()-1])); 
}

int main() {
	// Number of lines in the file
	int num_lines = 0;
	// Number of words in the file
	int num_words = 0;
	// Number of words that start with a vowel
	int vowel_start = 0;
	// Map representing words and their frequencies in the file
	map<string, int> frequencies;
	// Map representing words that start with vowels and their frequencies
	map<string, int> v_frequencies;
	// Map representing word frequencies of a certain length
	map<int, int> len_frequencies;
	// Struct reprenting the word info of a word
	struct word_info {
		string name;
		int count;
		int length;
	};
	// Vector storing the word info to be sorted by num occurrences
	vector<word_info> words_info;
	// Set representing the word positions
	map<string, vector<int>> positions;

	// Prompt user for file name
	string user_file;
	cout << "Enter the name of the text file: ";
	cin >> user_file;

	// Read from file
	ifstream infile(user_file);
	if (!infile) {
		cout << "Can't open the file" << endl;
		return EXIT_FAILURE;
	}

	int min_length;
	cout << "Enter the minimum length of words: ";
	cin >> min_length;

	// Read through the file
	string line;
	char st[500];
	string word;
	while (getline(infile, line)) {
		num_lines++;

		// Calculate values
		const char delta[] = " ";
		// Convert line into a cstring to use strtok on
		strcpy(st, line.c_str());

		if (strlen(st) != 0) {
			// Returns the string up to that token
			char* tok = strtok(st, delta);

			// Continue until you reach the end of the line
			while (tok) {
				// Words
				num_words++;
				word = "";
				word += tok;

				/*
				// Remove punctuation
				for (int i = 0, len = word.size(); i < len; i++) {
					if (ispunct(word[i]))
					{
						word.erase(i--, 1);
						len = word.size();
					}
				}
				*/

				// Frequencies
				if (frequencies.find(word) != frequencies.end()) {
					frequencies.find(word)->second++;
				} else {
					pair<string, int> word_pair = {word, 1};
					frequencies.insert(word_pair);
				}

				// Vowels
				if (tolower(word[0]) == 'a' || tolower(word[0]) == 'e' || tolower(word[0]) == 'i' || tolower(word[0]) == 'o' || tolower(word[0]) == 'u') {
					string lower = "";
					for (auto c : word) {
						lower += tolower(c);
					}
					if (v_frequencies.find(lower) != v_frequencies.end()) {
						v_frequencies.find(lower)->second++;
					} else {
						pair<string, int> word_pair = { lower, 1 };
						v_frequencies.insert(word_pair);
						vowel_start += 1;
					}
				}

				// Word length
				if (len_frequencies.find(word.length()) != len_frequencies.end()) {
					if (frequencies.find(word) != frequencies.end()) {
						len_frequencies.find(word.length())->second++;
					}
				}
				else {
					pair<int, int> freq = { word.length(), 1 };
					len_frequencies.insert(freq);
				}

				// Word positions
				if (positions.find(word) != positions.end()) {
					positions.find(word)->second.push_back(num_words);
				} else {
					vector<int> v = {num_words};
					pair<string, vector<int>> pos = { word, v };
					positions.insert(pos);
				}

				tok = strtok(nullptr, delta);
			}
		}
	}

	// Sort word infos

	/*
	// Write to statistics.txt outfile
	string user_out_file = "statistics.txt";

	// Write to file the results
	ofstream outfile(user_out_file);
	if (!outfile) {
		cout << "Can't open the file" << endl;
		return EXIT_FAILURE;
	}*/

	// Calculate words with lengths equal to or less than given length
	int len_count = 0;
	for (int i = 1; i <= min_length; i++) {
		if (len_frequencies.find(word.length()) != len_frequencies.end()) {
			len_count += (len_frequencies.find(word.length())->second);
		}
	}

	// Word Length and Frequencies for Vowel Starting Words
	cout << user_file << " has " << num_words << " number of words\n";
	cout << user_file << " has " << num_lines << " number of lines\n";
	cout << user_file << " has " << vowel_start << " distinct words that start with a vowel\n";
	vector<string> vowel_strings;
	stringstream ss1;
	for (auto const& pair : v_frequencies) {
		ss1 << pair.first << " {Word Length: " << pair.first.length() << "}: " << pair.second;
		vowel_strings.push_back(ss1.str());
		ss1.str("");
	}
	sort(vowel_strings.begin(), vowel_strings.end(), sort_end);
	for (string s : vowel_strings) {
		cout << s << '\n';
	}
	// Distinct Words With Length
	cout << user_file << " has " << len_count << " distinct words with length " << min_length << " or less\n";
	vector<string> position_strings;
	stringstream ss2;
	for (auto const& pair : positions) {
		if (pair.first.length() <= min_length) {
			ss2 << pair.first << " {Word Positions: ";
			for (auto v : pair.second) {
				ss2 << v << ", ";
			}
			ss2 << "\b\b}: " << pair.first.length();
			position_strings.push_back(ss2.str());
			ss2.str("");
		}
	}
	sort(position_strings.begin(), position_strings.end(), sort_end);
	for (string s : position_strings) {
		cout << s << '\n';
	}
}