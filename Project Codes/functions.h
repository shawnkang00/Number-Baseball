// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

class History
{
	public:
		string input;
		string feedback;
		History *next;
};

class Game
{
	public:
		string difficulty;
		string answer;
		History *history;
		string result;
};

extern vector<Game> games;

void tail_insert(History *&head, History *&tail, string input, string feedback);

bool isNumber(string n);

bool isUnique(string input, int difficulty);

void printHistory(History *head, string difficulty);

void print_game_history();

string setDifficulty();

void inputGuess(string &input, string difficulty);

string generateAnswer(string difficulty);

string giveFeedback(string guess, string answer);

void playGame();

#endif
