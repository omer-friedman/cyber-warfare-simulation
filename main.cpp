/*
 * main.cpp
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#include "Game.h"
#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		cerr << "ERROR: Invalid input." << endl;
		exit(1);
	}
	srand(time(NULL));
	Game* g = new Game(argv[1],argv[2]);
	g->fight();
	return 0;
}

