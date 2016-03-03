//object2.cc

#include "object2.h"
#include <string>

/* === CTOR === */
Object::Object() : type(' '), subType("cell"), y(0), x(0), HP(0), ATK(0), DEF(0), Gold(0), tookAction(false) {}

Object::Object(char type, int y, int x) : type(type), y(y), x(x) {
	tookAction = false;
/* === PLAYER === */
	if(type == 'h') {//human
		subType = "player";
		HP = 140;
		ATK = 20;
		DEF = 20;
		Gold = 0;
	}
	else if(type == 'e') {//elf
		subType = "player";
		HP = 140;
		ATK = 30;
		DEF = 10;
		Gold = 0;
	}
	else if(type == 'd') {//dwarf
		subType = "player";
		HP = 100;
		ATK = 20;
		DEF = 30;
		Gold = 0;
	}
	else if(type == 'o') {//orc
		subType = "player";
		HP = 180;
		ATK = 30;
		DEF = 25;
		Gold = 0;
	}
/* === ENEMIES === */
	else if(type == 'V') {//vampire
		subType = "enemy";
		HP = 50;
		ATK = 25;
		DEF = 25;
		Gold = 1;
	}
	else if(type == 'W') {//werewolf
		subType = "enemy";
		HP = 120;
		ATK = 30;
		DEF = 5;
		Gold = 1;
	}
	else if(type == 'T') {//troll
		subType = "enemy";
		HP = 120;
		ATK = 25;
		DEF = 15;
		Gold = 1;
	}
	else if(type == 'N') {//goblin
		subType = "enemy";
		HP = 70;
		ATK = 5;
		DEF = 10;
		Gold = 1;
	}
	else if(type == 'M') {//merchant
		subType = "enemy";
		HP = 70;
		ATK = 5;
		DEF = 10;
		Gold = 0; //change this
	}
	else if(type == 'D') {//dragon
		subType = "enemy";
		HP = 150;
		ATK = 20;
		DEF = 20;
		Gold = 0;
	}
	else if(type == 'X') {//phoenix
		subType = "enemy";
		HP = 50;
		ATK = 35;
		DEF = 20;
		Gold = 0;
	}
/* === POTIONS === */
	else if(type == '0') {//restore health
		subType = "potion";
		HP = 10;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '1') {//boost attack
		subType = "potion";
		HP = 0;
		ATK = 5;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '2') {//boost defence
		subType = "potion";
		HP = 0;
		ATK = 0;
		DEF = 5;
		Gold = 0;
	}
	else if(type == '3') {//poison health
		subType = "potion";
		HP = -10;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '4') {//wound attack
		subType = "potion";
		HP = 0;
		ATK = -5;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '5') {//wound defence
		subType = "potion";
		HP = 0;
		ATK = 0;
		DEF = -5;
		Gold = 0;
	}
/* === GOLD === */
	else if(type == '6') {//normal
		subType = "gold";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 1;
	}
	else if(type == '7') {//small horde
		subType = "gold";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 2;
	}
	else if(type == '8') {//merchant horde
		subType = "gold";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 4;
	}
	else if(type == '9') {//dragon horde
		subType = "gold";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 6;
	}
/* === CELLS === */
	else if(type == ' ') {//empty
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '.') {//floor tile
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '+') {//doorway
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '-') {//top & bottom wall
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '|') {//side wall
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '#') {//passageway
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
	else if(type == '/') {//stairs
		subType = "cell";
		HP = 0;
		ATK = 0;
		DEF = 0;
		Gold = 0;
	}
}

/* === ACCESSORS === */
char Object::getType() {
	return type;
}

std::string Object::getSubType() {
	return subType;
}

int Object::getHP() {
	return HP;
}
	
int Object::getATK() {
	return ATK;
}
	
int Object::getDEF() {
	return DEF;
}

double Object::getGold() {
	return Gold;
}

int Object::getX() {
	return x;
}

int Object::getY() {
	return y;
}

bool Object::getTookAction() {
	return tookAction;
}

/* === MANIPULATORS === */
void Object::addHP(int i) {
	HP += i;
}

void Object::addATK(int i) {
	ATK += i;
}

void Object::addDEF(int i) {
	DEF += i;
}

void Object::addGold(int i) {
	Gold += i;
}

void Object::setHP(int i) {
	HP = i;
}

void Object::setATK(int i) {
	ATK = i;
}

void Object::setDEF(int i) {
	DEF = i;
}

void Object::setGold(int i) {
	Gold = i;
}

void Object::setY(int i) {
	y = i;
}

void Object::setX(int i) {
	x = i;
}

void Object::setYX(int j, int i) {
	y = j;
	x = i;
}

void Object::setTookActionTrue() {
	tookAction = true;
}

void Object::setTookActionFalse() {
	tookAction = false;
}

void Object::resetHP(char s) {
	if(s == 'h') {
		HP = 140;
	}
	else if(s == 'e') {
		HP = 140;
	}
	else if(s == 'd') {
		HP = 100;
	}
	else if(s == 'o') {
		HP = 180;
	}
}

void Object::resetATK(char s) {
	if(s == 'h') {
		ATK =  20;
	}
	else if(s == 'h') {
		ATK = 30;
	}
	else if(s == 'd') {
		ATK = 20;
	}
	else if(s == 'o') {
		ATK = 30;
	}
}

void Object::resetDEF(char s) {
	if(s == 'h') {
		DEF =  20;
		}
	else if(s == 'e') {
		DEF = 30;
	}
	else if(s == 'd') {
		DEF = 20;
	}
	else if(s == 'o') {
		DEF = 30;
	}
}

void Object::resetGold(char s) {
	Gold = 0;
}
