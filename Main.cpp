#include <iostream>
#include "Game.h"
using std::cout;
using std::cin;
using std::string;
using std::stoi;

int main() 
{	

	/*srand(time(0));
	for (int u = 0; u < 6; u++){
		cout << rand();
		cout << "";
	return 0; */
		

	while (true){

		Game game;
		game.run();

		/*int proceed = game.menu();
		if (proceed == 1) {
			continue;
		}
		else if (proceed == 0) {
			exit;
		} */
	}
	//game.run();
}