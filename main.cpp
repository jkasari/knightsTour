#include <iostream>
#include "board.h"
#include "knight.h"

using namespace std;


int main() {

  ChessBoard board1;
  int8_t currentRow = 0;
  int8_t currentCol = 0;
  int8_t futureRow;
  int8_t futureCol;

  for(int i = 0; i < 64; ++i) {

    board1.moveKnightCurrent(currentRow, currentCol);
    cout << board1;
    cout << i + 1 << endl << endl;
    board1.moveKnightPast(currentRow, currentCol);

    futureRow = board1.findNextMove(currentRow, currentCol).first;
    futureCol = board1.findNextMove(currentRow, currentCol).second;
    currentRow = futureRow;
    currentCol = futureCol;
  }

  return 0;
}
