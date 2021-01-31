#include "Queen.h"

Queen::Queen(int tile, COLOR color)
{
    m_tile = tile;
    m_type = Piece::TYPE::QUEEN;
    m_color = color;

    SetupMoves();
}

Queen::~Queen()
{
}

void Queen::SetupMoves()
{
    m_validMoves =
    {
        Move(Move::Direction::UP_LEFT, 7),
        Move(Move::Direction::UP, 7),
        Move(Move::Direction::UP_RIGHT, 7),
        Move(Move::Direction::LEFT, 7),
        Move(Move::Direction::RIGHT, 7),
        Move(Move::Direction::DOWN_LEFT, 7),
        Move(Move::Direction::DOWN, 7),
        Move(Move::Direction::DOWN_RIGHT, 7),
    };
}