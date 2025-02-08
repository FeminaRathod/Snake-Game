Snake Game

This is a simple implementation of Snake Game.This code uses a combination of standard C++ data structures (queue, set, and pair) and custom classes (Food, Snake, and Game Board) to implement the Snake game. The Snake class manages the snake's segments, direction, and movement, while the Food class handles the spawning of food on the board. The Game Board class integrates these components and manages the overall game logic, input handling, and rendering.

	Overview
The game includes:
    ->A Food class that handles the spawning of food on the game board.
    ->A Snake class that manages the movement, growth, and self-collision of the snake.
    ->A Game Board class that oversees the game logic, input handling, and rendering of the game.

	How to Play :-
Use the following controls to play the game:

W: Move Up
S: Move Down
A: Move Left
D: Move Right
X: Exit Game

The objective is to eat the food (marked as 'F') and avoid collisions with the wall or the snake's own body.

Data Structures Used
1)Queue (std::queue):
	Used in the Snake class to store the segments of the snake's body.
	Allows easy insertion of new segments at the head and removal of old segments at the tail, which is efficient for the snake's movement.

2)Set (std::set):
	Used in the Snake class as a body Set to keep track of the snake's body segments for quick lookup.
	Helps in detecting self-collision efficiently by checking if the head position already exists in the set.

3)Pair (std::pair):
	Used to represent the coordinates of the snake's segments, the food's position, and the snake's head.
	Provides a convenient way to manage and manipulate (x, y) coordinates.


Class Structure

	Food Class:

Attributes:
•	int x, y: Coordinates of the food on the game board.

Methods:
•	Food(): Constructor that initializes the food by calling Respawn().
•	void Respawn(): Randomly generates new coordinates for the food within the game board's boundaries.

	Snake Class:

Attributes:
•	queue<pair<int, int>> body: Stores the segments of the snake's body.
•	set<pair<int, int>> bodySet: Keeps track of the snake's body segments for collision detection.
•	eDirection direction: Enum representing the current direction of the snake's movement.
•	pair<int, int> head: Coordinates of the snake's head.

Methods:
•	Snake(): Constructor that initializes the snake with three segments, sets the initial direction to RIGHT, and places the head at the center of the board.
•	void Move(bool grow): Moves the snake in the current direction. If the snake eats food (grow is true), it grows by not removing the tail segment.
•	bool CollidedWithSelf(): Checks if the snake's head has collided with any other part of its body.

	GameBoard Class:

Attributes:
•	Snake snake: An instance of the Snake class representing the snake in the game.
•	Food food: An instance of the Food class representing the food in the game.
•	bool gameOver: A flag indicating whether the game is over.
•	int score: The player's score.

Methods:

•	GameBoard(): Constructor that initializes the game board and calls Reset().
•	void Reset(): Resets the game state by reinitializing the snake, respawning the food, and resetting the score.
•	void Draw(): Draws the game board, the snake, and the food on the console.
•	void Input(): Handles player input for controlling the snake's movement.
•	void Logic(): Contains the game logic, including movement, collision detection, and score updates.
•	void GameOverScreen(): Displays the game over screen and handles input for restarting or exiting the game.


