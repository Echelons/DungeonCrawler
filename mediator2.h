//mediator2.h

#ifndef __MEDIATOR2_H__
#define __MEDIATOR2_H__

#include <iostream>
#include <fstream>
#include "object2.h"

const int mapHeight = 25;
const int mapWidth = 79;

class Mediator {
	Object map[mapHeight][mapWidth];
	Object hldCell;
	Object cpyMap[mapHeight][mapWidth];
	int playerY, playerX;
	int floor;
	bool hostility;
	bool winFlag;
	bool loseFlag;
	std::string action;
public:
	void bottomLeft();
	Mediator(std::ifstream &f);
	void setDragons();
	void drawMap();
	void nextLevel();
	void attack(Object &a, Object &b);
	void interact(Object &a, Object &b);
	void setMerchantHostile();
	void setMerchantFriendly();
	void setHuman();
	void setElf();
	void setDwarf();
	void setOrc();
	
	bool nearPlayer(Object &a);
	bool nearDragon(Object &a);
	bool nearDragonHorde(Object &a);
	
	void cycleEnemyActions();
	std::string getAction();
	void resetAction();
	
	void moveNO();
	void moveNE();
	void moveEA();
	void moveSE();
	void moveSO();
	void moveSW();
	void moveWE();
	void moveNW();
	
	void attackNO();
	void attackNE();
	void attackEA();
	void attackSE();
	void attackSO();
	void attackSW();
	void attackWE();
	void attackNW();

	bool getWinFlag();
	bool getLoseFlag();
	int score();
	
};

#endif
