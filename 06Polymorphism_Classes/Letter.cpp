//***************************************************************************
// File name:			Letter.cpp
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Implements constructors and function of subclass Letter
//***************************************************************************

#include "Letter.h"
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//***************************************************************************
// Function:			Letter
// Description:		Grants Letter.cpp access to private data in Letter.h
// Parameters:		mTrackID - the tracking number
//								mSendTo - the address of the recipient
//								mSendFrom - the address of the sender
//								mWeight - the weight of the parcel
//								mDistance - how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Letter::Letter(int trackID, string recipient, string sender, int weight, int distance)
	: Parcel(trackID, recipient, sender, weight, distance) {//is it :parcel or :public parcel? identifieer?
	
	mCost = mPRICEPEROZ * weight;

	mTime = (distance / mSPEED);

	mInsured = false;
	mRushed = false;
}

//***************************************************************************
// Function:		print
// Description: Prints Letter data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Letter::print(ostream& rcOut) {
	this->print(rcOut);//is this correct???
}

//***************************************************************************
// Function:		read
// Description: assigns sequenced data into Letter members
// Parameters:	rcIn - the istream operator
// Returned:		none
//***************************************************************************
bool Letter::read(istream& rcIn) {
	this->read(rcIn);
}

//***************************************************************************
// Function:		getCost
// Description: Returns the cost of mailing the Letter
// Parameters:	none
// Returned:		the cost to ship the Letter
//***************************************************************************
double Letter::getCost() {
	return mCost;
}

//***************************************************************************
// Function:		getTime
// Description: Returns the time it will take mailing the Letter
// Parameters:	none
// Returned:		the time it will take to ship the Letter
//***************************************************************************
int Letter::getTime() {
	return mTime;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Letter "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Letter::addInsurance() {
	mInsured = true;
	mCost = mINSURANCERATE + mCost;
	cout << "Added Insurance for $" << mINSURANCERATE;
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Letter "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Letter::addRush() {
	mRushed = true;
	mCost = mCost + (mRUSHPERCENT * mCost);
	cout << "Added Rush for $" << (mRUSHPERCENT * mCost);
}
