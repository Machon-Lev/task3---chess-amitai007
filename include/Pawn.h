#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece {
public:
    // Constructor for the Pawn.
    // Parameters:
    //   player - The player (color) to which the Pawn belongs.
    Pawn(Player player);

    // Function to check if a move is legal for the Pawn.
    // Parameters:
    //   src_row, src_col - The source position of the Pawn.
    //   dest_row, dest_col - The destination position to move the Pawn.
    //   board - Pointer to the chess board to validate the move.
    // Returns:
    //   true if the move is legal for the Pawn, otherwise false.
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board) override;
};
