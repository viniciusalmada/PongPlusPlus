#include "board.hpp"

Board::Board()
    : ball({ WIDTH / 2, HEIGHT / 2 }), player1({ 100, HEIGHT / 2 }),
      player2({ 100, HEIGHT / 2 })
{
}