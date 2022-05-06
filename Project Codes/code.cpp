#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <time.h>

using namespace std;

struct History{
	string input;
	string feedback;
	History *next;
};

struct Game{
	string difficulty;
	string answer;
	History *history;
	string result;
};

vector<Game> games;

// This function is to build a linked list forward
// Function Parameters: Head, tail of linked list, input and feedback of node
void tail_insert(History *&head, History *&tail, string input, string feedback)
{
	History *newHistory = new History;
	newHistory->input = input;
	newHistory->feedback = feedback;
	if(head == NULL){
		head = newHistory;
		tail = newHistory;
	}else{
		tail->next = newHistory;
		tail = newHistory;
	}
}
// This function is to check if string is a number
// Input: string
// Output: True if all characters in a string is a number, false if else
bool isNumber(string n) 
{
	return n.find_first_not_of("0123456789") == string::npos;
}

// This function prints the attempt history of particular game
void printHistory(History *head, string difficulty)	
{
	History *temp;
	int count = 1;
	temp = head;
	if(difficulty == "Normal"){
		while(temp != NULL){
			cout << "Attempt " << count << ":   " << temp->input << "        " << temp->feedback << endl;
			temp = temp->next;
			count++;
		}
	}else{
		while(temp != NULL){
			cout << "Attempt " << count << ":   " << temp->input << "       " << temp->feedback << endl;
			temp = temp->next;
			count++;
		}
	}
	return;
}

// This function prints the history of games and lets you choose which game history you wish to view
void print_game_history() 
{
	int size = games.size(), idx;
	string n;
	cout << "No.        Difficulty       Result" << endl;
	for(int i = 0; i < size; i++){
		if(games[i].difficulty == "Normal"){
			cout << "Game " << i+1 << ":      " << games[i].difficulty << "          " << games[i].result << endl;	
		}else{
			cout << "Game " << i+1 << ":       " << games[i].difficulty << "           " << games[i].result << endl;	
		}
	}
	cout << "Input the number of the game you wish to view. (1~" << games.size() << ")" << endl;
	while(getline(cin, n)){
		if(isNumber(n)){
			idx = stoi(n);
			if(idx <= games.size() && 0 < idx){
				cout << "Game " << idx << " - Answer: " << games[idx-1].answer << endl;
				cout << "Attempt No.  Guess      Feedback" << endl;
				printHistory(games[idx-1].history, games[idx-1].difficulty);
				return;
			}else{
				cout << "Invalid input. Please input again." << endl;
			}
		}else{
			cout << "Invalid input. Please input again." << endl;
		}
	}
}

// This function recieves an input from the user to set the difficulty of the game
// Input: Player input on the difficulty
// Output: Returns the difficulty value based on the player input
string setDifficulty() {
	string input;
	string difficulty;
	cout << "Please choose difficulty" << endl;
	cout << "Enter 1 for Normal Mode - Guessing a 3 digit number" << endl;
	cout << "Enter 2 for Hard Mode - Guessing a 4 digit number" << endl;
	while(getline(cin, input)){
		if(input == "1"){
			difficulty = "Normal";
			break;
		}else if(input == "2"){
			difficulty = "Hard";
			break;
		}else{
			cout << "Invalid input. Please choose difficulty again." << endl;
		}
	}
	return difficulty;
}

// This function checks whether the player's guess is a valid guess
// Input: Player's guess and the difficulty of the game
// Output: Print out a statement telling whether it's a valid guess or not
void inputGuess(string &input, string difficulty)
{
	cout << "Guess: ";
	while(getline(cin, input)){
		if(difficulty == "Normal") {
			if(input.length() != 3 || !isNumber(input)){
				cout << "Invalid guess. Please input a 3 digit number.\nGuess: ";
			}
			else {
				return;
			}
		}
		else {
			if(input.length() != 4 || !isNumber(input)){
				cout << "Invalid guess. Please input a 4 digit number.\nGuess: ";
			}else{
				return;
			}
		}
	}
}

// This function generates a 3-digit or 4-digit number according to the selected difficulty
// Input: The difficulty of the game (i.e. "Normal" or "Hard")
// Output: The answer of the game (i.e. a 3-digit or a 4-digit number)
// Since numbers can start with zero and all digits must be different, we decided to return the generated answer as a string
string generateAnswer(string difficulty)
{
	string num, numbers = "0123456789";
    if(difficulty == "Normal"){
		for(int i = 0; i < 3; i++){
			num += numbers[rand()%(10 - i)];
			numbers.erase(remove(numbers.begin(), numbers.end(), num[i]), numbers.end());
		}
		
	}else{
		for(int i = 0; i < 4; i++){
			num += numbers[rand()%(10 - i)];
			numbers.erase(remove(numbers.begin(), numbers.end(), num[i]), numbers.end());
		}
	}
	return num;
}

// This function compares the player's guess with the generated answer
// And returns the feedback after comparison to tell how many strikes or balls, or it's an OUT
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
        feedback += "OUT";
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

// This function is used to play the whole game my making the function call in the main function
// Input: No input
// Output: Print statements to tell the game progress and results
void playGame()
{
	Game game;
	History *head = NULL, *tail = NULL;
	string difficulty = setDifficulty();
	string answer = generateAnswer(difficulty);
	game.answer = answer;
	game.difficulty = difficulty;
	string guess, feedback;
	int attempt;
	if(difficulty == "Normal"){
		attempt = 6;
	}else{
		attempt = 8;
	}
	while(attempt > 0){
		inputGuess(guess, difficulty);
		feedback = giveFeedback(guess, answer);
		tail_insert(head, tail, guess, feedback);
		attempt--;
		if(difficulty == "Normal"){
			cout << feedback << endl;
			if(feedback == "3 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 6 - attempt << " tries!" << endl;
				game.history = head;
				game.result = "Win";
				games.push_back(game);
				return;
			}else if(attempt > 0){
				cout << "Your guess is wrong! You still have " << attempt << " tries left." << endl;
			}else{
				break;
			}
		}else{
			cout << feedback << endl;
			if(feedback == "4 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 8 - attempt << " tries!" << endl;
				game.history = head;
				game.result = "Win";
				games.push_back(game);
				return;
			}else if(attempt > 0){
				cout << "Your guess is wrong! You still have " << attempt << " tries left." << endl;
			}else{
				break;
			}
		}
	}
	game.history = head;
	game.result = "Lose";
	games.push_back(game);
	cout << "You ran out of tries, better luck next time!" << endl;
	return;
}

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
			cout << "Invalid input. Please input again.\n(Y/N): " << endl;
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
					cout << "Invalid input. Please input again.\n(Y/N): " << endl;
				}
			}
			cout << "Would you like to play again? (Y/N): ";
		}else if(input == "N"){
			break;
		}else{
			cout << "Invalid input. Please input again.\n(Y/N): " << endl;
		}
	}	
	cout << "Thank you for playing!" << endl;
	return 0;
}
