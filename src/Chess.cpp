#include "Chess.h"

Chess::Chess(std::string title)
{
	sAppName = title;
}

Chess::~Chess()
{
	for (auto piece : m_activePieces)
	{
		delete piece;
	}
}

bool Chess::OnUserCreate()
{
	for (int i = 0; i < (int)Piece::TYPE::MAX; i++)
	{
		std::string num = std::to_string(i).append(".png");
		m_sprWhitePieces.push_back(std::make_unique<olc::Sprite>("./gfx/pieces/white/w" + num));
		m_sprBlackPieces.push_back(std::make_unique<olc::Sprite>("./gfx/pieces/black/b" + num));
	}

	// 8 by 8 board, not dynamic yet
	m_sprBoard = std::make_unique<olc::Sprite>("./gfx/board/board.png");
	m_sprBlackSquare = std::make_unique<olc::Sprite>("./gfx/board/squareB.png");
	m_sprWhiteSquare = std::make_unique<olc::Sprite>("./gfx/board/squareW.png");
	m_sprHighlightSquare = std::make_unique<olc::Sprite>("./gfx/board/highlight.png");
	m_sprAttackSquare = std::make_unique<olc::Sprite>("./gfx/board/attack.png");
		
	m_board = std::make_unique<Tile[]>(m_width * m_height);
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			Tile tile(x, y);

			if (y % 2 == 0)
			{
				if (x % 2 == 0)
					tile.SetType(Tile::TYPE::WHITE);
				else
					tile.SetType(Tile::TYPE::BLACK);
			}
			else
			{
				if (x % 2 == 0)
					tile.SetType(Tile::TYPE::BLACK);
				else
					tile.SetType(Tile::TYPE::WHITE);
			}

			m_board[y * m_width + x] = tile;
		}
	}

	return true;
}

bool Chess::OnUserUpdate(float fElapsedTime)
{
	/* GAME LOGIC */
	for (auto piece : m_activePieces)
	{
		if (!m_board[piece->GetTile()].IsOccupied())
			m_board[piece->GetTile()].SetPiece(piece);
	}

	auto IsWithinBounds = [&](olc::vi2d pos1, olc::vi2d pos2)
	{
		if (pos2.x < pos1.x)
			return false;
		if (pos2.y < pos1.y)
			return false;

		return true;
	};

	auto CalculateMove = [&](int tile, int step)
	{
		int index = 0;

		step <= 0 ? index = tile - abs(step) : index = tile + step;

		return index;
	};

	if (GetMouse(0).bPressed)
	{
		if (IsWithinBounds(GetMousePos(), olc::vi2d(m_width * m_tileSize.x + m_tileOffset.x, m_height * m_tileSize.y + m_tileOffset.y)))
		{
			int index = ((GetMouseY() - m_tileOffset.y) / m_tileSize.y) * m_width + ((GetMouseX() - m_tileOffset.x) / m_tileSize.x);
			Piece* piece = m_board[index].GetPiece();
			if (piece && (int)m_turn == (int)piece->GetColor())
			{
				m_selectedPiece = piece;
				std::cout << "Name: " << piece->GetName() << " Color: " << (int)piece->GetColor() << std::endl;
			}
			if (m_selectedPiece)
			{
				bool valid = false;
				for (Move move : m_selectedPiece->ValidMoves())
				{
					bool knight = false;
					if (m_selectedPiece->GetType() == Piece::TYPE::KNIGHT)
						knight = true;
					if (move.IsInvalidMove(m_selectedPiece->GetTile(), m_width, m_height, knight))
						continue;

					for (int i = 1; i <= move.GetSteps(); i++)
					{
						int newTile = CalculateMove(m_selectedPiece->GetTile(), (int)move.GetDirection() * i);

						if (newTile == index)
						{
							valid = true;
							break;
						}

						if (m_board[newTile].GetPiece())
							break;

						if (move.IsInvalidMove(newTile, m_width, m_height, knight))
							break;
					}

					if (valid)
						break;
				}

				if (valid)
				{
					m_selectedPiece->MoveTo(m_board, index);
					m_selectedPiece = nullptr;
					m_turn = m_turn == Chess::Turn::BLACK ? Chess::Turn::WHITE : Chess::Turn::BLACK;
				}
			}
		}
	}


	/* DRAWING */
	Clear(olc::DARK_RED);

	// board
	DrawSprite(olc::vi2d(0, 0), m_sprBoard.get());

	// tiles
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			int index = y * m_width + x;
			switch (m_board[index].GetType())
			{
			case Tile::TYPE::UNKNOWN:
				break;
			case Tile::TYPE::WHITE:
				DrawSprite(olc::vi2d(x, y) * m_tileSize + m_tileOffset, m_sprWhiteSquare.get());
				break;
			case Tile::TYPE::BLACK:
				DrawSprite(olc::vi2d(x, y) * m_tileSize + m_tileOffset, m_sprBlackSquare.get());
				break;
			}
			
			// pieces
			if (m_board[index].IsOccupied())
			{
				SetPixelMode(olc::Pixel::MASK);

				Piece* piece = m_board[index].GetPiece();
				piece->Draw(this, piece->GetColor() == Piece::COLOR::WHITE ? 
					m_sprWhitePieces[(int)piece->GetType()].get() : 
					m_sprBlackPieces[(int)piece->GetType()].get() ,
					olc::vi2d(x, y) * m_tileSize + m_tileOffset);

				SetPixelMode(olc::Pixel::NORMAL);
			}
		}
	}

	// visuals
	if (m_selectedPiece)
	{
		for (Move move : m_selectedPiece->ValidMoves())
		{
			bool knight = false;
			if (m_selectedPiece->GetType() == Piece::TYPE::KNIGHT)
				knight = true;
			if (move.IsInvalidMove(m_selectedPiece->GetTile(), m_width, m_height, knight))
				continue;

			for (int i = 1; i <= move.GetSteps(); i++)
			{
				int newTile = CalculateMove(m_selectedPiece->GetTile(), (int)move.GetDirection() * i);

				if (newTile < 0 || newTile > m_width * m_height)
					break;

				Tile::Coord pos = m_board[newTile].GetId();
				olc::vi2d sprPos = { pos.x, pos.y };
				// blue (empty tile)
				if (!m_board[newTile].GetPiece())
				{
					DrawSprite(sprPos * m_tileSize + m_tileOffset, m_sprHighlightSquare.get());
				}
				// red (occupied tile)
				else
				{
					//@TODO: layer it below piece
					if ((int)m_board[newTile].GetPiece()->GetColor() != (int)m_turn)
					{
						DrawSprite(sprPos * m_tileSize + m_tileOffset, m_sprAttackSquare.get());
					}

					break;
				}

				if (move.IsInvalidMove(newTile, m_width, m_height, knight))
					break;
			}
		}
	}

	return true;
}