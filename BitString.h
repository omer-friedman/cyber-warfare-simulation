/*
 * BitString.h
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#ifndef BITSTRING_H_
#define BITSTRING_H_

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned char bit;
class OffencePackage;


class BitString {
public:
	BitString(const BitString&); 								//copy c'tor
	BitString(string bitArr,int size);							//c'tor by string
	~BitString(){delete stringArr;}								
	int checkPower(const BitString& pack); 						//check BitString power
	void initializeString(string bitArr);  						//initialize bitstring
	BitString& operator=(const BitString&);						//copy bitstring to this
	void operator %(BitString&);								//combine between two bitStrings
	bit& operator[](const int ind){return stringArr[ind];}     //allow access to cpesific cell - read and write
	bit operator[](const int ind)const{return stringArr[ind];} //allow access to cpesific cell - read only
	const void print() const;									//print BitString
	int getPower() const {return power;}
	void setPower(const OffencePackage&);
	int getSize() const {return size;}		

private:
	int size;
	int power;
	bit* stringArr;
};

#endif /* BITSTRING_H_ */
