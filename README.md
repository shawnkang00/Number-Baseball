# ENGG1340 / Course Project (2021-22 Second Semester)
## Project Outline
### Topic:
- Number Baseball
### Group No.:
- Group 9
### Group members:
1. Jang Jaeho (UID: 3035855492)
2. Kang Hyunwoo (UID: 3035552624)


## Proposal Introduction
Wordle is a very popular game these days and it has gone viral on social media. Wordle is a game guessing a five-letter word in six attempts. Each time you make a guess, a feedback (a hint) will be given with colors green, yellow, or gray.

Similarly, there is a game in Korea that is similar to Wordle which was very popular among high school students a few years ago, beacuse all you need to play this game is a pen and a paper. This game is called Number Baseball, instead of guessing a word like in Wordle, Number Baseball is a game guessing a number (usually with 3 or 4 digits). Each time a player makes a guess, a feedback will be given with concepts in baseball (Strike, Ball, and Out).


## Game Rules
1. When the game starts, the player can choose to play the Normal Mode or the Hard Mode
    - In Normal Mode: Player have to guess a 3-digit number within 6 attempts
    - In Hard Mode: Player have to guess a 4-digit number within 8 attempts
    - For the generated number, ALL the digits are different, overlapping digits are not allowed (i.e. Numbers like 111 or 929 is not allowed).
    - For the generated number, ALL the digits are consists of random integer from 0 ~ 9 (i.e. Number can start with 0).

2. The player attempts to guess the number by inputting the number with the corresponding number of digits set by the difficulty.

3. The program then returns feedback based on the guess. 
    - If a number in the player's guess exists in the answer and is in the correct place (correct digit), it is a “STRIKE”.
    - If a number in the player's guess exists in the answer but is in the wrong place, it is a “BALL”.
    - If NONE of the numbers in the player's guess exists in the answer, it is an “OUT”.
	- The feedback will tell the play the TOTAL number of strikes and balls in the player’s guess, or an out. (e.g. 1 STRIKE 2 BALL, 3 STRIKE, 2 BALL, OUT, etc.)

4. The player continues to guess the number based on the feedback returned by the program after each guess until the player runs out of attempts. 

5. The game ends when the player correctly guesses the number or runs out of attempts.

6. After the game ends, the player can choose to play the game again or quit the game


## Features
- Player will select the difficulty of the game when the game starts
- Generate random number for user to guess (i.e. generate an answer)
- Player input to guess the number with input error checking
- Compare user input with the answer and return feedback
- End the program if the player input (guess) matches the answer or the player runs out of attempts


## Coding Requirements
### Generation of random game sets and events:
- Every game, the computer will come up with a random number for the user to guess depending on the difficulty that the player has chosen. This can be done by using the functions `rand()`, `srand()`, and `time()`.

### Data structures for storing game status:
- To store the game status, we can store the number of attempts in a variable
- Also, we will store user guesses and the returned feedbacks, to show the user all the guess records and feedbacks after the game ends

### Dynamic memory management:
- Depending on the difficulty chosen by the user, the length (number of digits) of the number generated by the program will vary.

### File input/output (e.g., for loading/saving game status):
- Player inputs guess
- Program outputs feedback based on player’s each guess
- If player guesses the answer correctly, the game ends and the program outputs the number of guesses taken
- If player didn't guess the answer correctly within the given attempts, the game ends and the program outputs the message telling that the player ran out of attempts
- After each game ends, program will output a question asking whether player want to restart the game or exit the game

### Program codes in multiple files:
- Main file, file for functions used in the game, file for the setting of the game


## Sample Test Cases
- `input1.txt`: Sample input file for Normal Difficulty
- `input2.txt`: Sample input file for Hard Difficulty