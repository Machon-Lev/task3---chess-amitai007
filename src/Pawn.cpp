#include "Pawn.h"

// Constructor
Pawn::Pawn(Player player) : Piece(player) {}

// Check if the move is legal for the Pawn
bool Pawn::is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    // Check capturing move for White Pawn
    if (_player == WHITE_PLAYER && dest_row - src_row == 1 && abs(dest_col - src_col) == 1
        && (*board).getPiece(dest_row, dest_col) != nullptr)
    {
        return true;
    }
    // Check capturing move for Black Pawn
    else if (_player == BLACK_PLAYER && dest_row - src_row == -1 && abs(dest_col - src_col) == 1
        && (*board).getPiece(dest_row, dest_col) != nullptr)
    {
        return true;
    }

    // Check non-capturing move
    if (src_col != dest_col)
    {
        return false;
    }

    // Check the initial double-step move for White Pawn
    if (_player == WHITE_PLAYER && dest_row != 3 && dest_row - src_row != 1)
    {
        return false;
    }
    // Check the initial double-step move for Black Pawn
    else if (_player == BLACK_PLAYER && dest_row != 4 && dest_row - src_row != -1)
    {
        return false;
    }

    // Check if there is a piece directly in front of the Pawn
    if (_player == WHITE_PLAYER)
    {
        return !(*board).there_is_a_piece_directly(src_row, src_col, dest_row + 1, dest_col);
    }
    else
    {
        return !(*board).there_is_a_piece_directly(src_row, src_col, dest_row - 1, dest_col);
    }
}
