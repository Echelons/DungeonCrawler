//main.cc

#include <iostream>
#include <string>
#include <fstream>
#include "mediator2.h"


bool gameLoop(Mediator DM) {
	// Choose Race
	std::string race;
	while (true) {
		std::cout << "Choose your race (h, e, d, o): ";
		std::cin >> race;
		if (race == "h") {
			DM.setHuman();
			break;
		} else if (race == "e") {
			DM.setElf();
			break;
		} else if (race == "d") {
			DM.setDwarf();
			break;
		} else if (race == "o") {
			DM.setOrc();
			break;
		} else if (race == "q") {
			return true;
		} else {
			std::cout << "You must enter a valid race." << std::endl;
		}
	}
	
	DM.drawMap();
	std::cout << "Player spawned." << std::endl;

	while (true) { // Loop for each turn
		if (DM.getWinFlag() == false && DM.getLoseFlag() == false) {
			while (true) { // Get a valid command from the player and execute it.
				std::string usrCmd;
				std::getline(std::cin, usrCmd);
			
				if (usrCmd == "no") {
					DM.moveNO();
					break;
				} else if (usrCmd == "so") {
					DM.moveSO();
					break;
				} else if (usrCmd == "ea") {
					DM.moveEA();
					break;
				} else if (usrCmd == "we") {
					DM.moveWE();
					break;
				} else if (usrCmd == "ne") {
					DM.moveNE();
					break;
				} else if (usrCmd == "nw") {
					DM.moveNW();
					break;
				} else if (usrCmd == "se") {
					DM.moveSE();
					break;
				} else if (usrCmd == "sw") {
					DM.moveSW();
					break;
				} else if (usrCmd == "u no") {
					DM.moveNO();
					break;
				} else if (usrCmd == "u so") {
					DM.moveSO();
					break;
				} else if (usrCmd == "u ea") {
					DM.moveEA();
					break;
				} else if (usrCmd == "u we") {
					DM.moveWE();
					break;
				} else if (usrCmd == "u ne") {
					DM.moveNE();
					break;
				} else if (usrCmd == "u nw") {
					DM.moveNW();
					break;
				} else if (usrCmd == "u se") {
					DM.moveSE();
					break;
				} else if (usrCmd == "u sw") {
					DM.moveSW();
					break;
				} else if (usrCmd == "a no") {
					DM.attackNO();
					break;
				} else if (usrCmd == "a so") {
					DM.attackSO();
					break;
				} else if (usrCmd == "a ea") {
					DM.attackEA();
					break;
				} else if (usrCmd == "a we") {
					DM.attackWE();
					break;
				} else if (usrCmd == "a ne") {
					DM.attackNE();
					break;
				} else if (usrCmd == "a nw") {
					DM.attackNW();
					break;
				} else if (usrCmd == "a se") {
					DM.attackSE();
					break;
				} else if (usrCmd == "a sw") {
					DM.attackSW();
					break;
				} else if (usrCmd == "r") {
					return false;
				} else if (usrCmd == "q") {
					return true;
				} else {
					//std::cout << "You must enter a valid command." << std::endl;
				}
			}
	
			DM.cycleEnemyActions();
			DM.drawMap();
			std::cout << DM.getAction() << std::endl; // print actions
			DM.resetAction();

		} else if (DM.getWinFlag() == true) {
			std::cout << "You win!  Score: " << DM.score() << std::endl;
			return false;
		} else if (DM.getLoseFlag() == true) {
			std::cout << "You died!  Score: " << DM.score() << std::endl;
			return false;
		}
	}
}




int main(int argc, char *argv[]) {
	std::ifstream mapTemplate("map.txt");
	Mediator DM(mapTemplate);
	if(argc > 2) { //check for correct usage
		std::cerr << "Usage " << argv[0] << "[filename]" << std::endl;
		return 0;
	}
	if(argc == 2) { //a command line argument was given
		std::ifstream mapTemplate(argv[1]); //open desired file
		if(!mapTemplate.is_open()) { //make sure file got opened
			std::cerr << argv[1] << " could not be opened!" << std::endl;
			return 0;
		}
		else { //read in file
			DM = Mediator(mapTemplate);
		}
	}
	else {
		std::ifstream mapTemplate("map.txt");
		DM = Mediator(mapTemplate);
	}
	
	bool quitFlag = false;
	std::string retry;
	while (!quitFlag) { // continue playing until player quits
		if (quitFlag == false) {
			quitFlag = gameLoop(DM);
		}
	}
}
