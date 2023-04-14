#include "card.hpp"
using namespace std;
using namespace ariel;

Card:: Card(int num, int shape)
{
    this->num = num;
    this->shape = shape;
}

int Card:: get_card_num() const
{
    return this->num;
}

int Card:: get_card_shape() const
{
    return this->shape;
}

string Card:: toString() const
{
    string num = "";
    string shape = "";
    
    if(this->num == 11)
    {
        num = "Jack";
    }
    else if(this->num == 11)
    {
        num = "Queen";
    }
    else if(this->num == 11)
    {
        num = "King";
    }
    else if(this->num == 14)
    {
        num = "Ace";
    }
    else
    {
        num = to_string(this->num);
    }


    if(this->shape == 0)
    {
        shape = "Spades";
    }
    else if(this->shape == 1)
    {
        shape = "Hearts";
    }
    else if(this->shape == 2)
    {
        shape = "Diamonds";
    }
    else if(this->shape == 3)
    {
        shape = "Clubs";
    }
    return num + " of " + shape;
}