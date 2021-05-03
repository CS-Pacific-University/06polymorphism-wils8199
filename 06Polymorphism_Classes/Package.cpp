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
// Parameters:		mTrackID		- the tracking number
//								mSendTo			- the address of the recipient
//								mSendFrom		- the address of the sender
//								mWeight			- the weight of the parcel
//								mDistance		- how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Package::Package(int trackID, string recipient, string sender, 
									int weight, int distance, int volume)
	: Parcel(trackID, recipient, sender, weight, distance) {
	mVolume = volume;

	const int mSIZE = 100;//volume
	const int mOVERTIME = 1000;//miles
	const double mPRICESMALL = 12;//$, flat
	const double mPRICEBIG = 20;//$, flat
	
	if (mVolume > mSIZE) {
		mCost = mPRICEBIG;
	}
	else {
		mCost = mPRICESMALL;
	}

	if (mDistance > mOVERTIME) {
		mTime = 2;//IS THIS A MAGIC CONSTANT?
	}
	else {
		mTime = 1;
	}

}

//***************************************************************************
// Function:		print
// Description: Prints Package data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Package::print(ostream& rcOut) {
	const string mOVERNIGHT = "OVERNIGHT!";

	Parcel::print(rcOut);

	cout << mOVERNIGHT;
}

//***************************************************************************
// Function:		read
// Description: assigns sequenced data into Package members
// Parameters:	rcIn - the istream operator
// Returned:		the boolean state of the function
//***************************************************************************
bool Package::read(istream& rcIn) {
	bool wasRead = Parcel::read(rcIn);
	const int mSIZE = 100;//volume
	const int mOVERTIME = 1000;//miles
	const double mPRICESMALL = 12;//$, flat
	const double mPRICEBIG = 20;//$, flat
	const int FARTIME = 2;//day
	const int NEARTIME = 1;//day

	rcIn >> mVolume;
	
	if (mVolume > mSIZE) {
		mCost = mPRICEBIG;
	}
	else {
		mCost = mPRICESMALL;
	}

	if (mDistance > mOVERTIME) {
		mTime = FARTIME;//IS THIS A MAGIC CONSTANT?
	}
	else {
		mTime = NEARTIME;
	}

	return wasRead;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Package "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Package::addInsurance() {
	const double mINSURANCEPERCENT = 0.25;//$, percent of current const

	if (mInsured == false) {
		mInsured = true;

		cout << "Added Insurance for $" << (mINSURANCEPERCENT * mCost);

		mCost = (mINSURANCEPERCENT * mCost) + mCost;
	}
	else {
		cout << "Package has already been insured.";
		//there was no error handling specified if user chooses to insure twice
	}
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Package "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Package::addRush() {
	const double mRUSHPERCENT = 0.75;//$, percent of current cost

	if (mRushed == false) {
		mRushed = true;

		cout << "Added Rush for $" << (mRUSHPERCENT * mCost);

		mCost = (mRUSHPERCENT * mCost) + mCost;
	}
	else {
		cout << "Package has already been insured.";
		//there was no error handling specified if user chooses to insure twice
	}
}
