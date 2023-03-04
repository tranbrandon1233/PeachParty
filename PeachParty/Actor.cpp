#include "Actor.h"
#include "StudentWorld.h"
#include "GameConstants.h"
#include <iostream>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.
/*
Avatar::~Avatar() {
	while (temp != nullptr) {  //Delete all nodes for coordinates
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool Actor::coordFound(int x, int y) {
	Coords* coord = head;
	while (coord != nullptr) {  //Delete all nodes for coordinates
		coord = coord->next;
		if (coord->x == x && coord->y == y) {
			return true;
		}
	}
	return false;
}
*/
void Actor::moveActor(int dir) {
	switch (dir) {
	case 0:
			moveTo(getX() + 2, getY());
		break;
	case 90:
		moveTo(getX(), getY() + 2);
		break;
	case 180:
		moveTo(getX() - 2, getY());
		break;
	case 270:
		moveTo(getX(), getY() - 2);
		break;

	}
}
void Actor::changeDirection(){  //Change direction of actor
	switch (direction) { 
		case 0:   //Facing right
			if (getX()%16==0 && getY() % 16 == 0 && sw->wallFound(getX() + SPRITE_WIDTH, getY()) == true) {  //If a wall was found at that point, 
				direction = 90;  //Change direction and check again
				setDirection(0);  //Change direction to left
	
			}
			break;
		case 90:  //Facing up
			if (getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() +SPRITE_HEIGHT) == true) {  //If a wall was found at that point, 
			
				setDirection(0);  //Change direction to left
				direction = 270;

	
			}
			break;
		case 180:  //Facing left
			if (getX() % 16 == 0 && getY() % 16 == 0 && sw->wallFound(getX() - SPRITE_WIDTH, getY()) == true) {  //If a wall was found at that point, 
				direction = 90; //Change direction
				setDirection(0);  //Change direction to left

		
			}
			break;
		case 270:   //Facing down
			if (getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() - SPRITE_HEIGHT) == true) {  //If a wall was found at that point, 
				std::cerr << "turn" << std::endl;
				direction = 180;  //Change direction
				setDirection(180);  //Change direction to left
	
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
			/*
			temp->next = new Coords(); //Track coords here
			temp = temp->next;
			temp->x = getX();
			temp->y = getY();
			*/
			moveActor(getDirection());
			ticks_to_move--;  //Decrement ticks to move
			if (!ticks_to_move)  //If ticks to move is zero, set waiting to roll to true
				waitingToRoll = true;
		}
}
