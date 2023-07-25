#include "Piece.h"
#include "Board.h"

// Constructor
Piece::Piece(Player player)
{
    _player = player;
}

// Getter function to retrieve the player who owns the piece
Player Piece::get_player() const
{
    return _player;
}
