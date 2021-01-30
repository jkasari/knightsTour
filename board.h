#ifndef ChessBoard_h
#define ChessBoard_h
#include "knight.h"
#include <iostream>

class ChessBoard {

  friend std::ostream& operator<<(std::ostream&, const ChessBoard&);

 public:
  ChessBoard();

 private:
  int8_t chessBoard[8][8];

};

#endif // ChessBoard_h
