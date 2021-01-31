#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(int tile, COLOR color);
    ~Queen();

    void SetupMoves() override;

private:

};

