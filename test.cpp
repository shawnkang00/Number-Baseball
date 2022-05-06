#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <time.h>

using namespace std;

int main() {
    string difficulty;
    cin >> difficulty;


    string num;
    string numbers = "0123456789";
    if(difficulty == "Normal"){
		for(int i = 0; i < 3; i++){
			num += numbers[rand()%(10 - i)];
			numbers.erase(stoi(num[i]), 1);
		}
		
	}else{
		for(int i = 0; i < 4; i++){
			num += numbers[rand()%(10 - i)];
			numbers.erase(num[i], 1);
		}
	}
	cout << num << endl;
}