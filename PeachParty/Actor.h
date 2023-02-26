#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
#include "GameWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public  GraphObject  //Actor class inheriting from GraphObject
{
public:
	Actor(int imageID, int startX, int startY, int actorType = 1, int dir = 0, int depth = 0, double size = 1.0)  //Constructor for Actor class
		: GraphObject(imageID, startX, startY, dir, depth, size), m_alive(true), m_actor(actorType)   //Initialize GraphObject with parameters
	{}
	virtual int doSomething()=0;   //Pure virtual method for doSomething, whcih will vary for each class
	bool getStatus() {
		return m_alive;
	}
	
	bool changeStatus(bool status) {
		m_alive = status;
	}
	int getActor() {
		return m_actor;
	}

private:
	bool m_alive;
	int m_actor;

};

class CoinSquare : public Actor {  //Class for CoinSquare inheriting from Actor superclass
	public:
		CoinSquare(char type, int imageID, int startX, int startY) //CoinSquare constructor
			: Actor(imageID, startX, startY, type, 0, 1)  //Initialize Actor with appropriate parameters

		{

		
		}
		virtual int doSomething() {  //Manages behavior of square
			if (getStatus()) { //Check if alive

			} 
			else {  //If not, return
				return;
			}

		}
	private:
		char blockType;
};

class Player : public Actor { //Player class
	public:
		Player(int imageID, int type, int player, int startX, int startY)  //Constructor for player
			: Actor(imageID, startX, startY, type), coins(0), stars(0), vortex(false), ticks_to_move(0), rollState(false)   //Initialize Actor and private vars
		{}
		int doSomething() { 
			if (!rollState) {   //Check if not waiting to roll
				if (gw->getAction(getActor())) {

				}
			}
			else {

			}
		}
	private:
		int coins;
		int stars;
		bool vortex;
		int ticks_to_move;
		bool rollState;
		GameWorld* gw;
};
#endif // ACTOR_H_
