/*
 * Package.h
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_

#include "BitString.h"
#include <typeinfo>
#include <iostream>

class Package {
public:
	Package(int dim=0):dimension(dim),stringArr(0){initializePackage();}  //c'tor
	virtual ~Package();													  //d'tor
	void setStringArr(BitString*,int ind);								  //set string array at place ind
	void initializePackage(){stringArr = new BitString*[dimension];}	  //initialize package
	Package& operator=(const Package& otherPack);						  //copy from otherPack to "this"
	BitString& operator[](const int ind){return *(stringArr[ind]);}		  //allow access to specific cell - read and write
	BitString operator[](const int ind)const{return *(stringArr[ind]);}	  //allow access to specific cell - read only
	void print();														  //print package
	int getDimension() const {return dimension;}						  //get package dimension
	virtual void findMaxPower(const OffencePackage&)=0;					  //find max power(only defence package)
	virtual int getMaxPower()=0;										  //get max power(only defence package)

private:
	int dimension;
	BitString** stringArr;
};

#endif /* PACKAGE_H_ */
