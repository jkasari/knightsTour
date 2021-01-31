#ifndef ChessBoard_h
#define ChessBoard_h
#include "knight.h"
#include <iostream>

class ChessBoard {

  friend std::ostream& operator<<(std::ostream&, const ChessBoard&);

 public:
  ChessBoard();


  /**
   * This leaves a '#' to show exactly where the knight currently is.
   * This is just for display purposes and when used with out |moveKnightPast|
   * will cause the program to crash. Make sure to pass both move knight
   * functions the same values!!!
   */
  void moveKnightCurrent(int8_t, int8_t);

  /**
   * This leaves a '@' mark after the knight as left the spot. This mark
   * is what all the functions are looking for when choosing the next move.
   */
  void moveKnightPast(int8_t, int8_t);

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
