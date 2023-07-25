#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(Player player) : Piece(player) {} // Constructor for the Bishop.

bool Bishop::is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    // Check if the move is legal for the Bishop.
    return bishop_is_legal_move(src_row, src_col, dest_row, dest_col, board);   
}

bool Bishop::bishop_is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    // Check if the move is legal diagonally for the Bishop.
    if (abs(src_row - dest_row) != abs(src_col - dest_col))
        return false;
    return !board->there_is_a_piece_diagonally(src_row, src_col, dest_row, dest_col);  
}
