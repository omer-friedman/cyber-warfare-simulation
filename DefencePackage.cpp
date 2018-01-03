/*
 * DefencePackage.cpp
 *
 *  Created on: 15 בדצמ× 2017
 *      Author: Omer
 */

#include "DefencePackage.h"

DefencePackage::~DefencePackage() {
	// TODO Auto-generated destructor stub
}

/*
	Function find the max power of all bitStrings
*/
void DefencePackage::findMaxPower(const OffencePackage& offPack) {
	int max=0;
	int curPower;
	for(int i=0;i<this->getDimension();i++)
	{
		(*this)[i].setPower(offPack); //set each BitString power
		curPower = (*this)[i].getPower();
		if(curPower>max)
			max = curPower;
	}
	maxPower = max;
}

/*
	Function copy nwDefPack to "this"
*/
DefencePackage& DefencePackage::operator =(const DefencePackage& nwDefPack) {
	Package::operator=(nwDefPack); //use father operator=
	maxPower = nwDefPack.maxPower; //set other data member
	return *this;
}
