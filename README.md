# COMP2113-Group-5-
README.MD

Identification

Team Members: Bang Jun Young (UID: 3035662338) and Chiu Tsz Chun (UID: 3035712195)


Description and Game Rules

Our idea is to implement Mastermind as a text-based game. 4 coloured pins are generated in consecutive positions randomly, with repeats of colours allowed. The goal of the player is to guess all 4 pin colours and positions correctly within 12 tries. In each turn, the players can place their 4 guesses, all guesses are only within the colours ('R', 'B', 'G', 'Y', 'P', 'O') case-sensitive. The program matches each guessed pin with the solution.

If a guessed pin matches the colour and the position of the corresponding pin in the solution, a red flag will be returned (stated with the letter 'R' on the right side of the grid). If a guessed pin only matches a colour, but in an incorrect position, a white pin is returned (stated with the letter 'W' on the right side of the grid). If a guessed pin doesn't match the colour of pins, it will return '-' on the right side of the grid.

The player wins if it matches all 4 pins exactly (colour and position) in 12 tries or less, and loses otherwise.


List of Assumptions

- All user inputs are in all caps
- All user inputs are written exactly in format explicitly required in instructions
- All guesses are only within the following list: {'R', 'B', 'G', 'Y', 'O', 'P'} (case-sensitive)
- Save-states are not modified and regenerated afterwards


List of features:

For every new game, the generate function will randomly generate four coloured pins for the codebreaker to guess. (requirement 1)
Storage of user guesses (inputs) and game response (output) is done through linked lists, and manipulation of arrays in match() function (requirement 2)
Matching, reading, and saving functions are done dynamically through pointers (requirement 3)
Saving/loading functions are done through printing linked lists into external file, then regenerating save state is done through reconstructing linked lists from external file (file I/O - requirement 4)
Program is written in 5 different files, and recombined through header files and a final makefile (requirement 5)
All programs are named sensibly and in proper indentation. (requirement 6)
GUI elements, including instructions, game grid and input key, are implemented to help supplement user understanding and smooth out gameflow (requirement 7)
Winning condition and different outcomes: 1. Win (give solution) 2. Lose (give solution)


Coding elements:

For every game, the generate() function creates a random game state
print_grid() function to display the user's guesses, and flags to indicate the rightness of the guess.
while loop to accept the user's guesses and check if win condition is fulfilled
tail_insert() function to add newest guesses and flags to linked lists for storage
match() function to compare the user's guess and the answer to determine the number of redflag, whiteflag or dash to be returned. The user's guesses are correct if it result in 4 redflags, and the function will indicate that the user successfully guessed the correct pins.


Compilation and execution:

Navigate on bash to the Project folder
Compile with command: $ make game_main
Run game with command: ./game_main
Start game with "PLAY", and see instructions with "INSTRUCTIONS"
