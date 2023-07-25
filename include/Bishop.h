#pragma once
#include "Piece.h"

class Bishop : public Piece {
private:
    // Private helper function to check if a move is legal for the Bishop.
    // Parameters:
    //   src_row, src_col - The source position of the Bishop.
    //   dest_row, dest_col - The destination position to move the Bishop.
    //   board - Pointer to the chess board to validate the move.
    // Returns:
    //   true if the move is legal for the Bishop, otherwise false.
    bool bishop_is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board);

public:
    // Constructor for the Bishop.
    // Parameters:
    //   player - The player (color) to which the Bishop belongs.
    Bishop(Player player);

    // Public function to check if a move is legal for the Bishop.
    // Parameters:
    //   src_row, src_col - The source position of the Bishop.
    //   dest_row, dest_col - The destination position to move the Bishop.
    //   board - Pointer to the chess board to validate the move.
    // Returns:
    //   true if the move is legal for the Bishop, otherwise false.
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board);
};
