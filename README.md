
# Sudoku Game in C

A simple console-based Sudoku game developed using the C programming language. The game allows users to fill empty cells in a 9×9 Sudoku grid while checking whether their moves follow Sudoku rules.

## Features

- Displays a 9×9 Sudoku puzzle in the terminal.
- Allows users to enter numbers into empty cells.
- Checks whether a move is valid before placing a number.
- Prevents users from modifying the original given numbers.
- Validates moves according to Sudoku rules:
  - No repeated numbers in the same row.
  - No repeated numbers in the same column.
  - No repeated numbers in the same 3×3 box.
- Allows users to exit the game at any time.

## Technologies Used

- **Language:** C
- **Concepts:** 2D Arrays, Functions, Loops, Conditional Statements, Input/Output

## How to Run

### 1. Clone the Repository

```bash
git clone YOUR_REPOSITORY_LINK
```

### 2. Open the Project Folder

```bash
cd YOUR_REPOSITORY_NAME
```

### 3. Compile the Program

If you have GCC installed:

```bash
gcc sudoku.c -o sudoku
```

### 4. Run the Game

**Windows (PowerShell):**
```powershell
.\sudoku.exe
```

**Linux/macOS:**
```bash
./sudoku
```

## How to Play

1. The Sudoku puzzle will appear in the terminal.
2. Empty cells are represented by `0`.
3. Enter three values:
   - Row number
   - Column number
   - Number you want to place
4. All positions are entered using numbers from 1 to 9.
5. The game checks whether your move is valid.
6. Enter `0 0 0` to exit the game.

### Example

```text
Enter row, column and number: 1 3 4
```

This attempts to place `4` in row 1, column 3.

## Sudoku Rules

- Each row must contain numbers from 1 to 9 without repetition.
- Each column must contain numbers from 1 to 9 without repetition.
- Each 3×3 box must contain numbers from 1 to 9 without repetition.

## Learning Objectives

This project helped me practice:

- Working with two-dimensional arrays.
- Breaking a program into functions.
- Using loops and conditional statements.
- Implementing basic input validation.
- Applying logical problem-solving to a real-world puzzle.

## Author

Developed as a beginner-level C programming project.
