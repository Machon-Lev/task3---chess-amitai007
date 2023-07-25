#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int _SIZE = 21;

class Chess {
    unsigned char m_board[_SIZE][_SIZE] = { 0 }; // 2D array to represent the chess board.
    bool m_turn = true; // Tracks the current player's turn (true for Player 1, false for Player 2).
    string m_boardString; // String representation of the chess board.
    string m_input; // Holds user input.
    string m_msg = "\n"; // Additional message to display during the game.
    string m_errorMsg = "\n"; // Error message to display during the game.
    int m_codeResponse; // Numeric code representing the result of a move or action.

    // Helper functions for internal operations:
    void clear() const; // Clear the screen.
    void setFrames(); // Set the frames for the chess board display.
    void setPieces(); // Initialize the chess board with starting pieces.
    void show() const; // Show the chess board along with additional messages.
    void displayBoard() const; // Display the current state of the chess board.
    void showAskInput() const; // Display a prompt asking for user input.
    bool isSame() const; // Check if the source and destination positions are the same.
    bool isValid() const; // Check if the user input is valid.
    bool isExit() const; // Check if the user wants to exit the game.
    void execute(); // Execute the user's input and make the move.
    void doTurn(); // Perform a single turn of the game.

public:
    // Constructors and assignment operators:
    Chess(const string& start = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"); // Constructor to set up the initial state of the chess board.
    Chess(const Chess&) = delete; // Copy constructor (deleted).
    Chess& operator=(const Chess&) = delete; // Assignment operator (deleted).

    // Function to get user input and return it as a string.
    string getInput();

    // Function to set the numeric code response.
    void setCodeResponse(int codeResponse);
};
