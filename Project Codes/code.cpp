#include <iostream>
#include <string>
#include <cstdlib> 
#include <list>
#include <time.h>

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

bool setDifficulty() {
	string input;
	bool difficulty = false;
	cout << "Please choose difficulty" << endl;
	cout << "Enter 1 for Normal Mode - Guessing a 3 digit number" << endl;
	cout << "Enter 2 for Hard Mode - Guessing a 4 digit number" << endl;
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
		if(difficulty) {
			if(input.length() != 4 || !isNumber(input)){
				cout << "Invalid guess. Please input a 4 digit number.\nGuess: ";
			}else{
				return;
			}
		}
		else {
			if(input.length() != 3 || !isNumber(input)){
				cout << "Invalid guess. Please input a 3 digit number.\nGuess: ";
			}
			else {
				return;
			}
		}
	}
}

/* string generateAnswer(int difficulty) {
    int temp = 0;
    string answer;

    for (int i = 1; i <= 4; i++) {
        
    }
    
} */

string giveFeedback(string guess, string answer) {
    int strike = 0, ball = 0;
	string feedback;

    for (int i = 0; i < answer.length(); i++) {
        if (guess[i] == answer[i]) {
            strike += 1;
        }
        else {
            for (int j = 0; j < answer.length(); j++) {
                if (guess[i] == answer[j]) {
                    ball += 1;
                }
            }
        }
    }

    if (strike == 0 && ball == 0) {
        feedback += "It's an OUT";
    }
    else if (ball == 0) {
        feedback += to_string(strike);
		feedback += " Strike";
    }
	else if (strike == 0) {
        feedback += to_string(ball);
		feedback += " Ball";
    }
    else {
        feedback += to_string(strike);
		feedback += " Strike ";
		feedback += to_string(ball);
		feedback += " Ball";
    }

	return feedback;
}

void playGame()
{
	bool difficulty = setDifficulty();
	// string answer = generateAnswer(difficulty);
	string answer = "1234";

	string guess, feedback;
	int tries, attempt;
	if(difficulty){
		attempt = 8;
	}else{
		attempt = 6;
	}
	while(attempt != 0){
		inputGuess(guess, difficulty);
		feedback = giveFeedback(guess, answer);
		if(difficulty){
			cout << feedback << endl;
			if(feedback == "4 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 8 - attempt << " tries" << endl;
			}else{
				cout << "Your guess is wrong! You still have " << attempt << " tries left" << endl;
			}
		}
		else{
			cout << feedback << endl;
			if(feedback == "3 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 6 - attempt << " tries" << endl;
			}else{
				cout << "Your guess is wrong! You still have " << attempt << " tries left" << endl;
			}
		}
		attempt--;
	}
	cout << "You ran out of tries, better luck next time!" << endl;
	return;
}

int main()
{		
	srand(time(NULL));
	playGame();
	string input;
	cout << "Would you like to play again? (Y/N)" << endl;
	while(getline(cin, input)){
		if(input == "Y"){
			playGame();
		}else if(input == "N"){
			cout << "Thank you for playing!" << endl;
			break;
		}else{
			cout << "Invalid input. Please input again." << endl;
		}
	}

	return 0;
}
