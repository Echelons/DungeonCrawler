//mediator2.cc

#include <cmath>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "mediator2.h"
#include "object2.h"

void Mediator::bottomLeft() {
	std::cout << map[24][0].getType() << std::endl;
}

Mediator::Mediator(std::ifstream &f) {
	char c;
	for(int i = 0; i < mapHeight; i++) {
		for(int j = 0; j < mapWidth; j++) {
			if(f.peek() == '\n') {
				f.ignore();
			}
			f.get(c);
			if (c == '@') {
				map[i][j] = Object('h', i, j);
				playerY = i;
				playerX = j;
			} 
			else {
				map[i][j] = Object(c, i, j);
			}
		}
	}
	for(int i = 0 ; i < mapHeight ; i++) {
		for(int j = 0 ; j < mapWidth ; j++) {
			cpyMap[i][j] = map[i][j];
		}
	}
	//setDragons();
	floor = 1;
	hostility = false;
	hldCell = Object('.', playerY, playerX);
	winFlag = false;
	loseFlag = false;
	action = "";
}

void Mediator::setDragons() {//places dragons beside a dragon horde
	srand(time(NULL));
	bool stopFlag = false;
	for(int i = 0 ; i < mapHeight ; ++i) {
		for(int j = 0 ; j < mapWidth ; ++j) {
			if(map[i][j].getType() == '9') {
				while(!stopFlag) {
					int r = rand() % 8;
					if(r == 0) {//place dragon NW of dragon horde
						if(!map[i-1][j-1].getType() == '.') {
							continue;
						} else {
							map[i-1][j-1] = Object('D', i-1, j-1);
							stopFlag = true;
						}
					} else if(r == 1) {//place dragon N of dragon horde
						if(!map[i-1][j].getType() == '.') {
							continue;
						} else {
							map[i-1][j] = Object('D', i-1, j);
							stopFlag = true;
						}
					} else if(r == 2) {//place dragon NE of dragon horde
						if(!map[i-1][j+1].getType() == '.') {
							continue;
						} else {
							map[i-1][j+1] = Object('D', i-1, j+1);
							stopFlag = true;
						}
					} else if(r == 3) {//place dragon E of dragon horde
						if(!map[i][j+1].getType() == '.') {
							continue;
						} else {
							map[i][j+1] = Object('D', i, j+1);
							stopFlag = true;
						}
					} else if(r == 4) {//place dragon SE of dragon horde
						if(!map[i+1][j+1].getType() == '.') {
							continue;
						} else {
							map[i+1][j+1] = Object('D', i+1, j+1);
							stopFlag = true;
						}
					} else if(r == 5) {//place dragon S of dragon horde
						if(!map[i+1][j].getType() == '.') {
							continue;
						} else {
							map[i+1][j] = Object('D', i+1, j);
							stopFlag = true;
						}
					} else if(r == 6) {//place dragon SW of dragon horde
						if(!map[i+1][j-1].getType() == '.') {
							continue;
						} else {
							map[i+1][j-1] = Object('D', i+1, j-1);
							stopFlag = true;
						}
					} else if(r == 7) {//place dragon W of dragon horde
						if(!map[i][j-1].getType() == '.') {
							continue;
						} else {
							map[i][j-1] = Object('D', i, j-1);
							stopFlag = true;
						}
					}
				}
			}
		}
	}
}

void Mediator::drawMap() {
	for(int i = 0 ; i < mapHeight ; ++i) {
		for(int j = 0 ; j < mapWidth ; ++j) {
			/* === OBJECTS === */
			if(map[i][j].getType() == '|') { std::cout << "|"; }//side wall
			else if(map[i][j].getType() == '-') { std::cout << "-"; }//top-bottom wall
			else if(map[i][j].getType() == '.') { std::cout << "."; }//floor tile
			else if(map[i][j].getType() == '+') { std::cout << "+"; }//doorway
			else if(map[i][j].getType() == '#') { std::cout << "#"; }//passage
			else if(map[i][j].getType() == ' ') { std::cout << " "; }//empty space
			else if(map[i][j].getType() == '/') { std::cout << "/"; }//staircase
			/* === CHARACTERS (PLAYER + ENEMIES) === */
			else if(map[i][j].getType() == 'h') { std::cout << "@"; }//player character
			else if(map[i][j].getType() == 'e') { std::cout << "@"; }//player character
			else if(map[i][j].getType() == 'd') { std::cout << "@"; }//player character
			else if(map[i][j].getType() == 'o') { std::cout << "@"; }//player character
			else if(map[i][j].getType() == 'V') { std::cout << "V"; }//vampire
			else if(map[i][j].getType() == 'W') { std::cout << "W"; }//werewolf
			else if(map[i][j].getType() == 'T') { std::cout << "T"; }//troll
			else if(map[i][j].getType() == 'N') { std::cout << "N"; }//goblin
			else if(map[i][j].getType() == 'M') { std::cout << "M"; }//merchant
			else if(map[i][j].getType() == 'D') { std::cout << "D"; }//dragon
			else if(map[i][j].getType() == 'X') { std::cout << "X"; }//phoenix
			/* === POTIONS === */
			else if(map[i][j].getType() == '0') { std::cout << "P"; }//restore health
			else if(map[i][j].getType() == '1') { std::cout << "P"; }//boost attack
			else if(map[i][j].getType() == '2') { std::cout << "P"; }//boost defence
			else if(map[i][j].getType() == '3') { std::cout << "P"; }//poison health
			else if(map[i][j].getType() == '4') { std::cout << "P"; }//wound attack
			else if(map[i][j].getType() == '5') { std::cout << "P"; }//wound defence
			/* === GOLD === */
			else if(map[i][j].getType() == '6') { std::cout << "G"; }//normal
			else if(map[i][j].getType() == '7') { std::cout << "G"; }//small horde
			else if(map[i][j].getType() == '8') { std::cout << "G"; }//merchant horde
			else if(map[i][j].getType() == '9') { std::cout << "G"; }//dragon horde
		}
	std::cout << std::endl;
	}
	std::cout << "Race: ";
	if(map[playerY][playerX].getType() == 'h') { std::cout << "Human "; }
	else if(map[playerY][playerX].getType() == 'e') { std::cout << "Elf "; }
	else if(map[playerY][playerX].getType() == 'd') { std::cout << "Dwarf "; }
	else if(map[playerY][playerX].getType() == 'o') { std::cout << "Orc "; }
	std::cout << "Gold: " << map[playerY][playerX].getGold();
	std::cout << "                                             Floor: " << floor << std::endl;
	std::cout << "HP: "  << map[playerY][playerX].getHP() << std::endl;
	std::cout << "Atk: " << map[playerY][playerX].getATK() << std::endl;
	std::cout << "Def: " << map[playerY][playerX].getDEF() << std::endl;
	std::cout << "Action: ";
}

void Mediator::nextLevel() {
	if (floor == 10) {
		winFlag = true;
	} else {
		int tmpHP = map[playerY][playerX].getHP();
		int tmpGold = map[playerY][playerX].getGold();
		char tmpType = map[playerY][playerX].getType();
		for(int i = 0 ; i < mapHeight ; ++i) {
			for(int j = 0 ; j < mapWidth ; ++j) {
				map[i][j] = cpyMap[i][j];
				if(cpyMap[i][j].getSubType() == "player") {
					playerX = j;
					playerY = i;
				}
			}
		}
		map[playerY][playerX].resetATK(tmpType);
		map[playerY][playerX].resetDEF(tmpType);
		map[playerY][playerX].setHP(tmpHP);
		map[playerY][playerX].setGold(tmpGold);
		//setDragons();
		++floor;
		hldCell = Object('.', playerY, playerX);
	}
}

void Mediator::attack(Object &a, Object &b) {//player attacks object
	if(b.getType() == 'M') { setMerchantHostile(); }
	if(b.getSubType() == "enemy") {
		int damage = ceil((100 / (100 + double(b.getDEF()))) * double(a.getATK()));
		b.addHP(-damage);
		action = action + "Player attacks enemy.  ";
		if(b.getHP() <= 0) {
			action = action + "Enemy dies.  ";
			if(b.getType() == 'M') {//If merchant dies, replace spot with merchant horde
				a.addGold(b.getGold());
				int tmpY, tmpX;
				tmpY  = b.getY();
				tmpX = b.getX();
				b = Object('8', tmpY, tmpX);
			}
			else {//if non-merchant enemy dies, replace spot with floor tile
				a.addGold(b.getGold());
				int tmpY, tmpX;
				tmpY  = b.getY();
				tmpX = b.getX();
				b = Object('.', tmpY, tmpX);
			}
		}
	}
	else {
		action = action + "You attack the ground!  ";
		/*do nothing, you didn't attack an enemy*/
	}
}
		
void Mediator::interact(Object &a, Object &b) {
	if(a.getSubType() == "player") {//player interacts with object
		if(b.getSubType() == "gold") {
			if(b.getType() == '9' && nearDragon(b)) {
				//cannot collect dragon still alive
				action = action + "You try to pick up the dragon's horde, but it's still alive.";
			}
			else if(a.getType() == 'd') {//dwarf double gold
				a.addGold(2 * b.getGold());
				action = action + "Player picks up gold.  ";
			}
			else if(a.getType() == 'o') {//orc half gold
				a.addGold(b.getGold() / 2);
				action = action + "Player picks up gold.  ";
			}
			else {//normal gold collection
				a.addGold(b.getGold());
				action = action + "Player picks up gold.  ";
			}
			/*replace collected gold with floor tile then move player onto space*/
			if (b.getType() != '9' || !nearDragon(b)) {
				int tmpY, tmpX;
				tmpY  = b.getY();
				tmpX = b.getX();
				b = Object('.', tmpY, tmpX); //replace gold with floor tile
				interact(a, b); //call interact again, this will switch the positions of the two objects
			}
		}
		else if(b.getSubType() == "potion") {// POTION INTERACTION
			if(b.getType() == 'e') {
				if(b.getType() == '3' || b.getType() == '4' || b.getType() == '5') {
					a.addHP(-1 * b.getHP());
					a.addATK(-1 * b.getATK());
					a.addDEF(-1 * b.getDEF());
				}
				else {
					a.addHP(b.getHP());
					a.addATK(b.getATK());
					a.addDEF(b.getDEF());
				}
			}
			else {
				a.addHP(b.getHP());
				a.addATK(b.getATK());
				a.addDEF(b.getDEF());
			}
			//replace used potion with floor tile (.)
			int tmpY, tmpX;
			tmpY  = b.getY();
			tmpX = b.getX();
			b = Object('.', tmpY, tmpX); //replace potion with floor tile
			interact(a, b); //call interact again, this will switch the positions of the two objects
			action = action + "Player used a potion.  ";
		}
		else if(b.getSubType() == "cell") {// MOVEMENT
			if(b.getType() == ' '|| b.getType() == '-' || b.getType() == '|') {
				//do nothing, can't interact with these cells
				action = action + "You can't move there.  ";
			}
			else if(b.getType() == '/') {
				nextLevel();
			}
			else {
				Object tmp = b;
				b = a;
				b.setYX(tmp.getY(), tmp.getX());
				playerY = tmp.getY();
				playerX = tmp.getX();
				a = hldCell;
				hldCell = tmp;
				action = action + "Player moved.  ";
			}
		}
	}
	else if(a.getSubType() == "enemy") {//enemy interacts with object
		if(b.getSubType() == "enemy" || b.getSubType() == "gold" || b.getSubType() == "potion") {
			//do nothing
		}
		else if(b.getSubType() == "player") {
			if(a.getType() == 'D' && !nearDragonHorde(b)) {
				//player not beside dragon horde, dragon too lazy so no attack
			}
			else if(a.getType() == 'M' && !hostility) {
				//friendly merchant, does not attack, gives high five
			}
			else {//enemy attacks player
				int damage = ceil((100 / (100 + double(b.getDEF()))) * double(a.getATK()));
				b.addHP(-damage);
				action = action + "Enemy attacks player.  ";
					if(b.getHP() <= 0) {
						loseFlag = true;
					}
			}
		}
		else if(b.getSubType() == "cell") {
			if(a.getType() == 'D') {
				//do nothing
			}
			if(b.getType() == ' '|| b.getType() == '-' || b.getType() == '|' || b.getType() == '+' || b.getType() == '#' || b.getType() == '/') {
				//do nothing, can't interact with these cells
			}
			else {//swap the objects positions
				Object tmp = b;
				int tmpAY, tmpAX, tmpBY, tmpBX;
				tmpAY = a.getY();
				tmpAX = a.getX();
				tmpBY = b.getY();
				tmpBX = b.getX();
				b = a;
				a = tmp;
				b.setYX(tmpBY, tmpBX);
				a.setYX(tmpAY, tmpAX);
			}
		}
	}
}

void Mediator::setMerchantHostile() {
	hostility = true;
}

void Mediator::setMerchantFriendly() {
	hostility = false;
}

void Mediator::setHuman() {
	map[playerY][playerX] = Object('h', playerY, playerX);
}

void Mediator::setElf() {
	map[playerY][playerX] = Object('e', playerY, playerX);
}

void Mediator::setDwarf() {
	map[playerY][playerX] = Object('d', playerY, playerX);
}

void Mediator::setOrc() {
	map[playerY][playerX] = Object('o', playerY, playerX);
}
 
bool Mediator::nearPlayer(Object &a) {//determines if the object has a player in its radius
	int tmpY, tmpX;
	tmpY = a.getY();
	tmpX = a.getX();
	return (map[tmpY-1][tmpX-1].getSubType() == "player" || map[tmpY-1][tmpX].getSubType() == "player" || 
		    map[tmpY-1][tmpX+1].getSubType() == "player" || map[tmpY][tmpX-1].getSubType() == "player" || 
			map[tmpY][tmpX+1].getSubType() == "player" || map[tmpY+1][tmpX-1].getSubType() == "player" || 
			map[tmpY+1][tmpX].getSubType() == "player" || map[tmpY+1][tmpX+1].getSubType() == "player");
}

bool Mediator::nearDragon(Object &a) {//determines if the object has a dragon in its radius
	int tmpY, tmpX;
	tmpY = a.getY();
	tmpX = a.getX();
	return (map[tmpY-1][tmpX-1].getType() == 'D' || map[tmpY-1][tmpX].getType() == 'D' || 
		    map[tmpY-1][tmpX+1].getType() == 'D' || map[tmpY][tmpX-1].getType() == 'D' || 
			map[tmpY][tmpX+1].getType() == 'D' || map[tmpY+1][tmpX-1].getType() == 'D' || 
			map[tmpY+1][tmpX].getType() == 'D' || map[tmpY+1][tmpX+1].getType() == 'D');
}

bool Mediator::nearDragonHorde(Object &a) {//determines if the object has a dragon horde in its radius
	int tmpY, tmpX;
	tmpY = a.getY();
	tmpX = a.getX();
	return (map[tmpY-1][tmpX-1].getType() == '9' || map[tmpY-1][tmpX].getType() == '9' || 
		    map[tmpY-1][tmpX+1].getType() == '9' || map[tmpY][tmpX-1].getType() == '9' || 
			map[tmpY][tmpX+1].getType() == '9' || map[tmpY+1][tmpX-1].getType() == '9' || 
			map[tmpY+1][tmpX].getType() == '9' || map[tmpY+1][tmpX+1].getType() == '9');
}

void Mediator::cycleEnemyActions() {//cycles the map and makes appropriate action for each enemy
	srand(time(NULL));
	for(int i = 0; i < mapHeight ; ++i) {
		for(int j = 0; j < mapWidth ; ++j) {
			if(map[i][j].getSubType() == "enemy" && !map[i][j].getTookAction()) {
				map[i][j].setTookActionTrue();
				if(nearPlayer(map[i][j])) {//attack player
					interact(map[i][j], map[playerY][playerX]);
				}
				else if (map[i][j].getType() != 'D') {//move in random direction
					int r = rand() % 8;
					if(r == 0) {//move NW
						interact(map[i][j], map[i-1][j-1]);
					}
					else if(r == 1) {//move N
						interact(map[i][j], map[i-1][j]);
					}
					else if(r == 2) {//move NE
						interact(map[i][j], map[i-1][j+1]);
					}
					else if(r == 3) {//move E
						interact(map[i][j], map[i][j+1]);
					}
					else if(r == 4) {//move SE
						interact(map[i][j], map[i+1][j+1]);
					}
					else if(r == 5) {//move S
						interact(map[i][j], map[i+1][j]);
					}
					else if(r == 6) {//move SW
						interact(map[i][j], map[i+1][j-1]);
					}
					else if(r == 7) {//move W
						interact(map[i][j], map[i][j-1]);
					}
				}
			}
		}
	}
	for(int i = 0; i < mapHeight ; ++i) {//set all objects in map tookAction to false
		for(int j = 0; j < mapWidth ; ++j) {
			map[i][j].setTookActionFalse();
		}
	}
}

std::string Mediator::getAction() {
	return action;
}

void Mediator::resetAction() {
	action = "";
}

void Mediator::moveNO() {
	interact(map[playerY][playerX], map[playerY-1][playerX]);
}

void Mediator::moveNE() {
	interact(map[playerY][playerX], map[playerY-1][playerX+1]);
}

void Mediator::moveEA() {
	interact(map[playerY][playerX], map[playerY][playerX+1]);
}

void Mediator::moveSE() {
	interact(map[playerY][playerX], map[playerY+1][playerX+1]);
}

void Mediator::moveSO() {
	interact(map[playerY][playerX], map[playerY+1][playerX]);
}

void Mediator::moveSW() {
	interact(map[playerY][playerX], map[playerY+1][playerX-1]);
}

void Mediator::moveWE() {
	interact(map[playerY][playerX], map[playerY][playerX-1]);
}

void Mediator::moveNW() {
	interact(map[playerY][playerX], map[playerY-1][playerX-1]);
}

void Mediator::attackNO() {
	attack(map[playerY][playerX], map[playerY-1][playerX]);
}
void Mediator::attackNE() {
	attack(map[playerY][playerX], map[playerY-1][playerX+1]);
}
void Mediator::attackEA() {
	attack(map[playerY][playerX], map[playerY][playerX+1]);
}
void Mediator::attackSE() {
	attack(map[playerY][playerX], map[playerY+1][playerX+1]);
}
void Mediator::attackSO() {
	attack(map[playerY][playerX], map[playerY+1][playerX]);
}
void Mediator::attackSW() {
	attack(map[playerY][playerX], map[playerY+1][playerX-1]);
}
void Mediator::attackWE() {
	attack(map[playerY][playerX], map[playerY][playerX-1]);
}
void Mediator::attackNW() {
	attack(map[playerY][playerX], map[playerY-1][playerX-1]);
}

int Mediator::score() {
	if (map[playerY][playerX].getType() == 'h') {
		return map[playerY][playerX].getGold() + 0.5 * map[playerY][playerX].getGold();
	} else {
		return map[playerY][playerX].getGold();
	}
}

bool Mediator::getWinFlag() {
	return winFlag;
}

bool Mediator::getLoseFlag() {
	return loseFlag;
}
