#include "board.hpp"

#include "board_const.hpp"

Board::Board()
    : ball({ BOARD_WIDTH / 2, BOARD_HEIGHT / 2 }),
      player1({ 100, BOARD_HEIGHT / 2, Player::Side::LEFT }),
      player2({ 100, BOARD_HEIGHT / 2, Player::Side::RIGHT }),
      canvas(BOARD_WIDTH, BOARD_HEIGHT)
{
  UpdateBoard();
}

void Board::Render() const { canvas.Render(); }

void Board::MovePlayer1(bool toUp)
{
  int pos = player1.GetPosition();
  if (toUp)
  {
    if (pos < MAX_UPPER_POSITION)
    {
      player1.IncrementPosition();
    }
  }
  else
  {
    if (pos > MIN_LOWER_POSITION)
    {
      player1.DecrementPosition();
    }
  }
  UpdateBoard();
}

void Board::UpdateBoard()
{
  GraRen::Rectangle player1_rect = player1.GetDrawable();
  GraRen::Rectangle player2_rect = player2.GetDrawable();
  GraRen::Circle ball_rect = ball.GetDrawable();

  std::vector<GraRen::IElement*> elems{ &player1_rect,
                                        &player2_rect,
                                        &ball_rect };

  canvas.UpdateData(elems);
}