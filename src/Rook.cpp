#include "Rook.h"
#include "Board.h"

// Constructor
Rook::Rook(Player player) : Piece(player) {}

// Check if the move is legal for the Rook
bool Rook::is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    // Rooks can move either horizontally or vertically, not both.
    if (src_row != dest_row && src_col != dest_col)
        return false;

    // Check if there is a piece directly in the path of the Rook.
    return !board->there_is_a_piece_directly(src_row, src_col, dest_row, dest_col);
}
