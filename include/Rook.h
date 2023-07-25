#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(Player player);
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board) override;
};
