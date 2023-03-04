#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
#include "GameWorld.h"

class StudentWorld;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public  GraphObject  //Actor class inheriting from GraphObject
{
	public:
		Actor(StudentWorld *sw, const int imageID, int startX, int startY, int dir = 0, int depth = 0, double size = 1.0)  //Constructor for Actor class
			: GraphObject(imageID, startX, startY, dir, depth, size), m_alive(true), sw(sw), direction(dir)   //Initialize parameters
		{}
		virtual void doSomething()=0;   //Pure virtual method for doSomething, which will vary for each class
		
		StudentWorld *getSW() const {  //Get StudentWorld pointer
			return sw;
		}
		
		bool getStatus() const{   //Get status of actor
			return m_alive;
		}
	
		bool changeStatus(bool status) {  //Change status of actor
			m_alive = status;
		}
	
		void changeDirection();
		int getDirection() { return direction; }
		void moveActor(int dir);

		virtual ~Actor(){}

	private:
		bool m_alive;
		int direction;
		StudentWorld* sw;


};



class Avatar : public Actor { //Player class
	public:
		Avatar(StudentWorld* sw, int playerNum, int startX, int startY)  //Constructor for player
			: Actor(sw, playerNum==1 ? IID_PEACH : IID_YOSHI, startX, startY), coins(0), stars(0), vortex(false), ticks_to_move(0), waitingToRoll(false), playerNum(playerNum)  //Initialize Actor and private vars
		{}
		
		virtual void doSomething();
		void setCoins(int num) { coins = num; }  //Set coins
		int getCoins() const { return coins; }  //Set coins
		void setDirection(int dir) {}


	private:
		int playerNum;
		int coins;
		int stars;
		bool vortex;
		int ticks_to_move;
		bool waitingToRoll;
};

class CoinSquare : public Actor {  //Class for CoinSquare inheriting from Actor superclass
	public:
		CoinSquare(StudentWorld* sw, char type, int startX, int startY) //CoinSquare constructor
			: Actor(sw, type=='b' ? IID_BLUE_COIN_SQUARE : IID_RED_COIN_SQUARE, startX, startY, 0, 1), m_avatar()  //Initialize Actor with appropriate parameters

		{


		}
		virtual void doSomething();
private:
	Avatar* m_avatar;
};

class Vortex : public Actor {
	public:
		Vortex(StudentWorld* sw, int startX, int startY) //Vortex constructor
			: Actor(sw, IID_VORTEX, startX, startY, 0, 1)  //Initialize Actor with appropriate parameters

		{}
};

#endif // ACTOR_H
