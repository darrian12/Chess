#pragma once

#include "Piece.h"
class Tile;

class Pawn : public Piece
{
public:
    Pawn(int tile, COLOR color);
    ~Pawn();

    void MoveTo(const std::unique_ptr<Tile[]>& board, int destination) override;
    void SetupMoves() override;

private:
    bool m_firstMove = true;
};

