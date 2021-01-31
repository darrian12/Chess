#pragma once

#include "olcPixelGameEngine.h"
#include "Tile.h"
#include "Piece.h"
#include "Move.h"
#include "all_pieces.h"

#include <unordered_map>

class Chess : public olc::PixelGameEngine
{
public:
	Chess(std::string title);
	~Chess();

	enum class Turn
	{
		WHITE,
		BLACK
	};

private:
	// Called once at the start
	bool OnUserCreate()						override;
	// Called once per frame
	bool OnUserUpdate(float fElapsedTime)	override;

private:
	Chess::Turn m_turn = Chess::Turn::BLACK;

	bool DrawTestSquare = false;
	olc::vi2d TestSquarePos;

	// board
	int m_width  = 8;
	int m_height = 8;
	std::unique_ptr<Tile[]> m_board = nullptr;

	// pieces
	Piece* m_selectedPiece = nullptr;
	std::vector<Piece*> m_activePieces =
	{
		// white
		//{ new Rook(0, Piece::COLOR::WHITE)		},
		{ new Knight(1, Piece::COLOR::WHITE)	},
		//{ new Bishop(2, Piece::COLOR::WHITE)	},
		//{ new King(3, Piece::COLOR::WHITE)		},
		//{ new Queen(4, Piece::COLOR::WHITE)		},
		//{ new Bishop(5, Piece::COLOR::WHITE)	},
		{ new Knight(6, Piece::COLOR::WHITE)	},
		//{ new Rook(7, Piece::COLOR::WHITE)		},

		//{ new Pawn(8, Piece::COLOR::WHITE)		},
		//{ new Pawn(9, Piece::COLOR::WHITE)		},
		//{ new Pawn(10, Piece::COLOR::WHITE)		},
		//{ new Pawn(11, Piece::COLOR::WHITE)		},
		//{ new Pawn(12, Piece::COLOR::WHITE)		},
		//{ new Pawn(13, Piece::COLOR::WHITE)		},
		//{ new Pawn(14, Piece::COLOR::WHITE)		},
		//{ new Pawn(15, Piece::COLOR::WHITE)		},

		//// black
		//{ new Pawn(48, Piece::COLOR::BLACK)		},
		//{ new Pawn(49, Piece::COLOR::BLACK)		},
		//{ new Pawn(50, Piece::COLOR::BLACK)		},
		//{ new Pawn(51, Piece::COLOR::BLACK)		},
		//{ new Pawn(52, Piece::COLOR::BLACK)		},
		//{ new Pawn(53, Piece::COLOR::BLACK)		},
		//{ new Pawn(54, Piece::COLOR::BLACK)		},
		//{ new Pawn(55, Piece::COLOR::BLACK)		},

		//{ new Rook(56, Piece::COLOR::BLACK)		},
		{ new Knight(57, Piece::COLOR::BLACK)	},
		//{ new Bishop(58, Piece::COLOR::BLACK)	},
		/*{ new King(59, Piece::COLOR::BLACK)		},
		{ new Queen(60, Piece::COLOR::BLACK)	},*/
		//{ new Bishop(61, Piece::COLOR::BLACK)	},
		{ new Knight(62, Piece::COLOR::BLACK)	},
		//{ new Rook(63, Piece::COLOR::BLACK)		},
	};

	// textures
	olc::vi2d m_tileSize	= { 53, 53 };
	//olc::vi2d m_pieceSize	= { 51,	51 };
	olc::vi2d m_tileOffset	= { 14, 14 };
	std::vector<std::unique_ptr<olc::Sprite>>		    m_sprBlackPieces;
	std::vector<std::unique_ptr<olc::Sprite>>			m_sprWhitePieces;
	std::unique_ptr<olc::Sprite>						m_sprBoard				= nullptr;
	std::unique_ptr<olc::Sprite>						m_sprBlackSquare		= nullptr;
	std::unique_ptr<olc::Sprite>						m_sprWhiteSquare		= nullptr;
	std::unique_ptr<olc::Sprite>						m_sprHighlightSquare	= nullptr;
	std::unique_ptr<olc::Sprite>						m_sprAttackSquare		= nullptr;
};
