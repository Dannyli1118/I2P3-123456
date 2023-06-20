#pragma once
#include "../state/state.hpp"
/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */

class Submission{
public:
  static Move get_move(State *state, int depth);
};

int sub(State *state ,int dep, int alpha, int beta,  int player, int init_player);