#include "knight.h"

Knight::Knight(int8_t row, int8_t col) : row(row), col(col) {}


std::vector<Square> Knight::potentialMoves() {
    std::vector<Square> moves;
    int8_t up2 = row - 2;
    int8_t up1 = row - 1;
    int8_t down2 = row + 2;
    int8_t down1 = row + 1;
    int8_t right2 = col + 2;
    int8_t right1 = col + 1;
    int8_t left2 = col - 2;
    int8_t left1 = col - 1;

    if(isOnBoard(up2, right1)) {
        moves.push_back(Square(up2, right1));
    }

    if(isOnBoard(up2, left1)) {
        moves.push_back(Square(up2, left1));
    }

    if(isOnBoard(down2, right1)) {
        moves.push_back(Square(down2, right1));
    }

    if(isOnBoard(down2, left1)) {
        moves.push_back(Square(down2, left1));
    }

    if(isOnBoard(up1, right2)) {
        moves.push_back(Square(up1, right2));
    }

    if(isOnBoard(down1, right2)) {
        moves.push_back(Square(down1, right2));
    }

    if(isOnBoard(up1, left2)) {
        moves.push_back(Square(up1, left2));
    }

    if(isOnBoard(down1, left2)) {
        moves.push_back(Square(down1, left2));
    }
    return moves;
}


bool Knight::isOnBoard(int8_t row, int8_t col) {
    return (0 <= row && row <= 7)
        && (0 <= col && col <= 7);
}