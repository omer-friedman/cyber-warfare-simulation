/*
 * BitString.cpp
 *
 *  Created on: 14 בדצמ× 2017
 *      Author: Omer
 */

#include "BitString.h"
#include "OffencePackage.h"

/*
	Copy Constructor.	
*/
BitString::BitString(const BitString& cpyBitString):size(0),power(0),stringArr(0) {
	*this = cpyBitString;
}

/*
	Constructor by string.
*/
BitString::BitString(string bitArr,int sz):size(sz),power(0),stringArr(0) {
	stringArr = new bit[size];
	initializeString(bitArr);
}

/*
	Funfction gets bit array as string and initialize the BitString.
*/
void BitString::initializeString(string bitArr) {
	bit c;
	if((int)(bitArr.length()/2 + 1)!=size) //check if length of string is ok.
	{
		prntErr:
		cerr << "ERROR: Invalid input.";
		exit(1);
	}
	for(int i=0;i<size;i++)
	{
		c = bitArr.at(i*2);
		if(c!='0' && c!='1') //check if string has somthing not 0 or 1.
			goto prntErr;
		stringArr[i] = c;
	}
}

/*
	Function get a reference to bitString and copy it to this.
*/
BitString& BitString::operator =(const BitString& otherBitStr) {
	delete []stringArr;
	stringArr = new bit[otherBitStr.getSize()];
	size = otherBitStr.getSize();
	power = otherBitStr.getPower();
	for(int i=0;i<size;i++)
		stringArr[i] = otherBitStr[i];
	return *this;
}

const void BitString::print() const
{
	for(int i=0;i<size;i++)
  {
		cout << stringArr[i];
    if(i!=size-1)
      cout << " ";
  }
}

/*
	Function get reference to bitString and change randomly substring
	between *this and other bitString.
*/
void BitString::operator %(BitString& otherBitStr) {
	bit curbit;
	int start,end=0;
	start=(rand()%size-2)+1; //where to start cutting
	while(start>=end)
		end = (rand()%size-1)+1;
	
	for(int i=start;i<=end;i++)			//swap substrings for "start" to "end" bit by bit
	{
		curbit = (*this)[i];
		(*this)[i] = otherBitStr[i];
		otherBitStr[i] = curbit;
	}
}

/*
	Function gets the offence package, check and set the maximum power of this BitString
	by checking every bitString of the offance package.
*/
void BitString::setPower(const OffencePackage& offPack) {
	int sz, max = 0;
	int curOffbit,curDeffbit;
	int offDim = offPack.getDimension();
	for(int i = 0; i < offDim; i++)
	{
		sz = size;
		for(int j=0; j<size;j++)
		{
			curOffbit = (offPack[i])[j]-'0';
			curDeffbit = (*this)[j]-'0';
			sz -= (curDeffbit*(1-curOffbit)) + (curOffbit*(1-curDeffbit)); //decrese by 1 if bit not the same.
		}
		if(sz>max)
			max = sz;
		if(max==size)
			break;
	}
	power = max;
}
