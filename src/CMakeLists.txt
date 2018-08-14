add_library(LegendsOfCodeSolution
    CardDeck.cpp
    Decision.cpp
    GameController.cpp
    Logger.cpp
    Player.cpp)
target_include_directories(LegendsOfCodeSolution PUBLIC ../include)
add_executable(mainExec main.cpp)
target_link_libraries(mainExec LegendsOfCodeSolution)
