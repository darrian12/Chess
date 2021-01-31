#include "King.h"

King::King(int tile, COLOR color)
{
    m_tile = tile;
    m_type = Piece::TYPE::KING;
    m_color = color;

    SetupMoves();
}

King::~King()
{
}

void King::SetupMoves()
{
    m_validMoves =
    {
        Move(Move::Direction::UP_LEFT, 1),
        Move(Move::Direction::UP, 1),
        Move(Move::Direction::UP_RIGHT, 1),
        Move(Move::Direction::LEFT, 1),
        Move(Move::Direction::RIGHT, 1),
        Move(Move::Direction::DOWN_LEFT, 1),
        Move(Move::Direction::DOWN, 1),
        Move(Move::Direction::DOWN_RIGHT, 1),
    };
}