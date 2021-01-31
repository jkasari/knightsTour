#ifndef ChessBoard_h
#define ChessBoard_h
#include "knight.h"
#include <iostream>

class ChessBoard {

  friend std::ostream& operator<<(std::ostream&, const ChessBoard&);

 public:
  ChessBoard();


  /**
   * This moves a knight to any given location and leaves a watermark once
   * it's there.
   */
  void moveKnight(int8_t, int8_t);

  /**
   * This checks a potential move on a live chessboard and
   * returns number of possible ways to get into that move.
   * This plays by the rules of the knight class and also
   * checks for "*" if the knight had already touched that spot.
   */
  int8_t newMoveOptions(int8_t, int8_t);

  int8_t findSmallestIndex(std::vector<int8_t>);

  /**
   * This takes a current knight location and returns the best option for a
   * new knight location.
   */
  Square findNextMove(int8_t, int8_t);

 private:
  char chessBoard[8][8];

};

#endif // ChessBoard_h
