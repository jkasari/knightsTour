#include "board.h"
#include "knight.h"
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

int8_t ChessBoard::findSmallestIndex(std::vector<int8_t> moveValues) {
    int8_t smallestVal = 8;
    int8_t smallestIndex;
    for(int i = 0; i < moveValues.size(); ++i) {
       if(moveValues[i] < smallestVal) {
           smallestVal = moveValues[i];
           smallestIndex = i;
       }
    }
    return smallestIndex;
}


int8_t ChessBoard::newMoveOptions(int8_t row, int8_t col) {
    Knight arthur(row, col);
    int8_t previousLocations = 0;
    if(chessBoard[row][col] == '@') {
        return 0;
    }
    std::vector<Square> movesOnBoard = arthur.potentialMoves();
    for(int i = 0; i < movesOnBoard.size(); ++i) {
        if(chessBoard[movesOnBoard[i].first][movesOnBoard[i].second] == '@') {
            previousLocations += 1;
        }
    }
    if(movesOnBoard.size() - previousLocations == 0) {
        return 10;//This makes sure you never feed |findSmallestIndex| a zero value. I'm sure there is a better way to do this.
    }
    return movesOnBoard.size() - previousLocations;
}


void ChessBoard::moveKnight(int8_t row, int8_t col) {
    if(0 > row || row > 7 || 0 > col || col > 7) {
        return;
    }
    chessBoard[row][col] = '@';
}


Square ChessBoard::findNextMove(int8_t row, int8_t col) {
    Knight Arthur(row, col);
    int8_t indexOfNextMove;
    std::vector<Square> nextMoves = Arthur.potentialMoves();
    std::vector<int8_t> nextMoveVals;
    for(int i = 0; i < nextMoves.size(); ++i) {
        nextMoveVals.push_back(newMoveOptions(nextMoves[i].first, nextMoves[i].second));
    }
    indexOfNextMove = findSmallestIndex(nextMoveVals);
    return nextMoves[indexOfNextMove];
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