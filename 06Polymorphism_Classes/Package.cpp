//***************************************************************************
// File name:			Package.cpp
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Implements constructors and function of subclass Package
//***************************************************************************

#include "Package.h"
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//***************************************************************************
// Function:			Package
// Description:		Grants Package.cpp access to private data in Package.h
// Parameters:		mTrackID - the tracking number
//								mSendTo - the address of the recipient
//								mSendFrom - the address of the sender
//								mWeight - the weight of the parcel
//								mDistance - how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Package::Package(int trackID, string recipient, string sender, int weight, int distance, int volume)
	: Parcel(trackID, recipient, sender, weight, distance) {
	mVolume = volume;

	if (mVolume > mSIZE) {
		mCost = mPRICEBIG;
	}
	else {
		mCost = mPRICESMALL;
	}

	if (mDistance > mOVERTIME) {
		mTime = 2;//IS THIS A MAGIC CONSTANT?
		mOvernight = false;
	}
	else {
		mTime = 1;
		mOvernight = true;
	}

	mInsured = false;
	mRushed = false;
}

//***************************************************************************
// Function:		print
// Description: Prints Package data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Package::print(ostream& rcOut) {
	this->print(rcOut);//is this correct???
}

//***************************************************************************
// Function:		read
// Description: assigns sequenced data into Package members
// Parameters:	rcIn - the istream operator
// Returned:		none
//***************************************************************************
bool Package::read(istream& rcIn) {
	this->read(rcIn);

	rcIn >> mVolume;
}

//***************************************************************************
// Function:		getCost
// Description: Returns the cost of mailing the Package
// Parameters:	none
// Returned:		the cost to ship the Package
//***************************************************************************
double Package::getCost() {
	return mCost;
}

//***************************************************************************
// Function:		getTime
// Description: Returns the time it will take mailing the Package
// Parameters:	none
// Returned:		the time it will take to ship the Package
//***************************************************************************
int Package::getTime() {
	return mTime;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Package "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Package::addInsurance() {
	mInsured = true;
	mCost = (mINSURANCEPERCENT * mCost) + mCost;
	cout << "Added Insurance for $" << (mINSURANCEPERCENT * mCost);
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Package "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Package::addRush() {
	mRushed = true;
	mCost = (mRUSHPERCENT * mCost) + mCost;
	cout << "Added Rush for $" << (mRUSHPERCENT * mCost);
}
