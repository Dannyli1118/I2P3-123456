#include <cstdlib>

#include "../state/state.hpp"
#include "./playerAI.hpp"

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move PlayerAI::get_move(State *state, int depth){
    if(!state->legal_actions.size()){
        state->get_legal_actions();
    }

    Move max_value_move;
    int max_value = -1000;

    for(auto it: state->legal_actions){
        int tmp_value = minimax(state->next_state(it), depth-1, 0, state->player);
        if(tmp_value>max_value){
            max_value = tmp_value;
            max_value_move = it;
        }
        //printf("%d\n", tmp_value);
    }
    return max_value_move;
}


int minimax(State *state ,int dep, int player, int init_player){
    
    if(state->player==init_player && state->game_state == WIN){
        return 10000;
    }
    if(state->player!=init_player && state->game_state == WIN){
        return -10000;
    }
    
    if(!state->legal_actions.size()){
        state->get_legal_actions();
    }

    if(dep==0 || state->legal_actions.empty()){
        return state->evaluate(init_player);
    }

    if(player==1){
        int tmp_value = -100000;
        for(auto it:state->legal_actions){
            tmp_value = std::max(tmp_value,minimax(state->next_state(it), dep-1, 0, init_player));
        }
        return tmp_value;
    }  
    else{
        int tmp_value = 100000;
        for(auto it:state->legal_actions){
            tmp_value = std::min(tmp_value,minimax(state->next_state(it), dep-1, 1, init_player));
        }
        return tmp_value;
    }
}

/*
./build/main ./build/player_random ./build/player_palyerAI
cd /mnt/c/Users/user/OneDrive/桌面/code/I2P3-123456
*/