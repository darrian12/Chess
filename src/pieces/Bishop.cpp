#include "Bishop.h"

Bishop::Bishop(int tile, COLOR color)
{
    m_tile = tile;
    m_type = Piece::TYPE::BISHOP;
    m_color = color;

    SetupMoves();
}

Bishop::~Bishop()
{
}

void Bishop::SetupMoves()
{
    m_validMoves =
    {
        Move(Move::Direction::UP_LEFT, 7),
        Move(Move::Direction::UP_RIGHT, 7),
        Move(Move::Direction::DOWN_LEFT, 7),
        Move(Move::Direction::DOWN_RIGHT, 7),
    };
}