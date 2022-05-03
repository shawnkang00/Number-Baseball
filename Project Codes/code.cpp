#include <iostream>
#include <string>
#include <cstdlib> 
#include <list>

using namespace std;

// Game History access 할때 사용 할 수도 있는 것들
// struct History{
// 	string input;
// 	string feedback;
// };

// struct Game{
// 	bool difficulty;
// 	vector<History> History;
// 	bool win;
// };

// vector<Game> games;

bool setDifficulty()
{
	string input;
	bool difficulty = false;
	cout << "Please choose difficulty" << endl;
	cout << "1. Normal\n2. Hard" << endl;
	while(getline(cin, input)){
		if(input == "1"){
			difficulty = false;
			break;
		}else if(input == "2"){
			difficulty = true;
			break;
		}else{
			cout << "Invalid input. Please choose difficulty again." << endl;
			getline(cin, input);
		}
	}
	return difficulty;
}

bool isNumber(string n)
{
	return n.find_first_not_of("0123456789") == string::npos;
}

void inputGuess(string &input, bool difficulty)
{
	cout << "Guess: ";
	while(getline(cin, input)){
		if(difficulty){
			if(input.length() != 4 || !isNumber(input)){
				cout << "Invalid guess. Please input a 4 digit number.\nGuess: ";
			}else{
				return;
			}
		}else{
			if(input.length() != 3 || !isNumber(input)){
				cout << "Invalid guess. Please input a 3 digit number.\nGuess: ";
			}else{
				return;
			}
		}
	}
}

void playGame()
{
	bool difficulty = setDifficulty();
	//char answer = generateNumber(difficulty);
	string guess, feedback;
	int tries, maxTries;
	if(difficulty){
		maxTries = 8;
	}else{
		maxTries = 6;
	}
	while(maxTries != 0){
		inputGuess(guess, difficulty);
		//feedback = generateFeedback(input, answer)
		if(difficulty){
			if(feedback == "4 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 8 - maxTries << " tries" << endl;
			}else{
				continue;
			}
		}else{
			if(feedback == "3 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 6 - maxTries << " tries" << endl;
			}else{
				continue;
			}
		}
		maxTries--;
	}
	cout << "You ran out of tries, better luck next time!" << endl;
	return;
}

int main()
{		
	srand(time(NULL));
	playGame();
	string input;
	cout << "Would you like to play again? (y/n)" << endl;
	while(getline(cin, input)){
		if(input == "y"){
			playGame();
		}else if(input == "n"){
			cout << "Thank you for playing!" << endl;
			break;
		}else{
			cout << "Invalid input. Please input again." << endl;
		}
	}

	return 0;
}
