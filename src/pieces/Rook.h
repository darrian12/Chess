#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(int tile, COLOR color);
    ~Rook();

    void SetupMoves() override;

private:

};

