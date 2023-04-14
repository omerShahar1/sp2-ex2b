#include "card.hpp"
#include "player.hpp"
#include <string>
#include <list>
using namespace std;
using namespace ariel;

Player:: Player()
{
    this->name = "player"; 
    this->taken = 0; 
    this->lost = 0;
}

Player:: Player(string str)
{ 
    this->name = str; 
    this->taken = 0; 
    this->lost = 0; 
}

string Player:: getName() const
{ 
    return this->name;
}

int Player:: stacksize() const
{ 
    // cout << this->name + "   " + to_string(this->cards.size()) << endl;
    return this->cards.size();
}

int Player:: cardesTaken() const
{
    return this->taken;
}

Card Player:: showTop()
{
    return this->cards.front();
}

void Player:: throwCard()
{
    this->cards.pop_front();
}

void Player:: increase_lost()
{
    this->lost += 1;
}

void Player:: increase_taken(int num)
{ 
    this-> taken += num;
}

void Player:: addCard(int num, int shape)
{
    this->cards.push_back(Card(num, shape));
}

int Player:: get_lost()
{
    return this->lost;
}