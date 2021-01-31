#include <iostream>
#include "board.h"
#include "knight.h"

using namespace std;


int main() {

  ChessBoard board1;
  int8_t currentRow = 2;
  int8_t currentCol = 4;
  int8_t futureRow;
  int8_t futureCol;

  for(int i = 0; i < 2; ++i) {
    board1.moveKnight(currentRow, currentCol);
    cout << currentRow << "  " << currentCol << endl;
    //cout << board1 << endl;

  //  futureRow = board1.findNextMove(currentRow, currentCol).first;
  //  futureCol = board1.findNextMove(currentRow, currentCol).second;
  //  currentRow = futureRow;
  //  currentCol = futureCol;
  }

  return 0;
}
