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
	getline(cin, n);
	idx = stoi(n);
	cout << "Game " << idx << " - Answer: " << games[idx-1].answer << endl;
	cout << "Attempt No.  Guess      Feedback" << endl;
	printHistory(games[idx-1].history, games[idx-1].difficulty);
	return;
}

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

bool isNumber(string n)
{
	return n.find_first_not_of("0123456789") == string::npos;
}

void inputGuess(string &input, string difficulty)
{
	cout << "Guess: ";
	while(getline(cin, input)){
		if(difficulty == "Hard") {
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

string generateNumber(string difficulty)
{
	string num, numbers = "0123456789";
	num += numbers[rand()%10];
    if(difficulty == "Hard"){
		for(int i = 0; i < 3; i++){
			num += numbers[rand()%(10 - i)];
            numbers.erase(remove(numbers.begin(), numbers.end(), num[i]), numbers.end());
		}
	}else{
		for(int i = 0; i < 2; i++){
			num += numbers[rand()%(10 - i)];
            numbers.erase(remove(numbers.begin(), numbers.end(), num[i]), numbers.end());
		}
	}
	return num;
}

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

void playGame()
{
	Game game;
	History *head = NULL, *tail = NULL;
	string difficulty = setDifficulty();
	string answer = generateNumber(difficulty);
	cout << answer << endl;
	game.answer = answer;
	game.difficulty = difficulty;
	string guess, feedback;
	int tries, attempt;
	if(difficulty == "Hard"){
		attempt = 8;
	}else{
		attempt = 6;
	}
	while(attempt > 0){
		inputGuess(guess, difficulty);
		feedback = giveFeedback(guess, answer);
		tail_insert(head, tail, guess, feedback);
		attempt--;
		if(difficulty == "Hard"){
			cout << feedback << endl;
			if(feedback == "4 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 8 - attempt << " tries" << endl;
				game.history = head;
				game.result = "Win";
				games.push_back(game);
				return;
			}else{
				cout << "Your guess is wrong! You still have " << attempt << " tries left" << endl;
			}
		}
		else{
			cout << feedback << endl;
			if(feedback == "3 Strike"){
				cout << "Your guess is correct! You guessed the answer in " << 6 - attempt << " tries" << endl;
				game.history = head;
				game.result = "Win";
				games.push_back(game);
				return;
			}else{
				cout << "Your guess is wrong! You still have " << attempt << " tries left" << endl;
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
	cout << "Would you like to play again? (Y/N)" << endl;
	while(getline(cin, input)){
		if(input == "Y"){
			playGame();
			cout << "Would you like to play again? (Y/N)" << endl;
		}else if(input == "N"){
			break;
		}else{
			cout << "Invalid input. Please input again." << endl;
		}
	}

	cout << "View game history? (Y/N)" << endl;
	while(getline(cin, input)){
		if(input == "Y"){
			print_game_history();
			cout << "View game history again? (Y/N)" << endl;
		}else if(input == "N"){
			break;
		}else{
			cout << "Invalid input. Please input again." << endl;
		}
	}
	return 0;
}
