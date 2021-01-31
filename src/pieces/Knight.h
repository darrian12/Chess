#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(int tile, COLOR color);
    ~Knight();

    void SetupMoves() override;

private:

};

