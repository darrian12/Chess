#include "Tile.h"

Tile::Tile()
{
    m_id = { 0, 0 };
}

Tile::Tile(Tile::Coord id)
{
    m_id = id;
}

Tile::Tile(int x, int y)
{
    m_id.x = x;
    m_id.y = y;
}

Tile::~Tile()
{
}

Tile::Coord Tile::GetId() const
{
    return m_id;
}

Tile::TYPE Tile::GetType() const
{
    return m_type;
}

Piece* Tile::GetPiece() const
{
    return m_piece;
}

bool Tile::IsOccupied() const
{
    return m_occupied;
}

void Tile::SetId(Tile::Coord id)
{
    m_id = id;
}

void Tile::SetType(TYPE type)
{
    m_type = type;
}

void Tile::SetPiece(Piece* piece)
{
    m_piece = piece;
    m_occupied = true;
}

void Tile::RemovePiece()
{
    m_piece = nullptr;
    m_occupied = false;
}
