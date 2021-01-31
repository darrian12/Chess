#pragma once

#include "olcPixelGameEngine.h"
#include "Tile.h"
#include "Move.h"

class Piece
{
public:
	enum class TYPE
	{
		PAWN,
		ROOK,
		KNIGHT,
		BISHOP,
		QUEEN,
		KING,

		MAX,
	};

    enum class COLOR
    {
        WHITE,
        BLACK,
    };

public:
    Piece();
    ~Piece();

	void Draw(olc::PixelGameEngine* pge, olc::Sprite* spr, olc::vi2d pos);
	std::vector<Move> ValidMoves() const;

	// virtuals
	virtual void MoveTo(const std::unique_ptr<Tile[]>& board, int destination);
	virtual void SetupMoves() = 0;

	// gets
	TYPE  GetType()			const;
	COLOR GetColor()		const;
	int	  GetTile()         const;
	// debugging purpose
	std::string GetName()	const;

	// sets
	void SetType(TYPE type);
	void SetColor(COLOR color);
	void SetTile(int n);

protected:
	TYPE m_type;
    COLOR m_color;
	int m_tile;

	std::vector<Move> m_validMoves = {};
};
