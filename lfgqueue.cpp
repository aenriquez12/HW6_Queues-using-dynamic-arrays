#include "lfgqueue.h"
#include "player.h"


LFGQueue::LFGQueue(){
    players = new Player*[capacity];
    count = 0;
    capacity = 100;  
}

int LFGQueue::size(){
    return count;
}

void LFGQueue::push_player(Player* p){
     if (count == capacity) {
            capacity *= 2;
            Player** newPlayers = new Player*[capacity];
            for (int i = 0; i < count; ++i) {
                newPlayers[i] = players[i];
            }
            delete[] players;
            players = newPlayers;
        }
        players[++count] = p;
}

Player* LFGQueue::front_player(Player::Role r){
    for (int i = 0; i < count; ++i) {
            if (players[i]->role() == r) {
                return players[i];
            }
        }
        return nullptr;
}

void LFGQueue::pop_player(Player::Role r){
    for (int i = 0; i < count; ++i) {
            if (players[i]->role() == r) { 
                for (int j = i; j < count - 1; ++j) {
                    players[j] = players[j + 1];
                }
                --count;
                return;
            }
        }
}

bool LFGQueue::front_group(Player** group)
{
    Player* defender = nullptr;
        Player* hunter = nullptr;
        Player* bard = nullptr;

        for (int i = 0; i < count; ++i) {
            if (!defender && players[i]->role() == Player::Role::Defender) {
                defender = players[i];
            
            }
             else if (!hunter && players[i]->role() == Player::Role::Hunter) {
                hunter = players[i];
            } 
            else if (!bard && players[i]->role() == Player::Role::Bard) {
                bard = players[i];
            }
            if (defender && hunter && bard) {
                group[0] = defender;
                group[1] = hunter;
                group[2] = bard;
                return true;
            }
        }

        group[0] = group[1] = group[2] = nullptr;
        return false;
}

void LFGQueue::pop_group()
{
    Player* group[3];
    if (front_group(group)){
        pop_player(Player::Role::Defender);
        pop_player(Player::Role::Hunter);
        pop_player(Player::Role::Bard);
    }
}