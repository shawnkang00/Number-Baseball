// playgame.cpp
#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <time.h>
#include <algorithm>

#include "functions.h"
#include "playgame.h"


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