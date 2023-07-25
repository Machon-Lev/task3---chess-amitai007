#pragma once
#include "Piece.h"
#include "Board.h"

class Knight : public Piece {
public:
    // Constructor for the Knight.
    // Parameters:
    //   player - The player (color) to which the Knight belongs.
    Knight(Player player);

    // Function to check if a move is legal for the Knight.
    // Parameters:
    //   src_row, src_col - The source position of the Knight.
    //   dest_row, dest_col - The destination position to move the Knight.
    //   board - Pointer to the chess board to validate the move.
    // Returns:
    //   true if the move is legal for the Knight, otherwise false.
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_colconst, const Board* board) override;
};
