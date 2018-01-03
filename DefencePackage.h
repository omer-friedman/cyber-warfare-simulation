/*
 * DefencePackage.h
 *
 *  Created on: 15 בדצמ× 2017
 *      Author: Omer
 */

#ifndef DEFENCEPACKAGE_H_
#define DEFENCEPACKAGE_H_
#include "Package.h"

class DefencePackage: public Package{
public:
	DefencePackage(int dim=0) : Package(dim),maxPower(0){} //c'tor
	DefencePackage(const DefencePackage& nwDefPack):Package(nwDefPack),maxPower(nwDefPack.maxPower){} //copy c'tor
	virtual ~DefencePackage(); //d'tor
	virtual void findMaxPower(const OffencePackage&); //find the max power of the package
	virtual int getMaxPower(){return maxPower;}
	DefencePackage& operator=(const DefencePackage&); //set other defence package to "this"

private:
	int maxPower;
};

#endif /* DEFENCEPACKAGE_H_ */
