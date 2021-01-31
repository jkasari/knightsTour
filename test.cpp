#include <iostream>
#include <vector>
#include <utility>
#include "knight.h"
#include "board.h"
#include "nuttiest/nuttiest.hpp"

using namespace std;
using namespace nuttiest;

int main() {
  section("knight") {
    unit_test("potentialMoves") {
      Knight aurther(0, 0);
      vector<Square> expectedMoves{
          Square(2, 1),
          Square(1, 2),
      };
      vector<Square> actualMoves = aurther.potentialMoves();
      assert_eq(expectedMoves.size(),
                actualMoves.size()) for (int i = 0; i < expectedMoves.size();
                                         i++) {
        assert_eq(expectedMoves[i].first, actualMoves[i].first);
        assert_eq(expectedMoves[i].second, actualMoves[i].second);
      }
    }
    unit_test("potentialMoves") {
      Knight aurther(4, 4);
      vector<Square> expectedMoves{
          Square(2, 5),  // up2, right1
          Square(2, 3),  // up2, left1
          Square(6, 5),  // down2, right1
          Square(6, 3),  // down2, left1
          Square(3, 6),  // up1, right2
          Square(5, 6),  // up1, left2
          Square(3, 2),  // down1, right2
          Square(5, 2),  // down1, left2
      };
      vector<Square> actualMoves = aurther.potentialMoves();
      assert_eq(expectedMoves.size(),
                actualMoves.size()) for (int i = 0; i < expectedMoves.size();
                                         i++) {
        assert_eq(expectedMoves[i].first, actualMoves[i].first);
        assert_eq(expectedMoves[i].second, actualMoves[i].second);
      }
    }
    unit_test("potentialMoves") {
      Knight aurther(4, 6);
      vector<Square> expectedMoves{
          Square(2, 7),  // up2, right1
          Square(2, 5),  // up2, left1
          Square(6, 7),  // down2, right1
          Square(6, 5),  // down2, left1
          Square(3, 4),  // up1, left2
          Square(5, 4),  // down1, left2
      };
      vector<Square> actualMoves = aurther.potentialMoves();
      assert_eq(expectedMoves.size(),
                actualMoves.size()) for (int i = 0; i < expectedMoves.size();
                                         i++) {
        assert_eq(expectedMoves[i].first, actualMoves[i].first);
        assert_eq(expectedMoves[i].second, actualMoves[i].second);
      }
    }
  }
  section("newMoveOptions") {
    unit_test("newMoveOptions") {
      ChessBoard board1;
      int8_t numberOfOptions = board1.newMoveOptions(0, 0);
      assert_eq(numberOfOptions, 2);

      board1.moveKnight(1, 2);
      numberOfOptions = board1.newMoveOptions(0, 0);
      assert_eq(numberOfOptions, 1);

      board1.moveKnight(2, 1);
      numberOfOptions = board1.newMoveOptions(0, 0);
      assert_eq(numberOfOptions, 10);
      //This is because newMoveOptions returns a 10 if the potential moves reach zero.
      //Yes this is dumb, but it works.
    }
    unit_test("newMoveOptions") {
      ChessBoard board1;
      int8_t numberOfOptions = board1.newMoveOptions(4, 4);
      assert_eq(numberOfOptions, 8);

      board1.moveKnight(6, 3);
      numberOfOptions = board1.newMoveOptions(4, 4);
      assert_eq(numberOfOptions, 7);

      board1.moveKnight(3, 6);
      numberOfOptions = board1.newMoveOptions(4, 4);
      assert_eq(numberOfOptions, 6);
    }
  }
  section("findSmallestIndex") {
    unit_test("findSmallestIndex") {
      ChessBoard board1;
      vector<int8_t> values {
        8,
        5,
        1,
      };
      int8_t smallest = board1.findSmallestIndex(values);
      assert_eq(smallest, 2);
    }
    unit_test("findSmallestIndex") {
      ChessBoard board1;
      vector<int8_t> values {
        8,
        8,
        5,
        8,
        3,
      };
      int8_t smallest = board1.findSmallestIndex(values);
      assert_eq(smallest, 4);
    }
  }
  section("findNextMove") {
    unit_test("findNextMove") {
      ChessBoard board1;
      int8_t numberOfOptions = board1.newMoveOptions(0, 0);
      assert_eq(numberOfOptions, 2);
      assert_eq(board1.findNextMove(0, 0).first, 2);
      assert_eq(board1.findNextMove(0, 0).second, 1);
    }
  }
  summary();
}
