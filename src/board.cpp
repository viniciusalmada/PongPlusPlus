#include "board.hpp"

#include "board_const.hpp"

Board::Board()
    : ball({ BOARD_WIDTH / 2, BOARD_HEIGHT / 2 }),
      player1({ 100, BOARD_HEIGHT / 2, Player::Side::LEFT }),
      player2({ 100, BOARD_HEIGHT / 2, Player::Side::RIGHT })
{
}