#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Actor.h"
#include "Board.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
  virtual int init();
  virtual int move();
  virtual void cleanUp();
  ~StudentWorld() { cleanUp(); };
  bool wallFound(int x, int y) const;
  bool overlap(int x, int y, Actor* actor) const;
  Board* getBoard() const { return m_board; }
  
private:
	std::vector<Actor*> m_actors;
	Board* m_board;
};

#endif // STUDENTWORLD_H_
