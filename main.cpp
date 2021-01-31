#include <iostream>
#include <unistd.h>
#include "board.h"
#include "knight.h"
using namespace std;


void clearScreen(void) {
   for(int i = 0; i < 100; ++i) {
    cout << endl;
   }
}

int main(int32_t argc, char** argv) {

  if(argc != 3) {
    cout << "This program requires exactly two values:" << endl << endl;
    cout << "  -The starting row for the knight." << endl << endl;
    cout << "  -The starting colum for the knight." << endl;
    return 1;
  }


  ChessBoard board1;
  int8_t currentRow = stol(argv[1]);
  int8_t currentCol = stol(argv[2]);
  int8_t futureRow;
  int8_t futureCol;

  if(0 > currentRow || currentRow > 7 || 0 > currentCol || currentCol > 7) {
    cout << "\"Row\" and \"Col\" values must between 0 and 7." << endl;
    return 1;
  }

  for(int i = 0; i < 64; ++i) {

    board1.moveKnightCurrent(currentRow, currentCol);
    cout << board1;
    cout.width(17);
    cout << i + 1 << endl;
    usleep(100000);
    clearScreen();
    board1.moveKnightPast(currentRow, currentCol);

    futureRow = board1.findNextMove(currentRow, currentCol).first;
    futureCol = board1.findNextMove(currentRow, currentCol).second;
    currentRow = futureRow;
    currentCol = futureCol;
  }

  return 0;
}
