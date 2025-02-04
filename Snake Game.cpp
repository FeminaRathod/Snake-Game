// Snake Game 1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib> // For rand()
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
#include <vector>

using namespace std;

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

const int width = 20;
const int height = 20;

bool gameOver;
int x, y, foodX, foodY, score;
vector<pair<int, int>> snake; // Stores snake body
eDirection direction;

void Setup()
{
    gameOver = false;
    direction = STOP;

    x = width / 2;
    y = height / 2;

    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;

    snake.clear();
    snake.push_back({ x, y });
}

void Draw()
{
    system("cls"); // Clear screen

    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }

            if (i == y && j == x)
            {
                cout << "O"; // Snake head
            }
            else if (i == foodY && j == foodX)
            {
                cout << "F"; // Food
            }
            else
            {
                bool print = false;

                for (auto s : snake)
                {
                    if (s.first == j && s.second == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }

                if (!print)
                {
                    cout << " ";
                }
            }

            if (j == width - 1)
            {
                cout << "#";
            }
        }

        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }

    cout << "\nScore: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a': direction = LEFT;
            break;

        case 'd': direction = RIGHT;
            break;

        case 'w': direction = UP;
            break;

        case 's': direction = DOWN;
            break;

        case 'x': gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = snake[0].first;
    int prevY = snake[0].second;
    int prev2X, prev2Y;

    snake[0].first = x;
    snake[0].second = y;

    for (int i = 1; i < snake.size(); i++)
    {
        prev2X = snake[i].first;
        prev2Y = snake[i].second;

        snake[i].first = prevX;
        snake[i].second = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (direction)
    {
    case LEFT: x--;
        break;

    case RIGHT: x++;
        break;

    case UP: y--;
        break;

    case DOWN: y++;
        break;

    default:
        break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
    {
        gameOver = true;
    }

    for (int i = 1; i < snake.size(); i++) // Collision with itself
    {
        if (snake[i].first == x && snake[i].second == y)
        {
            gameOver = true;
        }
    }

    if (x == foodX && y == foodY)
    {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        snake.push_back({ -1, -1 });
    }
}

int main()
{
    std::cout << "Hello World!\n";

    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }

    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
