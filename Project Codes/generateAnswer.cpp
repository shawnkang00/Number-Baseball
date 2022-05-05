#include <iostream>
#include <time.h>
#include <string>

using namespace std;

string generateAnswer(int);

int main() {
    srand(time(NULL));
    int difficulty = 4;
    string answer;
    answer = generateAnswer(difficulty);

    cout << answer << endl;

    return 0;
}

string generateAnswer(int difficulty) {
    int temp = 0;
    string answer;

    for (int i = 1; i <= 4; i++) {
        
    }
    
}