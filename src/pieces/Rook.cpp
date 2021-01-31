#include "Rook.h"

Rook::Rook(int tile, COLOR color)
{
    m_tile = tile;
    m_type = Piece::TYPE::ROOK;
    m_color = color;

    SetupMoves();
}

Rook::~Rook()
{
}

void Rook::SetupMoves()
{
    m_validMoves =
    {
        Move(Move::Direction::LEFT, 7),
        Move(Move::Direction::UP, 7),
        Move(Move::Direction::RIGHT, 7),
        Move(Move::Direction::DOWN, 7),
    };
}