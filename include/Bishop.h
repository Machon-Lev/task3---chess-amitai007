#pragma once
#include "Piece.h"

class Bishop : public Piece {
private:
    bool bishop_is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board);

public:
    Bishop(Player player);
    bool is_legal_move(int src_row, int src_col, int dest_row, int dest_col, const Board* board);   
};
