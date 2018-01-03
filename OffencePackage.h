/*
 * OffencePackage.h
 *
 *  Created on: 15 בדצמ× 2017
 *      Author: Omer
 */

#ifndef OFFENCEPACKAGE_H_
#define OFFENCEPACKAGE_H_
#include "Package.h"

class OffencePackage : public Package {
public:
	OffencePackage(int dim=0): Package(dim){}; //call to father c'tor
	OffencePackage(const OffencePackage& otherOffencePack){*this = otherOffencePack;} //copy constructor
	virtual ~OffencePackage(){}; //virtual destructor
	OffencePackage& operator=(const OffencePackage& otherOffPack){Package::operator =(otherOffPack); return *this;}  //copy other package to "this"
	virtual void findMaxPower(const OffencePackage&){};
	virtual int getMaxPower(){return 0;};
};

#endif /* OFFENCEPACKAGE_H_ */
