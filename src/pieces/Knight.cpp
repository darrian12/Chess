#include "Knight.h"

Knight::Knight(int tile, COLOR color)
{
    m_tile = tile;
    m_type = Piece::TYPE::KNIGHT;
    m_color = color;

    SetupMoves();
}

Knight::~Knight()
{
}

void Knight::SetupMoves()
{
    m_validMoves =
    {
        Move(Move::Direction::KNIGHT_UP_LEFT_1, 1),
        Move(Move::Direction::KNIGHT_UP_LEFT_2, 1),
        Move(Move::Direction::KNIGHT_UP_RIGHT_1, 1),
        Move(Move::Direction::KNIGHT_UP_RIGHT_2, 1),
        Move(Move::Direction::KNIGHT_DOWN_LEFT_1, 1),
        Move(Move::Direction::KNIGHT_DOWN_LEFT_2, 1),
        Move(Move::Direction::KNIGHT_DOWN_RIGHT_1, 1),
        Move(Move::Direction::KNIGHT_DOWN_RIGHT_2, 1),
    };
}