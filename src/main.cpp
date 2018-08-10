#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "GameController.hpp"

int main() {
    GameController controller(std::cin, std::cout);
    while(true) {
        controller.executeIteration();
    }
    return 0;
}
