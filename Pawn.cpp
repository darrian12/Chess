#include "Pawn.h"

Pawn::Pawn(int tile, COLOR color)
{
    m_tile = tile;
    m_type = Piece::TYPE::PAWN;
    m_color = color;

    SetupMoves();
}

Pawn::~Pawn()
{
}

void Pawn::MoveTo(const std::unique_ptr<Tile[]>& board, int destination)
{
    m_firstMove = false;

    if (board[destination].GetPiece())
    {
        //@TODO: delete grabbed piece from active pieces vector
        board[destination].RemovePiece();
    }

    board[m_tile].RemovePiece();
    this->SetTile(destination);

    // re-checking moves since pawn changes depending on first move or not
    SetupMoves();
}

void Pawn::SetupMoves()
{
    if (m_color == COLOR::BLACK)
        m_validMoves =
        {
            Move(Move::Direction::UP, m_firstMove ? 2 : 1),
        };
    else
        m_validMoves =
        {
            Move(Move::Direction::DOWN, m_firstMove ? 2 : 1),
        };
}
