#pragma once
#include <string>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;
using std::string;
using std::cout;
using std::cin;
using std::exit;



class Game {
public:
	int i;
	int Generator(int difficultylevel) {
		int defaultMax = 5;
		int RmNumber = rand() % defaultMax ^ (difficultylevel + 1);
		return RmNumber;
	}

	int DifficultySel(string Diff) {
		int level;
		if (Diff == "Easy") {
			level = 0;
			return level;
		}
		else if (Diff == "Hard") {
			level = 1;
			return level;
		}
		else if (Diff == "Nightmare") {
			level = 2;
			return level;
		}
		else {
			cout << "Invalid difficulty input. Make sure you can spell.";
		}
	}

	void Responses(int difficultyLevel) {
		string Vict0 = "(SARCASM) Wow you won. You sure are something else.";
		string Vict1 = "That's more like it. I guess.";
		string Vict2 = "Damn you good at guessing. Out of 125 possible outcomes you got lucky and guessed correct. Good for you.(Lucky guess...";
		switch (difficultyLevel) {
		case 0:
			cout << Vict0;
		case 1:
			cout << Vict1;
		case 2:
			cout << Vict2;
		}

	}
	void run() {

		Game game;
		while (true) {
			string difficulty;
			cout << "\n Insert preferred difficulty. (Easy, Hard, Nightmare): ";
			cin >> difficulty;
			cout << "User chose " << difficulty;
			int DiffLevel = game.DifficultySel(difficulty);
			int MagicNumber = game.Generator(DiffLevel);

			for (i = 0; i < 4; i++) {
				cout << "Guess the magic number: ";
				string input;
				cin >> input;
				if (stoi(input) == MagicNumber) {
					game.Responses(DiffLevel);
					cout << "Play again? Type y/n ";
					string option;
					cin >> option;
					if (option == "y") {
						i = 4;
					}
					else if (option == "n") {
						break;
					}


				}
				else if (stoi(input) < MagicNumber) {
					cout << input << "is less than " << MagicNumber;
				}
				else if (stoi(input) > MagicNumber) {
					cout << input << "is greater than " << MagicNumber;
				}
				cout << i;
				/*else if (i == 5 || i > 5) {
					cout << "Out of tries.";
					game.menu();
				}*/

			}
		}
	}
	/*void menu(){
		Game game;
		cout << "Play again? Type y/n";
		string option;
		cin >> option;
		if (option == "y" || option == "Y") {
			i = 4;
		}
		else if (option == "n" || option == "N") {
			EXIT_SUCCESS;
		}
	}*/

		
		

		
	}
	;
