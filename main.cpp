#include <iostream>
#include "board.h"

using namespace std;


int main() {

  ChessBoard chessBoard1;

  chessBoard1.waterMark(7, 7);

  cout << chessBoard1 << endl;

  return 0;
}
