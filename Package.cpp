/*
 * Package.cpp
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#include "Package.h"

/*
	distructor: delete the package.
*/
Package::~Package() {
	for(int i=0;i<dimension;i++)
		delete stringArr[i];
	delete[] stringArr;
}

/*
	Function copy other pack to "this"
*/
Package& Package::operator =(const Package& otherPack) {
	dimension = otherPack.getDimension();
	for(int i=0;i<dimension;i++)
	{
		delete [] stringArr[i];
		stringArr[i] = new BitString(otherPack[i]);
	}
	return *this;
}

/*
	Function print the package
*/
void Package::print() {
	for(int i=0;i<dimension;i++)
	{
		if(stringArr[i]!=NULL)
			stringArr[i]->print();
		if(i!=(dimension-1))
			cout << endl;
	}
}
/*
	set bitString in index "ind"
*/
void Package::setStringArr(BitString* nwBitArr, int ind) {
	stringArr[ind] = new BitString(*nwBitArr);
}
