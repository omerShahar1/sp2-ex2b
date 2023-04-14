#include "card.hpp"
#include "player.hpp"
#include "game.hpp"
using namespace std;
using namespace ariel;

Game:: Game(Player& p1, Player& p2) : p1(p1), p2(p2)
{
    this->count_draw = 0; 
    this->count_turn = 0;


        for (int i = 0; i < 26 ; i++)
        {
            this->p1.addCard((rand() % 13) + 2, rand() % 4);
        }

        for (int i = 0; i < 26 ; i++)
        {
            this->p2.addCard((rand() % 13) + 2, rand() % 4);
        }
    

    list<Card> temp = {};
    for (int i = 2; i <= 14 ; i++)
    {

        for(int j=0; j<4; j++)
        {
            temp.push_back(Card(i, j));
        }
    }

    int r = 0;
    while(this->p1.stacksize()<26 && this->p2.stacksize()<26)
    {
        r = rand() % 2;
        if(r==0)
        {
            this->p1.addCard(temp.front().get_card_num(), temp.front().get_card_shape());
            temp.pop_front();
        }
        else
        {
            this->p2.addCard(temp.front().get_card_num(), temp.front().get_card_shape());
            temp.pop_front();
        }
    }


    while (this->p1.stacksize() < 26)
    {
        this->p1.addCard(temp.front().get_card_num(), temp.front().get_card_shape());
        temp.pop_front();
    }

    while (this->p2.stacksize() < 26)
    {
        this->p2.addCard(temp.front().get_card_num(), temp.front().get_card_shape());
        temp.pop_front();
    }
    
    
    // cout << "p1:" + to_string(p1.stacksize()) << endl;
    

    
}

bool Game:: check_game_over()
{
    if(this->p1.stacksize()<=0 || this->p2.stacksize()<=0)
    {
        return true;
    }
    return false;
}

void Game:: playTurn()
{
    if(this->check_game_over())
    {
        throw invalid_argument("The Game has finished.");
        return;
    }

    if (&p1 == &p2) 
    {
        throw invalid_argument("Both of the players are the same player.");
    }

    string str="";
    int count_table=0;
    
    while(!this->check_game_over())
    {
        Card c1(this->p1.showTop().get_card_num(), this->p1.showTop().get_card_shape());  
        this->p1.throwCard();
        str += p1.getName() + " played " + c1.toString() + " ";
        
        Card c2(this->p2.showTop().get_card_num(), this->p2.showTop().get_card_shape());
        this->p2.throwCard();
        str+=p2.getName()+ " played " + c2.toString() + ". ";
        
        count_table+=2;

        if(c1.get_card_num() == c2.get_card_num()) // draw
        {
            str += "Draw. ";
            this->count_draw +=1;
            this->count_turn +=1;
            
            if(!this->check_game_over())
            {
                c1 = Card(this->p1.showTop().get_card_num(), this->p1.showTop().get_card_shape());  
                this->p1.throwCard();
                
                c2 = Card(this->p2.showTop().get_card_num(), this->p2.showTop().get_card_shape());
                this->p2.throwCard();
                
                count_table+=2;
                
            }
            else // if the game finish while a draw the players take the cards equally.
            { 
                this->p1.increase_taken(count_table/2); 
                this->p2.increase_taken(count_table/2);
            }

        }
        else if(c1.get_card_num() > c2.get_card_num())
        {
            this->p1.increase_taken(count_table);
            str += this->p1.getName() + " wins.";
            this->p2.increase_lost();
            this->count_turn +=1;
            count_table=0;
            break;
        }
        else
        { 
            this->p2.increase_taken(count_table);
            str += this->p1.getName() + " wins.";
            this->p1.increase_lost();
            this->count_turn +=1;
            count_table=0;
            break;
        }
    }
    this-> log.push_back(str); // add the turns log to the end of the log list.

}

void Game:: playAll()
{
    while(!this->check_game_over())
    {
        this-> playTurn();
    }
}

void Game:: printLastTurn()
{
    cout << this->log.front() << endl;
}

void Game:: printWiner()
{
    if(this->p1.cardesTaken() > this->p2.cardesTaken())
    {
        cout << this->p1.getName() << endl;
    }
    else if(this->p1.cardesTaken() < this->p2.cardesTaken()) 
    {
        cout << this->p2.getName() << endl;
    }
    else
    {
        cout << "Draw." << endl; // prints draw.
    }
}

void Game:: printLog()
{
    for (auto i : this-> log) 
    {
        cout << i << endl;
    }
}
void Game:: printStats()
{
    cout << ""<< endl;
    cout << "________states______:" << endl;
    cout << "turns: " + to_string(this->count_turn)<< endl;
    cout << "draws: " + to_string(this->count_draw)<< endl;
    
    float rate = (float)this->count_draw / (float)this->count_turn;
    cout << "draw rate: " + to_string((int)(rate*100))+"%\n" << endl;
    
    cout << "player1 stats:" << endl;
    rate = (float)this->count_turn / (float)this->p1.cardesTaken();
    cout << "win rate:" + to_string((int)(rate*100))+"%\n" << endl;
    cout << "cards won:" + to_string(this->p1.cardesTaken())+"%\n" << endl;

    cout << "player2 stats:" << endl;
    rate = (float)this->count_turn / (float)this->p2.cardesTaken();
    cout << "win rate:" + to_string((int)(rate*100))+"%\n" << endl;
    cout << "cards won:" + to_string(this->p2.cardesTaken())+"%\n" << endl;
}