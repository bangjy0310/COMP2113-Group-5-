# COMP2113-Group-5-
Group Project

Team Members: Bang Jun Young (UID: 3035662338) and Chiu Tsz Chun (UID: 3035712195)

Our idea is to implement Mastermind as a text-based game. 

General Description of Mastermind
4 coloured pins are generated in consecutive positions randomly, with repeats of colours allowed. The goal of the player is to guess all 4 pin colours and positions correctly within 12 tries. In each turn, the players can place their 4 guesses, all guesses are only within the colours ('R', 'B', 'G', 'Y', 'P', 'O') case-sensitive. The program matches each guessed pin with the solution. 

If a guessed pin matches the colour and the position of the corresponding pin in the solution, a red flag will be returned (stated with the letter 'R' on the right side of the grid). 
If a guessed pin only matches a colour, but in an incorrect position, a white pin is returned (stated with the letter 'W' on the right side of the grid).
If a guessed pin doesn't match the colour of pins, it will return '-' on the right side of the grid.

The player wins if it matches all 4 pins exactly (colour and position) in 12 tries or less, and loses otherwise.

List of assumptions 
- All user inputs are in all caps
- All user inputs are written exactly in format explicitly required in instructions
- All guesses are only within the following list: {'R', 'B', 'G', 'Y', 'O', 'P'} (case-sensitive) 
- Save-states are not modified and regenerated afterwards

List of features:
- Random generation of solution pins
- Input system for player attempts (player inputs 4 colours)
- Systematic checking system to match player attempt with generated solution
- Counter for attempts
- Output system: 1. Win (give solution), 2. Try Again (give attempts left), 3. Loss (give solution) 

List of features:
- For every new game, the generate function will randomly generate four coloured pins for the codebreaker to guess. (requirement 1) 
- Storage of user guesses (inputs) and game response (output) is done through linked lists (requirement 2)
- Matching, reading, and saving functions are done dynamically through pointers (requirement 3)
- Saving/loading functions are done through printing linked lists into external file, then regenerating save state is done through reconstructing linked lists from external file (file i/o - requirement 4)
- Data structures for storing game status - attempts, flags, and solution will be stored through data structures (arrays)
- Program is written in 5 different files, and recombined through header files and a final makefile (requirement 5)  
- All programs are named sensibly and in proper indentation. (requirement 6) 
- GUI elements, including instructions, game grid and input key, are implemented to help supplement user understanding and smooth out gameflow (requirement 7)
- Output system: 1. Win (give solution) 2. Lose (give solution) 

Coding elements:
1. For every game, the generate function 
2. print_grid() function to display the user's guesses, and the redflag, whiteflag, or dashes to indicate the rightness of the guess. 
3. while loop to accept the user's guesses 
4. tail_insert function to add it to the linked list for storage 
5. match function to compare the user's guess and the answer to determine the number of redflag, whiteflag or dash to be returned. The user's guesses are correct if it result in    4 redflags, and the function will indicate that the user successfully guessed the correct pins with a boolean variable. 

Compilation and execution:
1. Navigate on bash to the Project folder
2. Compile with command:
   $ make game_main
3. Run game with command:
   ./game_main
4. Start game with "PLAY", and see instructions with "INSTRUCTIONS"

Sample Input / Sample Output files 

