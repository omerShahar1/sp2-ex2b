#pragma once
#include <iostream>
#include "player.hpp"
#include <list>
#include <string>
using namespace std;

namespace ariel
{
    class Game
    {
        private:
        Player& p1; // first player
        Player& p2; // second player
        list<string> log{}; //save game log.
        int count_draw; // count draws
        int count_turn; // count turns

        public:
        Game(Player& player1, Player& player2); //constructor with 2 parameters
        bool check_game_over(); // checks if the game has finished.

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        
       
    };
}