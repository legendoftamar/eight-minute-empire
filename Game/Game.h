//
// Created by Tamar M on 2019-10-29.
//

#ifndef EIGHT_MINUTE_EMPIRE_GAME_H
#define EIGHT_MINUTE_EMPIRE_GAME_H

#include "../Maps/Map.h"
#include "../Maps/MapLoader.h"
#include "../Players/Player.h"

using namespace std;

class Game {
public:
    vector<Player*> *players;
    Map* map;
    Deck* deck;
    Hand* hand;
    Player* startingPlayer;
    int *maxCardCount;

    Game();
    int initialize();
    int startup();
    void takeTurn(Player* player);
    void mainGameLoop();
};


#endif //EIGHT_MINUTE_EMPIRE_GAME_H
