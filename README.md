# COMP2113-Group-5-
Group Project

Team Members: Bang Jun Young (UID: 3035662338) and Chiu Tsz Chun (UID: 3035712195)

Our idea is to implement Mastermind as a text-based game. 

Description of Mastermind: 4 coloured pins are generated in consecutive positions randomly, with repeats of colours allowed. The goal of the player is to guess all 4 pin colours and positions correctly within 10 tries. In each turn, the players can place their 4 guesses by stating the colours in order. The program matches each guessed pin with the solution. 

If a guessed pin matches the colour and the position of the corresponding pin in the solution, a red flag will be returned.
If a guessed pin only matches a colour, but in an incorrect position, a white pin is returned.
If a guessed pin doesn't match the colour of pins, it will return nothing.

The player wins if it matches all 4 pins exactly (colour and position) in 10 tries or less, and loses otherwise.

List of features:
- Random generation of solution pins
- Input system for player attempts (player inputs 4 colours)
- Systematic checking system to match player attempt with generated solution
- Counter for attempts
- Output system: 1. Win (give solution), 2. Try Again (give attempts left), 3. Loss (give solution)

Coding elements:
1. Generation of random game sets or events - The final solution is generated randomly every time
2. Data structures for storing game status - attempts, flags, and solution will be stored through data structures (arrays)
3. Dynamic memory management - Pointers will be used to reference and manipulate memory
4. File input/output - file input will be given for attempts, file output will be given for information to player
5. Program codes in multiple files - generation of solution, checking of attempts, and flagging system will be coded in different files from main game file
