# COMP-2113---Course-Project
COMP 2113 - Course Project

# ENGG1340 / COMP2213 - Course Project (2021-22 Second Semester)
### Group 9
### Group members:
1. Jang Jaeho (UID: 3035855492)
2. Kang Hyunwoo (UID: 3035552624)

1. A 3-digit number is generated by the program, based on the difficulty of the game, which is set by the player.
2. The player attempts to guess the number by inputting the number with the corresponding number of digits set by the difficulty.
3. The program then returns feedback based on the guess. 
    - If a number in the player's guess exists in the answer and is in the correct place, it is a “STRIKE”.
    - If a number in the player's guess exists in the answer but is in the wrong place, it is a “BALL”.
    - If none of the numbers in the player's guess exists in the answer, it is an “OUT”.
	The feedback consists of the number of strikes and balls in the player’s guess, or out.
	(e.g. 1 Strike 2 Ball, 3 Strike, 2 Ball, OUT, etc.)
4. The player continues to guess the number based on the feedback returned by the programme until the player runs out of attempts.
5. The game ends when the player correctly guesses the number or runs out of attempts.

## Features
- Users will select the difficulty of the game when the game starts (The number of digits for the answer and also the number of 
- Generate random number for user to guess (i.e. generate an answer)
- Player input to guess the number with input error checking
- Compare user input with the answer and return feedback
- End the program if the user input (guess) matches the answer

## Code Requirements
1. Generation of random game sets and events
    - Every game, the computer will come up with a random number for the user to guess depending on the difficulty that the player has chosen. This can be done by using the rand() function with the rands(), time() functions.

2. Data structures for storing game status
    - Store number of tries in a variable

3. Dynamic memory management
    - Depending on the difficulty chosen by the user, the length (number of digits) of the number created by the program will vary.

4. File input/output (e.g., for loading/saving game status)
    - Player inputs guess
    - Program outputs feedback based on player’s guess
    - When game ends, program outputs the number of guesses taken

5. Program codes in multiple files
    - Main file, file for functions used in the game, file for the setting of the game

