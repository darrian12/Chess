#include "Move.h"

Move::Move(Direction dir, int steps)
{
    m_direction = dir;
    m_steps = steps;
}

Move::~Move()
{
}

bool Move::IsInvalidMove(int tile, int width, int height, bool knight)
{
    int remainder = tile % width;
    // left side boundary
    if (remainder == 0)
    {
        switch (m_direction)
        {
        case Direction::DOWN_LEFT:
        case Direction::LEFT:
        case Direction::UP_LEFT:
        case Direction::KNIGHT_UP_LEFT_2:
        case Direction::KNIGHT_UP_LEFT_1:
        case Direction::KNIGHT_DOWN_LEFT_2:
        case Direction::KNIGHT_DOWN_LEFT_1:
            return true;
        }
    }
    // right side boundary
    if (remainder == width - 1)
    {
        switch (m_direction)
        {
        case Direction::DOWN_RIGHT:
        case Direction::RIGHT:
        case Direction::UP_RIGHT:
        case Direction::KNIGHT_UP_RIGHT_2:
        case Direction::KNIGHT_UP_RIGHT_1:
        case Direction::KNIGHT_DOWN_RIGHT_2:
        case Direction::KNIGHT_DOWN_RIGHT_1:

            return true;
        }
    }
    // up side boundary
    if (tile >= 0 && tile < width)
    {
        switch (m_direction)
        {
        case Direction::UP:
        case Direction::UP_LEFT:
        case Direction::UP_RIGHT:
        case Direction::KNIGHT_UP_RIGHT_2:
        case Direction::KNIGHT_UP_RIGHT_1:
        case Direction::KNIGHT_UP_LEFT_2:
        case Direction::KNIGHT_UP_LEFT_1:
            return true;
        }
    }
    // down side boundary
    if (tile >= height * width - width && tile < height * width)
    {
        switch (m_direction)
        {
        case Direction::DOWN:
        case Direction::DOWN_LEFT:
        case Direction::DOWN_RIGHT:
        case Direction::KNIGHT_DOWN_RIGHT_2:
        case Direction::KNIGHT_DOWN_RIGHT_1:
        case Direction::KNIGHT_DOWN_LEFT_2:
        case Direction::KNIGHT_DOWN_LEFT_1:
            return true;
        }
    }

    if (knight)
    {
        // knight top left - 1
        if (tile == width)
            if (m_direction == Direction::KNIGHT_UP_RIGHT_1)
                return true;
        // knight top left
        if (tile == 0)
        {
            switch (m_direction)
        case Direction::KNIGHT_UP_RIGHT_1:
        case Direction::KNIGHT_UP_RIGHT_2:
            return true;
        }
        // knight bottom left - 1
        if (tile == (height - 2) * width)
            if (m_direction == Direction::KNIGHT_DOWN_RIGHT_1)
                return true;
        // knight B1
        if (tile == (height - 1) * width + 1)
            if (m_direction == Direction::KNIGHT_UP_LEFT_2)
                return true;
        // knight G1
        if (tile == height * width - 2)
            if (m_direction == Direction::KNIGHT_UP_RIGHT_2)
                return true;
        // knight H2
        if (tile == (height - 1) * width - 1)
        {
            switch (m_direction)
            {
            case Direction::KNIGHT_DOWN_LEFT_1:
            case Direction::KNIGHT_DOWN_RIGHT_1:
            case Direction::KNIGHT_DOWN_RIGHT_2:
                return true;
            }
        }
        // knight H7
        if (tile == width * 2 - 1)
            if (m_direction == Direction::KNIGHT_UP_LEFT_1)
                return true;
        // knight H8
        if (tile == width - 1)
        {
            switch (m_direction)
            {
            case Direction::KNIGHT_UP_LEFT_1:
            case Direction::KNIGHT_UP_LEFT_2:
                return true;
            }
        }
        // knight G8
        if (tile == width - 2)
            if (m_direction == Direction::KNIGHT_DOWN_RIGHT_2)
                return true;
        // knight B8
        if (tile == 1)
            if (m_direction == Direction::KNIGHT_DOWN_LEFT_2)
                return true;

        // missing inner layer (second)
    }

    return false;
}

Move::Direction Move::GetDirection() const
{
    return m_direction;
}

int Move::GetSteps() const
{
    return m_steps;
}
