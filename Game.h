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
using std::stoi;

class Game {
public:

	void responses(int difficultyLevel) {
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
	int difficultySel() {
		while (true) {
			cout << "Enter a difficulty level (Easy, Hard or Nightmare): ";
			string Diff;
			cin >> Diff;
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
				continue;

			}
		}
		
		
		
	}

	int generator(int difficultylevel) {
		srand(time(0));
		int defaultMax = 5;
		int RmNumber = rand() % defaultMax ^ (difficultylevel + 1);
		return RmNumber;
	}
	
	void run() {
		Game game;
		while (true) {
			
			int Difficulty = game.difficultySel();
			int MagicNumber = game.generator(Difficulty);
			int remaining_tries = 6;
			for (int i = 0; i < 6; i++) {
				cout << "Guess which number I'm thinking of: ";
				string input;
				cin >> input;
				//remaining_tries = remaining_tries - 1;
				if (stoi(input) < MagicNumber) {
					cout << input << "is less than the Magic Number. Remaining tries: " << remaining_tries;
				}
				else if (stoi(input) > MagicNumber) {
					cout << input << "is greater than the Magic Number. Remaining tries: " << remaining_tries;
				}
				/*else if (remaining_tries < 1) {
					cout << "You are out of tries. Would you like to play again? y/n: ";
					string again;
					cin >> again;
					if(again == "y"){
						return;
					}
					else if (again == "n") {
						exit(0);
					}
					return; 
				} */
				else if (stoi(input) == MagicNumber) {
					game.responses(Difficulty);
					cout << " Would you like to play again? y/n: ";
					string option;
					cin >> option;
					if (option == "y") {
						return;
					}
					else if (option == "n") {
						exit(0);
					}
					return;
				}
			}
			cout << "Out of tries. DOOOI Would you like to play again? y/n";
			string again;
			cin >> again;
			if (again == "y") {
				return;
			}
			else if (again == "n") {
				exit(0);
			}
			

		}
	}
};