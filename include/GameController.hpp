#pragma once

/*
 * @author Pawel Ptasznik
 */

#include <iostream>
#include "Logger.hpp"

class GameController {
public:
    GameController() = delete;
    GameController(std::istream& input, std::ostream& output);
    bool executeIteration();
private:
    std::istream& input_;
    std::ostream& output_;
    Logger logger_;
};
