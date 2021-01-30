#include <iostream>
#include <vector>
#include <utility>
#include "knight.h"
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
      assert_eq(expectedMoves.size(), actualMoves.size())
      for(int i = 0; i < expectedMoves.size(); i++) {
        assert_eq(expectedMoves[i].first, actualMoves[i].first);
        assert_eq(expectedMoves[i].second, actualMoves[i].second);
      }
    }
    unit_test("potentialMoves") {
      Knight aurther(4, 4);
      vector<Square> expectedMoves{
        Square(2, 5), //up2, right1
        Square(2, 3), //up2, left1
        Square(6, 5), //down2, right1
        Square(6, 3), //down2, left1
        Square(3, 6), //up1, right2
        Square(5, 6), //up1, left2
        Square(3, 2), //down1, right2
        Square(5, 2), //down1, left2
      };
      vector<Square> actualMoves = aurther.potentialMoves();
      assert_eq(expectedMoves.size(), actualMoves.size())
      for(int i = 0; i < expectedMoves.size(); i++) {
        assert_eq(expectedMoves[i].first, actualMoves[i].first);
        assert_eq(expectedMoves[i].second, actualMoves[i].second);
      }
    }
    unit_test("potentialMoves") {
      Knight aurther(4, 6);
      vector<Square> expectedMoves{
        Square(2, 7), //up2, right1
        Square(2, 5), //up2, left1
        Square(6, 7), //down2, right1
        Square(6, 5), //down2, left1
        Square(3, 4), //up1, left2
        Square(5, 4), //down1, left2
      };
      vector<Square> actualMoves = aurther.potentialMoves();
      assert_eq(expectedMoves.size(), actualMoves.size())
      for(int i = 0; i < expectedMoves.size(); i++) {
        assert_eq(expectedMoves[i].first, actualMoves[i].first);
        assert_eq(expectedMoves[i].second, actualMoves[i].second);
      }
    }
  }

  summary();
}

