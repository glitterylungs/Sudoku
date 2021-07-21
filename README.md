# Sudoku
Sudoku game in console. Created using the basics of the C++ language.


# Project description
The "Sudoku" project is a simple program in English for solving sudoku boards. It is based on entering numbers selected by the user into the board and checking the correctness of these numbers. In the project, it is possible to see the solution of a given board. It is also possible to select the level of difficulty of the board, which makes the program suitable for a large number of users at various levels of advancement. The program is characterized by readability, transparency and a high level of checking the values entered by the user.


# Description of the project functionality:
• displaying nice and colorful inscriptions and boards,
• smooth movement between 'pages' with the use of keyboard keys,
• main menu containing the following fields: instruction, about the author, play, exit,
• intermediate menu, allowing you to choose the difficulty of the board
(3 difficulty levels - easy, medium, difficult),
• drawing and loading boards from .txt files (20 boards of each difficulty level),
• solving the board using backtracking,
• checking the correctness of the value entered by the user,
• change of board color after entering an incorrect value,
• counter of the number of errors and progress,
• the ability to see the correct solution of the board and return to the main menu.


# How it works
After starting the program, we see the title of the game "sudoku".

![image](https://user-images.githubusercontent.com/72377506/126564500-95568b45-1915-4d1f-a467-be24dc6783f4.png)


After pressing the Enter key, we go to the main menu, where we have four options. After selecting the "How to play" option, we see an instruction describing what sudoku is about and how the game should look like in our program. After clicking on the key with the number 3 on the keyboard, you can see information about the author of the program. After selecting a four, the program is exited. If we want to go to the difficulty menu, we should choose the "NEW GAME" option. There are 3 levels to choose from in the difficulty menu - easy, medium and hard.

![image](https://user-images.githubusercontent.com/72377506/126564534-d250d341-f4cd-4be5-b073-da481ec6bcdd.png)
![image](https://user-images.githubusercontent.com/72377506/126564544-f2e9351b-f6e0-472a-9d6e-da80dc7398f7.png)


After selecting the level of difficulty we are interested in, the sudoku board appears. Above the board you will find a counter for the number of errors that we have made and a percentage counter for progress we have made. On the right side of the board there is a mini instruction which numbers, apart from 1-9, can be entered in place of selecting a row, column or specific value to be entered on the board.

![image](https://user-images.githubusercontent.com/72377506/126564577-76bb631e-1968-43d6-94c2-1eaa8b288877.png)


After entering the number 10 in any field, we return to the main menu, and after entering the number 11, the program displays the solved sudoku board.

![image](https://user-images.githubusercontent.com/72377506/126564593-e878d0f4-6a8a-4eee-b12c-f306b1d32fc8.png)


If we do not enter a number from 1-11 in the selection field of the row, column and value, we will receive a message that we must enter a number from 1-11. If you choose a place on the board that is already full, you will also get an appropriate message. If the value we decide to enter in the board is incorrect, the board will turn red for a moment and nothing will be entered in the given field.


After the user has solved the sudoku correctly, his eyes will see the word "great job" blinking, and then we will be redirected to the difficulty menu.

![image](https://user-images.githubusercontent.com/72377506/126564627-2e94a438-fb9f-4571-ba3f-dc3ce14e0fe5.png)

Enjoy!
