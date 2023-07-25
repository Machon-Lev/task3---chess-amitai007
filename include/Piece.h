#pragma once
#include <string>
#include <memory>
#include "Player.h"

class Board;

/**
 * Represents a chess piece.
 */
class Piece
{
protected:
    Player _player;

public:
    // Constructor for the Piece.
    Piece(Player player);
    // Get the player (color) of the piece.
    Player get_player() const;

    /**
     * Checks if a move from the source position to the destination position is legal for the piece.
     *
     * @param source_row The row index of the source position.
     * @param source_col The column index of the source position.
     * @param dest_row The row index of the destination position.
     * @param dest_col The column index of the destination position.
     * @param board The chessboard object representing the current state of the game.
     * @return True if the move is legal for the piece, false otherwise.
     */
    virtual bool is_legal_move(int source_row, int source_col, int dest_row, int dest_col, const Board* board) = 0;
};
