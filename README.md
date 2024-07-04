# Minesweeper-like Game in C
This project implements a simplified Minesweeper-like game in C, where two players take turns revealing cells on an 8x8 grid. The goal is to avoid selecting cells containing bombs while uncovering safe cells to score points. Players alternate turns until all safe cells are uncovered, and the player with the highest score wins.

## Features
- Two-player Game: Players take turns selecting cells.
- Random Bomb Placement: Bombs are randomly placed on the grid at the start of each game.
- Scoring: Players score points by uncovering safe cells (numbers less than 100).
- Winning Condition: The game ends when all safe cells have been uncovered, and the player with the higher score is declared the winner.
## Compilation and Execution
To compile the game, use the following command:
```console
gcc -o minesweeper main.c
```
To run the compiled executable:
```console
./minesweeper
```
## Game Instructions
1. Players: Enter the names of two players when prompted.
2. Gameplay:
- Players take turns entering coordinates (x, y) to uncover cells.
- Coordinates must be within the range of 0 to 7.
- The game automatically updates the grid and displays the current score after each move.
3. End of Game:
- The game ends when all safe cells are uncovered.
- The player with the higher score is declared the winner.
- The game prompts if players want to play again.
## Future Enhancements
- Implement additional features such as:
    - Difficulty levels with different bomb counts.
    - Interactive menu for game settings.