------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 Map.cpp Button.cpp Pirate.cpp Trap.cpp Person.cpp Player.cpp FullGame.cpp 
./a.out
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
All .h files must be in the same directory as the cpp 
files in order to compile.
Only enter numbers (not characters) when prompted
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Matty Keane and Sophia Soka
Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
Date: Dec 1, 2022
------------------------
ABOUT THIS PROJECT
------------------------
This project is a game where a user must collect three keys in order to win.
The user must navagate through the map while trying to avoid or fight pirates, 
while finding traps that contain riddles which must must be solved inorder to 
collect the keys. The user can purchase weapons, hints and lives from a 
merchant at the beggining of the game to help them naviagte through the map. 
Each Pirate and Trap will be placed randomily on the map for the user to discover. 
Pirates are also randomily assigned strength levels and the proability of winning
against a Pirate changes depending on if the user decides to use their weapon. If 
user collects three keys they will win the game and be added to the leaderboard.txt 
file, which ranks players based on the number of times they move. 
