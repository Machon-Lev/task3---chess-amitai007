#include "Queen.h"
#include "Board.h"
#include "Bishop.h"
#include "Rook.h"

// Constructor
Queen::Queen(Player player) : Piece(player) {}

// Check if the move is legal for the Queen
bool Queen::is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    Bishop b = Bishop(get_player());
    Rook r = Rook(get_player());

    // Check if the move is legal for a Rook or a Bishop
    return r.is_legal_move(src_row, src_col, dest_row, dest_col, board)
        || b.is_legal_move(src_row, src_col, dest_row, dest_col, board);
}
