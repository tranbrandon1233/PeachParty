#include "Actor.h"
#include "StudentWorld.h"
#include "GameConstants.h"
#include <iostream>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.


void Actor::moveActor(int dir) {
	switch (dir) {
	case 0:
		moveTo(getX() + 2, getY());
		break;
	case 90:
		moveTo(getX(), getY()-2);
		break;
	case 180:
		moveTo(getX()-2, getY());
		break;
	case 270:
		moveTo(getX() + 2, getY());
		break;

	}
}
void Actor::changeDirection(){  //Change direction of actor
	switch (direction) { 
		case 0:   //Facing right
			if (getX()%16==0 && getY() % 16 == 0 && sw->wallFound(getX() + SPRITE_WIDTH, getY()) == true) {  //If a wall was found at that point, 
				direction = 90;  //Change direction to up
	
			}
			break;
		case 90:  //Facing up
			if (getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() +SPRITE_HEIGHT) == true) {  //If a wall was found at that point, 
			
				setDirection(180);  //Change direction to left
				direction = 180;

	
			}
			break;
		case 180:  //Facing left
			if (getX() % 16 == 0 && getY() % 16 == 0 && sw->wallFound(getX() - SPRITE_WIDTH, getY()) == true) {  //If a wall was found at that point, 
				direction = 270;
		
			}
			break;
		case 270:   //Facing down
			if (getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() - SPRITE_HEIGHT) == true) {  //If a wall was found at that point, 
				direction = 0;  //Change direction to right
	
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
				changeDirection();
				ticks_to_move = 8 * randInt(1, 10);
				waitingToRoll = false;
			}
			else if (getSW()->getAction(playerNum) == ACTION_FIRE) {
				
			}

			else {
				return;
			}

		}
		else {
		
			changeDirection();
			moveActor(getDirection());
			ticks_to_move--;  //Decrement ticks to move
			if (!ticks_to_move)  //If ticks to move is zero, set waiting to roll to true
				waitingToRoll = true;
		}
}
