#pragma once

class Move
{
public:
    enum class Direction
    {
        UP_LEFT = -9,
        UP = -8,
        UP_RIGHT = -7,
        LEFT = -1,
        RIGHT = 1,
        DOWN_LEFT = 7,
        DOWN = 8,
        DOWN_RIGHT = 9,

        KNIGHT_UP_LEFT_1 = -17,
        KNIGHT_UP_LEFT_2 = -10,
        KNIGHT_UP_RIGHT_1 = -15,
        KNIGHT_UP_RIGHT_2 = -6,
        KNIGHT_DOWN_LEFT_1 = 17,
        KNIGHT_DOWN_LEFT_2 = 6,
        KNIGHT_DOWN_RIGHT_1 = 15,
        KNIGHT_DOWN_RIGHT_2 = 10,
    };

    Move(Direction dir, int steps);
    ~Move();

    bool IsInvalidMove(int tile, int width, int height, bool knight = false);

    Direction GetDirection() const;
    int GetSteps() const;

private:
    Direction m_direction;
    int m_steps;
};

