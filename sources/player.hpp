#pragma once
#include <iostream>
#include <list>
#include <string>
#include "card.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
        private:
            string name; // player name
            int taken, lost; // how many cards the player won and how many lost
            list<Card> cards{}; // save player cards
            int count_cards;

        public:
            Player(); // create new random player
            Player(string); // create new player
            string getName() const; // return player name
            int stacksize() const; // return current size of cards
            int cardesTaken() const; // return how many cards the player won
            Card showTop(); // return pointer to the first card
            void throwCard(); // throw a card from the hand.
            
            void increase_lost(); // increase lost valuse by 1
            void increase_taken(int); // increase value of the taken
            void addCard(int, int);
    };
}