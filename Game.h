/*
 * Game.h
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#ifndef GAME_H_
#define GAME_H_

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Package.h"
#include "OffencePackage.h"
#include "DefencePackage.h"

class Game {
public:
	Game(string, string); 									//c'tor
	Game(const Game&);										//copy c'tor
	~Game(){delete offence; delete defence;}				//d'tor
	Game& operator=(const Game&);							
	void readOffencePackage(string filename);				//read the offence package from file
	void readConfig(string filename);						//read the config and set the int data members
	void initialize();										//initialize game
	int checkNumber(string);								//change string to number if it is a number.
	void printWinner(int numOfIterations);					//print number of iterations and defence package
	void inputDefence();									//set defence with random 0 or 1
	void fight();											//main function that search for winner.
	void sortPackageByPower();								//sort package by power
	void changeSubStrings();								//change sub strings randomly
	int getDefenceSize() const {return defenceSize;}
	int getStringDimension() const {return stringDimension;}
	int getLifeTime() const {return lifeTime;}
	OffencePackage& getOffence() const {return *offence;}
	DefencePackage& getDefence() const {return *defence;}
private:
	int stringDimension;		//how many bytes in each bitString
	int defenceSize;			//size of defence package
	int lifeTime;				//number of generations
	OffencePackage* offence;	//offence package
	DefencePackage* defence;	//defence package

};

#endif /* GAME_H_ */
