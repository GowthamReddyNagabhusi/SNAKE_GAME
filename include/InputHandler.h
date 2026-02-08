#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "GameConfig.h"

class InputHandler {
public:
    static Direction GetDirection();
    static bool IsRestartPressed();
    static bool IsStartPressed();
    static bool IsQuitPressed();
};

#endif // INPUT_HANDLER_H

