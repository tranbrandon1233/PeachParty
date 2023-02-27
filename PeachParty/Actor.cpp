#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.


void Actor::changeDirection(){  //Change direction of actor
	switch (getDirection()) {  
		case 0:   //Facing right
			if (sw->wallFound(getX() + 2, getY()) == true) {  //If a wall was found at that point, 
				setDirection(90);  //Change direction to up

	
			}
			break;
		case 90:  //Facing up
			if (sw->wallFound(getX(), getY() - 2) == true) {  //If a wall was found at that point, 
				setDirection(180);  //Change direction to left

	
			}
			break;
		case 180:  //Facing left
			if (sw->wallFound(getX() - 2, getY()) == true) {  //If a wall was found at that point, 
				setDirection(270);  //Change direction to up

		
			}
			break;
		case 270:   //Facing down
			if (sw->wallFound(getX(), getY() + 2) == true) {  //If a wall was found at that point, 
				setDirection(0);  //Change direction to up

		
			}
			break;
		
		}
}

void CoinSquare::doSomething() {  //Manages behavior of square
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

void Avatar::doSomething() 
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
		
				if (getDirection() == 0 && getSW()->wallFound(getX() + 1, getY()) == true) {
					changeDirection();
				}
			
				else if (getDirection() == 90 && getSW()->wallFound(getX(), getY()-1) == true) {
					changeDirection();
				}
			
				else if (getDirection() == 180 && getSW()->wallFound(getX() - 1, getY()) == true) {
					changeDirection();
				}
	
				else if (getDirection() == 270 && getSW()->wallFound(getX(), getY()+1) == true) {
					changeDirection();
				}
		
			moveForward(2);
			increaseAnimationNumber();
			animate();
			ticks_to_move--;  //Decrement ticks to move
			if (!ticks_to_move)  //If ticks to move is zero, set waiting to roll to true
				waitingToRoll = true;
		}
}
