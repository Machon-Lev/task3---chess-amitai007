#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
    // Constructor for the Rook.
    // Parameters:
    //   player - The player (color) to which the Rook belongs.
    Rook(Player player);

    // Function to check if a move is legal for the Rook.
    // Parameters:
    //   src_row, src_col - The source position of the Rook.
    //   dest_row, dest_col - The destination position to move the Rook.
    //   board - Pointer to the chess board to validate the move.
    // Returns:
    //   true if the move is legal for the Rook, otherwise false.
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board) override;
};
