#ifndef STUDENTWORLD_H
#define STUDENTWORLD_H

#include "GameWorld.h"
#include "Actor.h"
#include "Board.h"
#include <string>
#include <list>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
  virtual int init();
  virtual int move();
  virtual void cleanUp();
  ~StudentWorld() { cleanUp(); };
  const bool wallFound(int x, int y);
  bool overlap(int x, int y, Actor* actor) const;
  Board* getBoard() const { return m_board; }
  void addActor(Actor* actor) { m_actors.push_back(actor); }  //Adds actors to vector
  void addPeach(const int x, const int y) { addActor(new Avatar(this, 1, IID_PEACH, x, y)); }  
  void addYoshi(const int x, const int y) { addActor(new Avatar(this, 2, IID_YOSHI, x, y)); }
  void addRedCoin(const int x, const int y) { addActor(new CoinSquare(this, IID_RED_COIN_SQUARE, x, y)); }
  void addBlueCoin(const int x, const int y) { addActor(new CoinSquare(this, IID_BLUE_COIN_SQUARE, x, y)); }

  
private:
	std::list<Actor*> m_actors;
	Board* m_board;
};

#endif // STUDENTWORLD_H_
