#include "Piece.h"

Piece::Piece()
{
    //SetupMoves();
}

Piece::~Piece()
{
}

void Piece::Draw(olc::PixelGameEngine* pge, olc::Sprite* spr, olc::vi2d pos)
{
    pge->DrawSprite(pos, spr);
}

std::vector<Move> Piece::ValidMoves() const
{
    return m_validMoves;
}

void Piece::MoveTo(const std::unique_ptr<Tile[]>& board, int destination)
{
    if (board[destination].GetPiece())
    {
        //@TODO: delete grabbed piece from active pieces vector
        board[destination].RemovePiece();
    }

    board[m_tile].RemovePiece();
    this->SetTile(destination);
}

Piece::TYPE Piece::GetType() const
{
    return m_type;
}

Piece::COLOR Piece::GetColor() const
{
    return m_color;
}

int Piece::GetTile() const
{
    return m_tile;
}

// debug only
std::string Piece::GetName() const
{
    std::string name = "";
    switch (m_type)
    {
    case Piece::TYPE::PAWN:
        name = "Pawn";
        break;
    case Piece::TYPE::ROOK:
        name = "Rook";
        break;
    case Piece::TYPE::KNIGHT:
        name = "Knight";
        break;
    case Piece::TYPE::BISHOP:
        name = "Bishop";
        break;
    case Piece::TYPE::QUEEN:
        name = "Queen";
        break;
    case Piece::TYPE::KING:
        name = "King";
        break;
    }

    return name;
}

void Piece::SetType(TYPE type)
{
    m_type = type;
}

void Piece::SetColor(COLOR color)
{
    m_color = color;
}

void Piece::SetTile(int n)
{
    m_tile = n;
}
