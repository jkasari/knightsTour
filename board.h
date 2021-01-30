#ifndef ChessBoard_h
#define ChessBoard_h
#include "knight.h"
#include <iostream>

class ChessBoard {

  friend std::ostream& operator<<(std::ostream&, const ChessBoard&);

 public:
  ChessBoard();
  /**
  * Leaves an '@' at any given point on the chessboard.
  * Planning on using this as a way for board to keep track
  * of where the knight as been previously.
  */
  void waterMark(int8_t, int8_t);
  /**
   * This checks a potential move on a live chessboard and
   * returns number of possible ways to get into that move.
   * This plays by the rules of the knight class and also
   * checks for "*" if the knight had already touched that spot.
   */
  int8_t newMoveOptions(int8_t, int8_t);

 private:
  char chessBoard[8][8];

};

#endif // ChessBoard_h
