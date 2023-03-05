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
	int right = getX() + SPRITE_WIDTH <= BOARD_WIDTH ? getX() + SPRITE_WIDTH : -1;
	int left = getX() - SPRITE_WIDTH >= 0 ? getX() - SPRITE_WIDTH : -1;
	int up = getY() + SPRITE_HEIGHT <= BOARD_HEIGHT ? getY() + SPRITE_HEIGHT : -1;
	int down = getY() - SPRITE_HEIGHT >= 0 ? getY() - SPRITE_HEIGHT : -1;
	switch (getActorDirection()) {  //Check if there is a fork for each direction
	case 0:
		if (right != -1 && up != -1 && down != -1) {
			if ((!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))) {
				return "urd";
			}
		}
		if (right != -1 && down != -1) {
			if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), down))
				return "rd";
		}
		if (up != -1 && down != -1) {
			if (!getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))
				return "ud";
		}
		if (up != -1 && right != -1) {
			if (!getSW()->wallFound(getX(), up) && !getSW()->wallFound(right, getY()))
				return "ur";
		}
		break;
	case 90:
		if (right != -1 && up != -1 && left != -1) {
			if ((!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up) && !getSW()->wallFound(right, getY()))) {
				return "url";
			}
		}
		if (right != -1 && left != -1) {
			if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(left, getY()))
				return "rl";
		}
		if ( up != -1 && left != -1) {
			if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up))
				return "ul";
		}
		if (right != -1 && up != -1) {
			if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), up))
				return "ur";
		}
		break;
	case 180:
		if (down != -1 && up != -1 && left != -1) {
			if ((!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))) {
				return "uld";
			}
		}
		if ( up != -1 && left != -1) {
			if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), up))
				return "ul";
		}
		if (up != -1 && down != -1) {
			if (!getSW()->wallFound(getX(), up) && !getSW()->wallFound(getX(), down))
				return "ud";
		}
		if (down != -1 && left != -1) {

			if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), down))
				return "ld";
		}
		break;
	case 270:
		if (right != -1 && down != -1 && left != -1) {

			if ((!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), down) && !getSW()->wallFound(right, getY()))) {
				return "lrd";
			}
		}
		if (right != -1 && left != -1) {

			if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(right, getY()))
				return "lr";
		}
		if (right != -1 && down != -1) {
			if (!getSW()->wallFound(right, getY()) && !getSW()->wallFound(getX(), down))
				return "rd";
		}
		if (down != -1 && left != -1) {
			if (!getSW()->wallFound(left, getY()) && !getSW()->wallFound(getX(), down))
				return "ld";
		}
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
	if (turn != ' ') {  //Case if required to turn
		switch (turn) {
		case 'u':
			direction = 90;  //Change direction
			setDirection(0);  //Change direction to left
			break;
		case 'd':
			direction = 270;  //Change direction
			setDirection(0);  //Change direction to left
			break;
		case 'l':
			direction = 180;  //Change direction
			setDirection(180);  //Change direction to left
			break;
		case 'r':
			direction = 0;  //Change direction
			setDirection(0);  //Change direction to left
			break;
		}
		return;
	}
	switch (direction) { 
		case 0:   //Facing right
			if ((getX()%16==0 && getY() % 16 == 0 && sw->wallFound(getX() + SPRITE_WIDTH, getY()) == true)) {  //If a wall was found at that point, 
				if (sw->wallFound(getX(), getY() + SPRITE_HEIGHT) == false) {
					direction = 90;  //Change direction
					setDirection(0);  //Change direction to up
				}
				else if (sw->wallFound(getX(), getY() - SPRITE_HEIGHT) == false) {
					direction = 270;  //Change direction
					setDirection(0);  //Change direction to down

				}
	
			}
			break;
		case 90:  //Facing up
			if ((getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() +SPRITE_HEIGHT) == true)) {  //If a wall was found at that point, 
				if (sw->wallFound(getX() + SPRITE_WIDTH, getY()) == false) {
					direction = 0;  //Change direction
					setDirection(0);  //Change direction to right
				}
				else if (sw->wallFound(getX() - SPRITE_WIDTH, getY()) == false) {
					direction = 180;  //Change direction
					setDirection(180);  //Change direction to left

				}	
			}
			break;
		case 180:  //Facing left
			if ((getX() % 16 == 0 && getY() % 16 == 0 && sw->wallFound(getX() - SPRITE_WIDTH, getY()) == true)) {  //If a wall was found at that point, 
				if (sw->wallFound(getX(), getY() + SPRITE_HEIGHT) == false) {
					direction = 90;  //Change direction
					setDirection(0);  //Change direction to left
				}
				else if (sw->wallFound(getX(), getY() - SPRITE_HEIGHT) == false) {
					direction = 270;  //Change direction
					setDirection(0);  //Change direction to left

				}
			}
			break;
		case 270:   //Facing down
			if ((getY() % 16 == 0 && getX() % 16 == 0 && sw->wallFound(getX(), getY() - SPRITE_HEIGHT) == true)) {  //If a wall was found at that point, 
				if (sw->wallFound(getX() + SPRITE_WIDTH, getY()) == false) {
					direction = 0;  //Change direction
					setDirection(0);  //Change direction to right
				}
				else if (sw->wallFound(getX() - SPRITE_WIDTH, getY()) == false) {
					direction = 180;  //Change direction
					setDirection(180);  //Change direction to left

				}
	
			}
			break;
		
		}
}

bool Actor::landedOnSquare(int x, int y, Avatar* avatar, bool& activation) {
	if (avatar != nullptr) {
		if (avatar->getX() == getX() && avatar->getY() == getY() && avatar->getTicks() == 0) { //If player landed on coin square
			activation = true;
			return true;
		}
	}
	return false;
}

bool Actor::passedSquare(int x, int y, Avatar* avatar, bool& activation) {
	if (avatar != nullptr && !activation) {
		if (avatar->getX() == getX() && avatar->getY() == getY()) { //If player landed on coin 
			activation = true;
			return true;
		}
	}
	return false;
}

void Actor::resetActivation(bool& peachActivation, bool& yoshiActivation) {
	if (getSW()->getPeach()->getX() != getX() || getSW()->getPeach()->getY() != getY())  //Reset once they move off of it
		peachActivation = false;
	if ((getSW()->getYoshi()->getX() != getX() || getSW()->getYoshi()->getY() != getY()))
		yoshiActivation = false;
}
void CoinSquare::doSomething() {  //Manages behavior of square
	if (getStatus()) { //Check if alive
		if(landedOnSquare(getX(), getY(), getSW()->getPeach(), peachActivated)) { //If player landed on coin square
				if (getSW()->boardContents(getX(), getY()) == Board::blue_coin_square) {
					getSW()->getPeach()->setCoins(getSW()->getPeach()->getCoins() + 3);
				}
				else if (getSW()->boardContents(getX(), getY()) == Board::red_coin_square) {
					getSW()->getPeach()->setCoins(getSW()->getPeach()->getCoins() - 3);
					getSW()->playSound(SOUND_TAKE_COIN);
				}

			}
	
		if (landedOnSquare(getX(), getY(), getSW()->getYoshi(), yoshiActivated)) { //If player landed on coin square
				if (getSW()->boardContents(getX(), getY()) == Board::blue_coin_square) {
					getSW()->getYoshi()->setCoins(getSW()->getYoshi()->getCoins() + 3);
					getSW()->playSound(SOUND_GIVE_COIN);
				}
				else if (getSW()->boardContents(getX(), getY()) == Board::red_coin_square) {
					getSW()->getYoshi()->setCoins(getSW()->getYoshi()->getCoins() - 3);
					getSW()->playSound(SOUND_TAKE_COIN);
				}

			}
		resetActivation(peachActivated, yoshiActivated);
		}

	else {  //If not, return
		return;
	}

}
void StarSquare::doSomething() {
	
		if (passedSquare(getX(), getY(), getSW()->getPeach(), peachActivated)) { //If square has not been activated
			if (getSW()->getPeach()->getCoins() < 20) { //If player does not have enough coins to buy star, return
				return;
			}
			else {  //If player has enough coins, buy star

				getSW()->getPeach()->setCoins(getSW()->getPeach()->getCoins() - 20);
				getSW()->getPeach()->setStars(getSW()->getPeach()->getStars() + 1);
				getSW()->playSound(SOUND_GIVE_STAR);
			}
		}
			if (passedSquare(getX(), getY() == getY(), getSW()->getYoshi(), yoshiActivated)) { //If player landed on star square
				if (getSW()->getYoshi()->getCoins() < 20) {  //If player does not have enough coins to buy star, return
					return;
				}
				else {  //If player has enough coins, buy star
					getSW()->getYoshi()->setCoins(getSW()->getYoshi()->getCoins() - 20);
					getSW()->getYoshi()->setStars(getSW()->getYoshi()->getStars() + 1);
					getSW()->playSound(SOUND_GIVE_STAR);
				}
			}
	
			resetActivation(peachActivated, yoshiActivated);
}

void BankSquare::doSomething() {
		if (landedOnSquare(getX(), getY(), getSW()->getPeach(), peachActivated)) { //If player landed on bank square
				getSW()->getPeach()->setCoins(getSW()->getPeach()->getCoins() + getSW()->getBankTotal());  //Give them the bank total and empty it
				getSW()->setBankTotal(0);
				getSW()->playSound(SOUND_WITHDRAW_BANK);
			}

			else if(passedSquare(getX(), getY(), getSW()->getPeach(), peachActivated)){ //If player passed the bank square
				if (getSW()->getPeach()->getCoins() - 5 >= 0) {  //If the player has at least 5 coins
					getSW()->getPeach()->setCoins(getSW()->getPeach()->getCoins() - 5);  //Take 5 of their coins and deposit into bank
					getSW()->setBankTotal(5 + getSW()->getBankTotal());
				}
				else {  //If not, take what they do have and deposit into bank
					getSW()->setBankTotal(getSW()->getPeach()->getCoins() + getSW()->getBankTotal());
					getSW()->getPeach()->setCoins(0);

				}
				getSW()->playSound(SOUND_DEPOSIT_BANK);
			}
		
	
		if (landedOnSquare(getX(), getY(), getSW()->getYoshi(), yoshiActivated)) { //If player landed on bank square
				getSW()->getYoshi()->setCoins(getSW()->getYoshi()->getCoins() + getSW()->getBankTotal());  //Give them the bank total and empty it
				getSW()->setBankTotal(0);
				getSW()->playSound(SOUND_WITHDRAW_BANK);
			}

			else if(passedSquare(getX(), getY(), getSW()->getYoshi(), yoshiActivated)){ //If player passed the bank square
				if (getSW()->getYoshi()->getCoins() - 5 >= 0) {  //If the player has at least 5 coins
					getSW()->getYoshi()->setCoins(getSW()->getYoshi()->getCoins() - 5);  //Take 5 of their coins and deposit into bank
					getSW()->setBankTotal(5 + getSW()->getBankTotal());
				}
				else {  //If not, take what they do have and deposit into bank
					getSW()->setBankTotal(getSW()->getYoshi()->getCoins() + getSW()->getBankTotal());
					getSW()->getYoshi()->setCoins(0);

				}
				getSW()->playSound(SOUND_DEPOSIT_BANK);
			}
		
	
			resetActivation(peachActivated, yoshiActivated);
}

void EventSquare::doSomething() {
	if (landedOnSquare(getX(), getY(), getSW()->getPeach(), peachActivated))
		activateEvent(getSW()->getPeach());

	if (landedOnSquare(getX(), getY(), getSW()->getYoshi(), yoshiActivated))
		activateEvent(getSW()->getYoshi());

		
	
}

void EventSquare::activateEvent(Avatar* avatar) {
	switch (randInt(1, 3)) {
	case 1: //Teleporting
		avatar->teleport();
		getSW()->playSound(SOUND_PLAYER_TELEPORT);
		break;
	case 2:  //Swap positions
		avatar->swapPosition(avatar->getPlayerNum() == 1 ? getSW()->getYoshi() : getSW()->getPeach());
		yoshiActivated = avatar->getPlayerNum() == 1 ? true : yoshiActivated;  //Prevents other avatar from teleporting
		peachActivated = avatar->getPlayerNum() == 2 ? true : peachActivated;  //Prevents other avatar from teleporting
		getSW()->playSound(SOUND_PLAYER_TELEPORT);
		break;
	case 3: //Give vortex
		avatar->setVortex(true);
		getSW()->playSound(SOUND_GIVE_VORTEX);
		break;
	}
}

void Vortex::doSomething() {

}
void Avatar::doSomething() 
	{
		if (waitingToRoll) {   //Check if waiting to roll
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
					cerr << checkFork(getActorDirection()) << endl;
					int tr = getSW()->getAction(playerNum);
					cerr << tr << endl;
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
			cerr << getActorDirection() << endl;
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
	int x = randInt(0,15); //Get random x and y
	int y = randInt(0, 15); //Get random x and y
	while (!isSquare(x, y)) {  //Loop while  (x,y) is not a square
		x = randInt(0,15); //Get random x and y
		y = randInt(0,15);
	}
	moveTo(x, y);  //Move the avatar there
	setActorDirection(-1); //Make direction invalid
}
