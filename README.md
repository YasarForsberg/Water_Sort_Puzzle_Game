# Water_Sort_Puzzle_Game

This project is a Water Sort Puzzle game developed in the C programming language using the Raylib library. It was completed as part of the "Algorithms and Programming Lab 2" course during the 2nd semester of the 1st year of Computer Engineering.

--------------------------------------------------------------------------------------------------------------------------------------------------------------
#Project Description

This game is a Graphical User Interface (GUI) version of the popular mobile puzzle game where the player must sort different colored liquids into tubes according to specific rules, using a limited number of containers.

Core Objective: To ensure all test tubes contain liquid of a single color (or are empty).

How it Works:

The player selects a source tube and a target tube to pour water.

The pouring operation is only valid if the following conditions are met:

The target tube must not be completely full.

The top color of the liquid being poured must be the same as the topmost color in the target tube (or the target tube must be completely empty).

--------------------------------------------------------------------------------------------------------------------------------------------------------------
#Features

Graphical Interface (GUI): A visually enhanced, user-friendly graphical interface powered by the Raylib library.

Pre-defined Levels: Instead of generating random levels at each start, the project includes pre-designed, solvable levels (e.g., Level 1, Level 2) for the player to experience.

Reset Mechanism: Instead of a single 'Undo' feature, an 'R' button is available, allowing the player to reset all moves in the current level and return to the initial state.

Win Condition Check: An algorithm to accurately detect when the puzzle has been successfully completed.

Error Handling: Visual and logical warnings for invalid moves (e.g., trying to pour into a full tube).

--------------------------------------------------------------------------------------------------------------------------------------------------------------
#Technologies and Requirements

Language: C Programming Language

Graphics Library: Raylib (A simple and easy-to-learn game and graphics programming library)

Requirements: To compile and run the project, the Raylib library must be installed on your system and linked to the project.

Course Focus: This project serves as an application of Data Structures (Arrays/Structs), Functions, Algorithm Development, and Basic Graphics Programming (Raylib) within the C language.

--------------------------------------------------------------------------------------------------------------------------------------------------------------
Contributor

This project was completed by Muhammed Yaşar Karaçam.

Student ID: 2022556037

Course Instructor: Barış ATA, Özgür GEYLANİ
