// main.cpp
#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <algorithm>
#include "playgame.h"
#include "functions.h"

using namespace std;

int main()
{		
	srand(time(NULL));
	playGame();
	string input;
	cout << "View game history? (Y/N): ";
	while(getline(cin, input)){
		if(input == "Y"){
			print_game_history();
			cout << "View game history again? (Y/N): ";
		}else if(input == "N"){
			break;
		}else{
			cout << "Invalid input. Please input again.\n(Y/N): ";
		}
	}
	cout << "Would you like to play again? (Y/N): ";
	while(getline(cin, input)){
		if(input == "Y"){
			playGame();
			cout << "View game history? (Y/N): ";
			while(getline(cin, input)){
				if(input == "Y"){
					print_game_history();
					cout << "View game history again? (Y/N): ";
				}else if(input == "N"){
					break;
				}else{
					cout << "Invalid input. Please input again.\n(Y/N): ";
				}
			}
			cout << "Would you like to play again? (Y/N): ";
		}else if(input == "N"){
			break;
		}else{
			cout << "Invalid input. Please input again.\n(Y/N): ";
		}
	}	
	cout << "Thank you for playing!" << endl;

	delete_list();

	return 0;
}
