#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.

void Actor::changeDirection(){  //Change direction of actor
	switch (getDirection()) {  
		case 0:   //Facing right
			if (sw->wallFound(getX() + 1, getY()) == true) {  //If a wall was found at that point, 
				setDirection(90);  //Change direction to up

				if (sw->wallFound(getX(), getY() - 1) == true) {  //If a wall was found at the new direction, 
					changeDirection(); //Change direction again
				}
			}
			break;
		case 90:  //Facing up
			if (sw->wallFound(getX(), getY() - 1) == true) {  //If a wall was found at that point, 
				setDirection(180);  //Change direction to left

				if (sw->wallFound(getX() - 1, getY()) == true) {  //If a wall was found at the new direction, 
					changeDirection(); //Change direction again
				}
			}
			break;
		case 180:  //Facing left
			if (sw->wallFound(getX() - 1, getY()) == true) {  //If a wall was found at that point, 
				setDirection(270);  //Change direction to up

				if (sw->wallFound(getX(), getY() + 1) == true) {  //If a wall was found at the new direction,  
					changeDirection(); //Change direction again
				}
			}
			break;
		case 270:   //Facing down
			if (sw->wallFound(getX(), getY() + 1) == true) {  //If a wall was found at that point, 
				setDirection(0);  //Change direction to up

				if (sw->wallFound(getX() + 1, getY()) == true) {  //If a wall was found at the new direction, 
					changeDirection(); //Change direction again
				}
			}
			break;

		}
}

int CoinSquare::doSomething() {  //Manages behavior of square
	if (getStatus()) { //Check if alive

	}
	else {  //If not, return
		return;
	}

}

int Player::doSomething() {
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
		else { //CHECK TO SEE IF ACTOR CAN MOVE HERE LATER
			changeDirection();  
		}
}
