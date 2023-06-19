#pragma once
#include "../state/state.hpp"
#include <set>

/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */

class PlayerAI{
public:
  static Move get_move(State *state, int depth);
};

int minimax(State *state ,int dep, int player);