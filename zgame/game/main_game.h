#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include "../system/render_system.h"
#include "../system/move_system.h"
#include "../system/input_move_system.h"
#include "../system/bounce_system.h"

class MainGame {
public:
    void init();
    void update();
};

#endif //MAIN_GAME_H