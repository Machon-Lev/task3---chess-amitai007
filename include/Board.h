#pragma once

#include <vector>
#include <string>
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Player.h"

class Board {
    Player whos_turn = WHITE_PLAYER; // Keeps track of the current player's turn.
    Piece* pieces[8][8]; // 2D array to store the pieces on the board.
    int white_king_place[2]; // Stores the position of the white king.
    int black_king_place[2]; // Stores the position of the black king.

public:
    Board(std::string board); // Constructor to initialize the board from a string representation.
    Board(const Board& other); // Copy constructor.
    Board(Board&& other) noexcept; // Move constructor.
    ~Board(); // Destructor.
    Piece* getPiece(const int row, const int col) const; // Get the piece at a given position.
    int code_response(const std::string res); // Convert string response to a numerical code.
    bool there_is_a_piece_directly(const int src_row, const int src_col, const int dest_row, const int dest_col) const; // Check if there is a piece in a straight line between source and destination.
    bool there_is_a_piece_diagonally(const int src_row, const int src_col, const int dest_row, const int dest_col) const; // Check if there is a piece diagonally between source and destination.

private:
    static int convert_str_to_loc(const char str_loc); // Convert a character representation of a location to a numerical index.
    bool is_check(); // Check if the current player is in check.
    void move_piece(const int src_row, const int src_col, const int dest_row, const int dest_col); // Move a piece from source to destination.
    int get_iterator_num(const int loc_row, const int loc_col) const; // Get the numerical index of a location on the board.
};
