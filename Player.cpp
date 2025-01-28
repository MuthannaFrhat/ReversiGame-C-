
#include "Player.h"


Player::Player(char _name) {

   points=0;
}

void Player::AddPoints(int num) {
points+=num;
}

int Player::GetPoints() const {
    return points;
}



