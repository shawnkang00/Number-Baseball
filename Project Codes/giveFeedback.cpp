// This function receives user's guess and gives feedback by comparing with the answer

#include <iostream>

using namespace std;

void giveFeedback(string, string, int, int &);

int main() {
    int difficulty = 4;
    int attempt = 6;

    string answer = "1234";

    while (attempt > 0) {
        string userGuess;
        cin >> userGuess;
        giveFeedback(userGuess, answer, difficulty, attempt);
    }

    return 0;
}

void giveFeedback(string guess, string answer, int difficulty, int &attempt) {
    int strike = 0, ball = 0;
    for (int i = 0; i < difficulty; i++) {
        if (guess[i] == answer[i]) {
            strike += 1;
        }
        else {
            for (int j = 0; j < difficulty; j++) {
                if (guess[i] == answer[j]) {
                    ball += 1;
                }
            }
        }
    }
    attempt -= 1;

    if (strike == 0 && ball == 0) {
        cout << "OUT !!!" << endl;
    }
    else if (strike == difficulty) {
        cout << "Congratulations!!! You won the game!!!" << endl;
    }
    else {
        cout << strike << " strike " << ball << " ball!!!" << endl;
    }

    if (attempt == 0) {
        cout << "You ran out of attempt" << endl;
    }
    else {
        cout << "You still have " << attempt << " attempts left" << endl;
    }
}
