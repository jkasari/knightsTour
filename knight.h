#ifndef knight_h
#define knight_h
#include <utility>
#include <vector>

using Square = std::pair<int8_t, int8_t>;

class Knight {

 public:
  Knight(int8_t, int8_t);
  /**
   * This gives you a vector of all the possible new locations for the
   * knight. This function only cares about staying on the board. It has
   * no idea where the knight as been previously.
   */
  std::vector<Square> potentialMoves();

 private:
  static bool isOnBoard(int8_t row, int8_t col);
  int8_t row;
  int8_t col;

};

#endif // knight_h
