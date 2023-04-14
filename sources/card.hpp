#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    class Card
    {
        private:
            int shape; // shape of the card
            int num; //  card number

        public:
            Card(int, int); // cretae a card with number and shape
            int get_card_num() const; // return number of card
            int get_card_shape() const; // return shape of the card
            string toString() const; // return string representation of the card
    };
}