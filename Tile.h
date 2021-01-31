#pragma once

class Piece;
//#include "olcPixelGameEngine.h"

class Tile
{
public:
	enum class TYPE
	{
		UNKNOWN,

		WHITE,
		BLACK,
	};

	struct Coord
	{
		int x;
		int y;
	};

public:
	Tile();
	Tile(Coord id);
	Tile(int x, int y);
	~Tile();

	// gets
	Coord  GetId()			const;
	TYPE   GetType()		const;
	Piece* GetPiece()		const;
	bool   IsOccupied()		const;

	// sets
	void SetId(Coord id);
	void SetType(TYPE type);
	void SetPiece(Piece* piece);

	void RemovePiece();

private:
	Coord  m_id;
	TYPE   m_type		= Tile::TYPE::UNKNOWN;
	Piece* m_piece		= nullptr;
	bool   m_occupied	= false;
};
