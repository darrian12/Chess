#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(int tile, COLOR color);
    ~Bishop();

    void SetupMoves() override;

private:

};

