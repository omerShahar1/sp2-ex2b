#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <string.h>
#include <stdexcept>
#include <iostream>
using namespace ariel;
using namespace std;

TEST_CASE("")
{
    CHECK_NOTHROW(Player p1("p1"));
    CHECK_NOTHROW(Player p1("p2"));
    CHECK_NOTHROW(Game game(Player& p1, Player& p2));
    
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p2.stacksize());
    CHECK_NOTHROW(p1.cardesTaken());
    CHECK_NOTHROW(p2.cardesTaken());

    Player p1("player1");
    Player p2("player2");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        CHECK_NOTHROW(game.playTurn());
    }
    
    CHECK_NOTHROW(Player p11("11"));
    CHECK_NOTHROW(Player p12("12"));
    CHECK_NOTHROW(Player p13("13"));
    CHECK_NOTHROW(Player p14("14"));
    CHECK_NOTHROW(Player p15("15"));
    CHECK_NOTHROW(Player p16("16"));
    CHECK_NOTHROW(Player p17("17"));
    CHECK_NOTHROW(Player p18("18"));
    CHECK_NOTHROW(Player p19("19"));
    CHECK_NOTHROW(Player p20("20"));
}