/*
 * Game.cpp
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#include "Game.h"

/*
	Function initialize the game. set offence package and data members from files
	and set the defence package.
*/
Game::Game(string config, string offence):offence(0),defence(0) {
	readConfig(config);
	readOffencePackage(offence);
	defence = new DefencePackage(defenceSize);
	inputDefence();
	defence->findMaxPower(*(this->offence));
}

/*
	copy constructor
*/
Game::Game(const Game& otherGame)
{
  *this = otherGame;
}

/*
	operator=: get reference to other game and copy the data memebers to "this"
*/
Game& Game::operator =(const Game& otherGame) {
  delete []offence;
  delete []defence;
  offence = new OffencePackage(otherGame.getOffence());
  defence = new DefencePackage(otherGame.getDefence());
  stringDimension = otherGame.getStringDimension();
  lifeTime = otherGame.getLifeTime();
  defenceSize = otherGame.getDefenceSize();
  return *this;
}

/*
	Function gets a file name,read it and initialize the offence package
	if input is wrong, print error messege and exit the program.
*/
void Game::readOffencePackage(string filename) {
	string line;
	int cntLine=0;
	int offenceDimension;
	int offenceStringSize;
	ifstream fin(filename.c_str());
	if (fin.is_open())
	{
		getline(fin,line);
		offenceDimension = checkNumber(line);
		if(offenceDimension!=-1 && offenceDimension%2==0) //check string dimension
		{
			getline (fin,line);
			offenceStringSize = (line.length()%2 == 0? line.length():line.length()/2+1);
			if(offenceStringSize!=stringDimension)
				goto prntErr;
			offence = new OffencePackage(offenceDimension);
		}
		else
			goto prntErr;
		do
		{
			offence->setStringArr(new BitString(line,offenceStringSize),cntLine++);
		}
		while (getline (fin,line));
    if(cntLine!=offenceDimension)
      goto prntErr;
		fin.close();
		return;
	}
	else{
		prntErr:
		cerr << "ERROR: Invalid input.";
		exit(1);
	}
}

/*
	Function gets a file name,read it and initialize the integer data members
	if input is wrong, print error messege and exit the program.
*/
void Game::readConfig(string filename) {
	string line;
	int size;
	ifstream fin(filename.c_str());
	if (fin.is_open())
	{
		fin >> line;
		size = checkNumber(line);
		if(size==-1 || size>1000000 || size<8)
			goto prntErr1;
		stringDimension = size;
		fin >> line;
		size = checkNumber(line);
		if(size==-1 || size>1024)
			goto prntErr1;
		defenceSize = size;
		fin >> line;
		size = checkNumber(line);
		if(size==-1 || size>1000000)
			goto prntErr1;
		lifeTime = size;
		fin.close();
	}
	else{
		prntErr1:
		cerr << "ERROR: Invalid input.";
		exit(1);
	}

}

/*
	Function gets string. if this string is a number, it returns the number
	else return -1.
*/
int Game::checkNumber(string word) {
	int length = word.length();
	for(int i=0;i<length;i++)
    {
		if(!isdigit(word.at(i))) //check if every char in the string is a digit
			return -1;
    }
	return atoi(word.c_str());
}

/*
	Function print num of iterations and print the defence package.
*/
void Game::printWinner(int numOfIterations) {
	cout << numOfIterations << endl;
	defence->print();
  cout << endl;
}

/*
	Function initialize random bitStrings and initialize the defence package.
*/
void Game::inputDefence() {
	string line="";
	int randNum;
	for(int j=0;j<defenceSize;j++)
	{
		line="";
		for(int i=0;i<stringDimension;i++)
		{
			randNum=rand()%2;
			line += randNum+'0';
			if(i!=stringDimension-1)
				line+=" ";
		}
		defence->setStringArr(new BitString(line,stringDimension),j);
	}
	return;
}

/*
	Function will keep change substrings until max power found or
	out of generations.
*/
void Game::fight() {
	int i;
	for(i=0;i<lifeTime;i++)
	{
		defence->findMaxPower(*offence);
		if(!(defence->getMaxPower()==stringDimension))
			changeSubStrings();
		else
			break;
	}
	sortPackageByPower();
	printWinner(i);
}

/*
	Function change the defence package. choose half random bitstrings
	and change substrings with the best half.
*/
void Game::changeSubStrings(){
	int hetzion = defenceSize/2;
	int randNum,randNumPack;
	sortPackageByPower();
	for(int i=0;i<hetzion;i++) //chose half random bitStrings
	{
		randNum = rand()%(defenceSize/2);
		randNumPack = rand()%defenceSize;
		(*defence)[randNumPack] % (*defence)[randNum];
	}
}

/*
	sort defence package by power from big to small.
*/
void Game::sortPackageByPower() {
	int i;
	BitString* tmp;
	for(i=0;i<defenceSize;i++)
	{
		for(int j=1;j<(defenceSize-i);j++)
		{
			if((*defence)[j-1].getPower() < (*defence)[j].getPower())
			{
				tmp = new BitString((*defence)[j-1]);
				(*defence)[j-1] = (*defence)[j];
				(*defence)[j] = *tmp;
				delete tmp;
			}

		}
	}
}
