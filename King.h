#pragma once

#include "Piece.h"

class King : public Piece
{
public:
    King(int tile, COLOR color);
    ~King();

    void SetupMoves() override;

private:

};

