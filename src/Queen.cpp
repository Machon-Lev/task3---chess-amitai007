#include "Queen.h"
#include "Board.h"
#include "Bishop.h"

Queen::Queen(Player player) : Piece(player){}

bool Queen::is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board)
{
    Bishop b = Bishop(get_player());
    Rook r = Rook(get_player());

    return r.is_legal_move(src_row, src_col, dest_row, dest_col, board)
        || b.is_legal_move(src_row, src_col, dest_row, dest_col, board);
}