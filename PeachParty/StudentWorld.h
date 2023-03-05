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
  Avatar* getPeach() { return m_peach; }
  Avatar* getYoshi() { return m_yoshi; }
  void addActor(Actor* actor) {
	  m_actors.push_back(actor);
  }
  void addPeach(const int x, const int y) { 
	  m_yoshi = new Avatar(this, 1, x, y);
	  addActor(m_yoshi);
  }  
  void addYoshi(const int x, const int y) { 
	  m_peach = new Avatar(this, 2, x, y);
		  addActor(m_peach); 
  }
  void addRedCoin(const int x, const int y) { addActor(new CoinSquare(this, 'r', x, y)); }
  void addBlueCoin(const int x, const int y) { addActor(new CoinSquare(this, 'b', x, y)); }
  void addVortex(const int x, const int y) { addActor(new Vortex(this, x, y)); }
  Board::GridEntry boardContents(int x, int y) { return getBoard()->getContentsOf(x/ SPRITE_WIDTH, y / SPRITE_HEIGHT); }
  
private:
	std::list<Actor*> m_actors;
	Board* m_board;
	Avatar* m_peach;
	Avatar* m_yoshi;
};

#endif // STUDENTWORLD_H_
