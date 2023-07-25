#include "Knight.h"

// Constructor
Knight::Knight(Player player) : Piece(player) {}

// Check if the move is legal for the Knight
bool Knight::is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    if ((abs(src_row - dest_row) == 2 && abs(src_col - dest_col) == 1)
        || (abs(src_row - dest_row) == 1 && abs(src_col - dest_col) == 2))
        return true;
    return false;
}
