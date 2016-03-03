//object2.h

#ifndef __OBJECT2_H__
#define __OBJECT2_H__

#include <string>

class Object {
	char type;
	std::string subType;
	int y, x, HP, ATK, DEF;
	double Gold;
	bool tookAction;
public:
	Object();
	Object(char type, int y, int x);
	
	char getType();
	std::string getSubType();
	int getHP();
	int getATK();
	int getDEF();
	double getGold();
	int getY();
	int getX();
	bool getTookAction();

	void addHP(int i);
	void addATK(int i);
	void addDEF(int i);
	void addGold(int i);
	
	void setHP(int i);
	void setATK(int i);
	void setDEF(int i);
	void setGold(int i);
	void setY(int i);
	void setX(int i);
	void setYX(int j, int i);
	void setTookActionTrue();
	void setTookActionFalse();
	void resetHP(char s);
	void resetATK(char s);
	void resetDEF(char s);
	void resetGold(char s);
};

#endif
