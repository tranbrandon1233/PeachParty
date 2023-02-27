#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
#include "GameWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public  GraphObject  //Actor class inheriting from GraphObject
{
	public:
		Actor(int imageID, int startX, int startY, int dir = 0, int depth = 0, double size = 1.0)  //Constructor for Actor class
			: GraphObject(imageID, startX, startY, dir, depth, size), m_alive(true)   //Initialize parameters
		{}
		virtual int doSomething()=0;   //Pure virtual method for doSomething, which will vary for each class
		
		StudentWorld* getSW() const {  //Get StudentWorld pointer
			return sw;
		}
		
		bool getStatus() const{   //Get status of actor
			return m_alive;
		}
	
		bool changeStatus(bool status) {  //Change status of actor
			m_alive = status;
		}
	
		void changeDirection();

	private:
		bool m_alive;
		StudentWorld* sw;


};

class CoinSquare : public Actor {  //Class for CoinSquare inheriting from Actor superclass
	public:
		CoinSquare(int imageID, int startX, int startY) //CoinSquare constructor
			: Actor(imageID, startX, startY, 0, 1)  //Initialize Actor with appropriate parameters

		{

		
		}
		virtual int doSomething();
	private:
};

class Player : public Actor { //Player class
	public:
		Player(int imageID, int startX, int startY)  //Constructor for player
			: Actor(imageID, startX, startY), coins(0), stars(0), vortex(false), ticks_to_move(0), waitingToRoll(false)  //Initialize Actor and private vars
		{}
		
		virtual int doSomething();

	private:
		int playerNum;
		int coins;
		int stars;
		bool vortex;
		int ticks_to_move;
		bool waitingToRoll;
};
#endif // ACTOR_H_
