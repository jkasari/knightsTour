#include "board.h"
#include <iomanip>


std::ostream& operator<<(std::ostream& stream, const ChessBoard& chessBoard) {
    stream << "+---+---+---+---+---+---+---+---+" << std::endl;
    for(int i = 0; i < 8; i++) {
        stream << "| ";
        for(int j = 0; j < 8; j++) {
        //    stream << std::setfill('0') << std::setw(2);
            stream << static_cast<char>(chessBoard.chessBoard[i][j]) << " | ";
        }
        if(i < 7) {
          stream << std::endl << "|---|---|---|---|---|---|---|---|" << std::endl;
        }
    }
    stream << std::endl << "+---+---+---+---+---+---+---+---+" << std::endl;
    return stream;
}


ChessBoard::ChessBoard() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            chessBoard[i][j] = ' ';
        }
    }
}

void ChessBoard::waterMark(int8_t row, int8_t col) {
    if(0 > row || row > 7 || 0 > col || col > 7) {
        return;
    }
    chessBoard[row][col] = '@';
}


int8_t ChessBoard::newMoveOptions(int8_t row, int8_t col) {
    Knight arthur(row, col);
    int8_t previousMoves = 0;
    std::vector<Square> movesOnBoard = arthur.potentialMoves();
    for(int i = 0; i < movesOnBoard.size(); ++i) {
        if(chessBoard[movesOnBoard[i].first][movesOnBoard[i].second] == '@') {
            previousMoves += 1;
        }
    }
    return movesOnBoard.size() - previousMoves;
}

// +----+----+----+----+----+----+----+----+
// | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 |
// |----|----|----|----|----|----|----|----|
// | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 |
// |----|----|----|----|----|----|----|----|
// | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 |
// |----|----|----|----|----|----|----|----|
// | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 |
// |----|----|----|----|----|----|----|----|
// | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
// |----|----|----|----|----|----|----|----|
// | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 |
// |----|----|----|----|----|----|----|----|
// | 60 | 61 | 62 | 63 | 64 | 65 | 66 | 67 |
// |----|----|----|----|----|----|----|----|
// | 70 | 71 | 72 | 73 | 74 | 75 | 76 | 77 |
// +----+----+----+----+----+----+----+----+