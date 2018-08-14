#pragma once

/*
 * @author Pawel Ptasznik
 */

#include <iostream>
#include <string>
#include <vector>
#include "CardDeck.hpp"
#include "Logger.hpp"
#include "Player.hpp"

class GameController {
public:
    GameController() = delete;
    GameController(std::istream& input, std::ostream& output);
    bool executeIteration();
private:
    void readInputStream();
    std::string createPickCommand(int num);
    std::istream& input_;
    std::ostream& output_;
    Logger logger_;
    Player hero_;
    Player opponent_;
    CardDeck deck_;
    std::vector<Card> draftPhaseCards_;
    int roundNumber_;
};
