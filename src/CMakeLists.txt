add_library(LegendsOfCodeSolution
    GameController.cpp
    Logger.cpp)
target_include_directories(LegendsOfCodeSolution PUBLIC ../include)
add_executable(mainExec main.cpp)
target_link_libraries(mainExec LegendsOfCodeSolution)
