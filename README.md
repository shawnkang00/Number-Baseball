# ENGG1340 / Course Project (2021-22 Second Semester)
## Project Outline
### Topic:
- Number Baseball
### Group No.:
- Group 9
### Group members:
1. Jang Jaeho
2. Kang Hyunwoo


## Project Abstract (Introduction)
Wordle is a very popular game these days and it has gone viral on social media. Wordle is a game of guessing a five-letter word in six attempts. Each time you make a guess, a feedback (a hint) will be given with the colors green, yellow, or gray.

Similarly, there is a game in Korea that is similar to Wordle which was very popular a few years ago, because all you need to play this game is a pen and paper. This game is called Number Baseball. Instead of guessing a word like in Wordle, Number Baseball is a game of guessing a number (usually with 3 or 4 digits). Each time a player makes a guess, a feedback will be given with concepts in baseball (Strike, Ball, and Out).


## Game Rules
1. When the game starts, the player can choose to play the Normal Mode or the Hard Mode
    - In Normal Mode: Player has to guess a 3-digit number within 6 attempts
    - In Hard Mode: Player has to guess a 4-digit number within 8 attempts

2. The answer that the player has to guess obeys the following rules
	- There are no duplicate digits in the answer, all the digits in the answer must be unique. (i.e. Numbers like 111 or 929 are not allowed)
	- All digits in the answer can be numbers between 0~9 (i.e. Numbers can start with 0, like 025)

3. The player attempts to guess the number by inputting the number with the corresponding number of digits set by the difficulty. If the player inputs an invalid number, an error message will appear and the player has to input a number again

4. The program then returns feedback based on the guess.
	- If a number in the player's guess exists in the answer and is in the correct position (correct digit), it is a “STRIKE”
	- If a number in the player's guess exists in the answer but is in the wrong position, it is a “BALL”
	- If NONE of the numbers in the player's guess exists in the answer, it is an “OUT”
	- The feedback will tell the player the TOTAL number of strikes and balls in the player’s guess, or an out. (e.g. 1 STRIKE 2 BALL, 3 STRIKE, 2 BALL, OUT, etc.)

5. The player continues to guess the number based on the feedback returned by the program after each guess until the player runs out of attempts or gets the correct answer

6. If the player guesses the correct number, they win, or if they run out of attempts, they lose


## Features
- Player will select the difficulty of the game when the game starts
- A random number (i.e. the answer) is generated for the player to guess
- Player input to guess the number with input error checking
- Every time the player input something into the program, the program will check whether the input is a valid input or not
- Compare player input with the answer and return feedback
- View game history with the guess and feedback of each attempt and also the answer of the game
- Restart the game or quit the game


## Coding Requirements
### Generation of random game sets and events:
- Every game, the computer will come up with a random number for the player to guess depending on the difficulty that the player has chosen. This is implemented with `rand()`, `srand()`, and `time(NULL)`

### Data structures for storing game status:
- To store the game status, we used variables to store the number of attempts
- Vectors and linked lists are used together with variables to store the history of each game which includes the guess and feedback of each attempt made in the game

### Dynamic memory management:
- Linked lists are used to store the history of every game
- Vectors are used to store all games played in the current session
- Each game in the vector includes the history of the game as a linked list
- A function is used to free the linked list when the program ends

### File input/output (e.g., for loading/saving game status):
- Player inputs difficulty
- Player inputs guess
- Program outputs feedback based on player’s each guess, and outputs the remaining number of attempts player has
- If player guesses the answer correctly, the game ends and the program outputs the number of guesses taken
- If player didn't guess the answer correctly within the given attempts, the game ends and the program outputs the message telling that the player ran out of attempts
- After each game ends, the program will output a question asking whether the player wants to check the history of the game. If yes, the program outputs the game history
- After viewing the game history, the program will ask whether the player wants to play another game or not

### Program codes in multiple files:
- `main.cpp`: main code for the game which uses functions from `playgame.h` and `functions.h`
- `playgame.cpp` / `playgame.h`: function used to play the game
- `functions.cpp` / `functions.h`: other functions used throughout the program
- Compilation is carried out with Makefile and `make` commands

### Testing the code
- We tested our program both in academy 11 and academy 21 servers via X2Go Client and via SSH
- The program was able to be successfully compiled on both servers

## Demonstration Video
Google Drive Link: https://drive.google.com/file/d/1ClvsoadIUI3H5QZ3zCupZb-MjXZqk517/view?usp=sharing
