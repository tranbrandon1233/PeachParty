#include "Actor.h"
#include "StudentWorld.h"
#include "GameConstants.h"
#include <iostream>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.
using namespace std;
/*
Actor::~Actor() {
	if (peachHead == nullptr && yoshiHead == nullptr) {
		return;
	}
	while (peachHead != nullptr) {  //Delete all nodes for Peach's coordinates
		peachTemp = peachHead;
		if(peachTemp != nullptr)
			peachHead = peachTemp->next;
		delete peachTemp;
	}
	while (yoshiHead != nullptr) {  //Delete all nodes for Yoshi's coordinates
		yoshiTemp = yoshiHead;
		if (yoshiTemp != nullptr)
			yoshiHead = yoshiTemp->next;
		delete yoshiTemp;
	}
	delete peachHead; //Delete last nodes
	delete yoshiHead;
}

bool Actor::coordFound(int x, int y) const {
	Coords* coord;
	if (type == "Peach") {
		coord = peachHead;
	}
	else if (type == "Yoshi") {
		coord = yoshiHead;
	}
	while (coord != nullptr) {  //Delete all nodes for coordinates
		if (coord->x == x && coord->y == y) {
			return true;
		}
		coord = coord->next;
	}
	return false;
}
*/

bool Actor::isSquare(int x, int y) { //Returns true if actor is square, false otherwise
	return getSW()->boardContents(x, y) == Board::bank_square || getSW()->boardContents(x, y) == Board::blue_coin_square || getSW()->boardContents(x, y) == Board::down_dir_square || getSW()->boardContents(x, y) == Board::event_square || getSW()->boardContents(x, y) == Board::left_dir_square || getSW()->boardContents(x, y) == Board::red_coin_square || getSW()->boardContents(x, y) == Board::right_dir_square || getSW()->boardContents(x, y) == Board::star_square || getSW()->boardContents(x, y) == Board::up_dir_square;
}
std::string Actor::checkFork(int dir) const {
	int right = getX() + SPRITE_WIDTH;
	int left = getX() - SPRITE_WIDTH;
	int up = getY() + SPRITE_HEIGHT;
	int down = getY() - SPRITE_HEIGHT;
	switch (getActorDirection()) {  //Check if there is a fork for each direction
	case 0:
		if ((!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))) {
			return "urd";
		}
		else if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), down))
			return "rd";
		else if (!getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))
			return "ud";
		else if (!getSW()->wallFound(getX(), up) && !getSW()->wallFound(right, getY()))
			return "ur";
		break;
	case 90:
		if ((!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up) && !getSW()->wallFound(right, getY()))) {
			return "url";
		}
		else if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(left, getY()))
			return "rl";
		else if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up))
			return "ul";
		else if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), up))
			return "ur";
		break;
	case 180:
		if ((!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))) {
			return "uld";
		}
		else if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up))
			return "ul";
		else if (!getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))
			return "ud";
		else if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), down))
			return "ld";
		break;
	case 270:
		if ((!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), down) && !getSW()->wallFound(right, getY()))) {
			return "lrd";
		}
		else if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(right, getY()))
			return "lr";
		else if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), down))
			return "rd";
		else if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), down))
			return "ld";
		break;
	}
	return "";  //Return false if not found
}
void Actor::moveActor(int dir) {
	switch (dir) {
	case 0:
	//	if (!coordFound(getX() + 2, getY()))  //If coordinates have not been passed before, move there
			moveTo(getX() + 2, getY());
		
		break;
	case 90:
		//if (!coordFound(getX(), getY()+2))
			moveTo(getX(), getY() + 2);
	

		break;
	case 180:
	//	if (!coordFound(getX() - 2, getY()))
			moveTo(getX() - 2, getY());
	

		break;
	case 270:
	//	if (!coordFound(getX(), getY() - 2))
		moveTo(getX(), getY() - 2);
		break;

	}
}
void Actor::changeDirection(char turn) {  //Change direction of actor
	cerr << getX()/SPRITE_WIDTH << " " << (getY() - SPRITE_HEIGHT) / SPRITE_HEIGHT << endl;
	switch (direction) { 
		case 0:   //Facing right
			if ((getX()%16==0 && getY() % 16 == 0 && sw->wallFound(getX() + SPRITE_WIDTH, getY()) == true) || turn == 'u') {  //If a wall was found at that point, 
				direction = 90;  //Change direction and check again
				setDirection(0);  //Change direction to left
	
			}
			break;
		case 90:  //Facing up
			if ((getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() +SPRITE_HEIGHT) == true) || turn == 'd') {  //If a wall was found at that point, 
			
				setDirection(0);  //Change direction to left
				direction = 270;

	
			}
			break;
		case 180:  //Facing left
			if ((getX() % 16 == 0 && getY() % 16 == 0 && sw->wallFound(getX() - SPRITE_WIDTH, getY()) == true) || turn == 'r') {  //If a wall was found at that point, 
				direction = 0; //Change direction
				setDirection(0);  //Change direction to left

		
			}
			break;
		case 270:   //Facing down
			if ((getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() - SPRITE_HEIGHT) == true) || turn == 'l') {  //If a wall was found at that point, 
				direction = 180;  //Change direction
				setDirection(180);  //Change direction to left
	
			}
			break;
		
		}
}

void CoinSquare::doSomething() {  //Manages behavior of square
	if (getStatus()) { //Check if alive
		if (getSW()->boardContents(getX(), getY()) == Board::blue_coin_square)
			m_avatar->setCoins( m_avatar->getCoins()+3);
		else if(getSW()->boardContents(getX(), getY()) == Board::red_coin_square)
			m_avatar->setCoins(m_avatar->getCoins() - 3);
	}
	else {  //If not, return
		return;
	}

}

void DirectionalSquare::doSomething() {}
void Vortex::doSomething() {

}
void Avatar::doSomething() 
	{
		if (waitingToRoll) {   //Check if not waiting to roll
			if (getSW()->getAction(playerNum) == ACTION_ROLL) {
				changeDirection();  //Change direction if needed
				ticks_to_move = 8 * randInt(1, 10);  //Set ticks to move
				waitingToRoll = false;  //No longer waiting to roll
			}
			else if (getSW()->getAction(playerNum) == ACTION_FIRE && vortex) {  //If firing and has a vortex
				switch (getDirection()) {  //Create vortex based on direction
				case 0:
					getSW()->addVortex(getX()+SPRITE_WIDTH, getY());
					break;
				case 90:
					getSW()->addVortex(getX(), getY() + SPRITE_HEIGHT);
					break;
				case 180:
					getSW()->addVortex(getX() - SPRITE_WIDTH, getY());
					break;
				case 270:
					getSW()->addVortex(getX(), getY() - SPRITE_HEIGHT);
					break;
				}
				getSW()->playSound(SOUND_PLAYER_FIRE);
				vortex = false;
			}

			else {
				return;
			}

		}
		else {
	
			if (getSW()->boardContents(getX(), getY()) == Board::down_dir_square) { //If on top of a dir square
				changeDirection('d');
			}
			else if (getSW()->boardContents(getX(), getY()) == Board::up_dir_square) {
				changeDirection('u');
			}
			else if (getSW()->boardContents(getX(), getY()) == Board::left_dir_square) {
				changeDirection('l');
			}
			else if (getSW()->boardContents(getX(), getY()) == Board::right_dir_square) {
				changeDirection('r');
			}
			else if (checkFork(getActorDirection()) != "") { //If there is a fork, change direction based on user input
				if (getSW()->getAction(playerNum) == ACTION_LEFT && checkFork(getActorDirection()).find("l") != std::string::npos) {
					changeDirection('l');
				}
				else if (getSW()->getAction(playerNum) == ACTION_RIGHT && checkFork(getActorDirection()).find("r") != std::string::npos) {
					changeDirection('r');
				}
				else if (getSW()->getAction(playerNum) == ACTION_DOWN && checkFork(getActorDirection()).find("d") != std::string::npos) {
					changeDirection('d');
				}
				else if (getSW()->getAction(playerNum) == ACTION_UP && checkFork(getActorDirection()).find("u") != std::string::npos) {
					changeDirection('u');
				}
				else {
					return;
				}
			}
			/*
			switch (playerNum) {
			case 1:
				getPeachTemp()->next = new Coords(); //Track Peach's coords here
				setPeachTemp(getPeachTemp()->next);
				getPeachTemp()->x = getX();
				getPeachTemp()->y = getY();
				break;
			case 2:
				getYoshiTemp()->next = new Coords(); //Track Yoshi's coords here
				setYoshiTemp(getYoshiTemp()->next);
				getYoshiTemp()->x = getX();
				getYoshiTemp()->y = getY();
				break;
			}
			*/
			if (getSW()->boardContents(getX(), getY()) == Board::down_dir_square) {
				changeDirection('d');
			}
			changeDirection();
			moveActor(getDirection());
			ticks_to_move--;  //Decrement ticks to move
			if (!ticks_to_move)  //If ticks to move is zero, set waiting to roll to true
				waitingToRoll = true;
		}
}

void Avatar::swapCoins(Avatar* avatar) {   //Change coins
	int tempCoins = coins;
	coins = avatar->getCoins();
	avatar->setCoins(tempCoins);
}
void Avatar::swapStars(Avatar* avatar) {  //Change stars
	int tempStars = stars;
	stars = avatar->getStars();
	avatar->setStars(tempStars);
}
void Avatar::swapPosition(Avatar* avatar) {
	int tempTicks = ticks_to_move; //Swap ticks
	ticks_to_move = avatar->getTicks();
	avatar->setTicks(tempTicks);

	bool tempRoll = waitingToRoll; //Swap roll states
	waitingToRoll = avatar->getRollState();
	avatar->setRollState(tempRoll);

	int tempDir = getActorDirection(); //Swap directions
	setActorDirection(avatar->getActorDirection());
	avatar->setActorDirection(tempDir);

	int tempSpriteDir = getDirection(); //Swap sprite directions
	setDirection(avatar->getDirection());
	avatar->setDirection(tempSpriteDir);
}



void Avatar::teleport() {
	int x = rand() % 15; //Get random x and y
	int y = rand() % 15;
	while (!isSquare(x, y)) {  //Loop while  (x,y) is not a square
		x = rand() % 15; //Get random x and y
		y = rand() % 15;
	}
	moveTo(x, y);  //Move the avatar there
	setActorDirection(-1); //Make direction invalid
}
