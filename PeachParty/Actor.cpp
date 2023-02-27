#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.

void Actor::changeDirection(){  //Change direction of actor
	switch (getDirection()) {  
		case 0:   //Facing right
			if (sw->wallFound(getX() + 2, getY()) == true) {  //If a wall was found at that point, 
				setDirection(90);  //Change direction to up

				if (sw->wallFound(getX(), getY() - 2) == true) {  //If a wall was found at the new direction, 
					changeDirection(); //Change direction again
				}
			}
			break;
		case 90:  //Facing up
			if (sw->wallFound(getX(), getY() - 2) == true) {  //If a wall was found at that point, 
				setDirection(180);  //Change direction to left

				if (sw->wallFound(getX() - 2, getY()) == true) {  //If a wall was found at the new direction, 
					changeDirection(); //Change direction again
				}
			}
			break;
		case 180:  //Facing left
			if (sw->wallFound(getX() - 2, getY()) == true) {  //If a wall was found at that point, 
				setDirection(270);  //Change direction to up

				if (sw->wallFound(getX(), getY() + 2) == true) {  //If a wall was found at the new direction,  
					changeDirection(); //Change direction again
				}
			}
			break;
		case 270:   //Facing down
			if (sw->wallFound(getX(), getY() + 2) == true) {  //If a wall was found at that point, 
				setDirection(0);  //Change direction to up

				if (sw->wallFound(getX() + 2, getY()) == true) {  //If a wall was found at the new direction, 
					changeDirection(); //Change direction again
				}
			}
			break;

		}
}

int CoinSquare::doSomething() {  //Manages behavior of square
	if (getStatus()) { //Check if alive
		if (getSW()->getBoard()->getContentsOf(getX(), getY()) == getSW()->getBoard()->Board::blue_coin_square)
			m_avatar->setCoins(m_avatar->getCoins() + 3);
		else if(getSW()->getBoard()->getContentsOf(getX(), getY()) == getSW()->getBoard()->Board::red_coin_square)
			m_avatar->setCoins(m_avatar->getCoins() - 3);
	}
	else {  //If not, return
		return;
	}

}

int Avatar::doSomething() {
	{
		if (waitingToRoll) {   //Check if not waiting to roll
			if (getSW()->getAction(playerNum) == ACTION_ROLL) {
				ticks_to_move = 8 * randInt(1, 10);
				waitingToRoll = false;
			}
			else {
				return;
			}

		}
		else {
			changeDirection();  //Change directions if needed
			moveForward(2);  //Move forward 2 pixels
			ticks_to_move--;  //Decrement ticks to move
			if (!ticks_to_move)  //If ticks to move is zero, set waiting to roll to true
				waitingToRoll = true;
		}
}
