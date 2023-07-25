#pragma once
#include "Piece.h"
#include "Board.h"

class King : public Piece {
public:
    // Constructor for the King.
    // Parameters:
    //   player - The player (color) to which the King belongs.
    King(Player player);

    // Function to check if a move is legal for the King.
    // Parameters:
    //   src_row, src_col - The source position of the King.
    //   dest_row, dest_col - The destination position to move the King.
    //   board - Pointer to the chess board to validate the move.
    // Returns:
    //   true if the move is legal for the King, otherwise false.
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board) override;
};
