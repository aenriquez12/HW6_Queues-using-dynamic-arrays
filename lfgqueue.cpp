#include "lfgqueue.h"


LFGQueue::LFGQueue(){
    player = new* player[100];
    count = 0;
    capacity = 100;
}

int LFGQueue::size(){
    return count;
}

void LFGQueue::push_player(Player* p){
    if(count == capacity){
        count *= 2;
        Player** newPTR = new Player*[count];
        for(int i = 0 ; i < count; ++i){
            newPTR[i] = players[i];

        }
        delete[] playerd;
        players = newPTR;
    }
    player[count] = p;
    ++count;

}

Player* LFGQueue::front_player(Player::Role r){
    for(int i = 0; i < count; ++i ){
        if(player[i]->role() == r ){
            return player[i];
        }
    }
    return nullptr;
}

void LFGQueue::pop_player(Player::Role r)
{
    for(int i = 0; i < count; ++i)
    {
        if(player[i]->role() == r)
        {
            for(int j = i; j < count -1; ++j)
            {
                player[j] = player[count+1];
            }
            --count;
            return;
        }
    }
}

bool LFGQueue::front_group(Player** group){

}

void LFGQueue::pop_group(){

}