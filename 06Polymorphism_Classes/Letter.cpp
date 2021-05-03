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
// Parameters:		mTrackID		- the tracking number
//								mSendTo			- the address of the recipient
//								mSendFrom		- the address of the sender
//								mWeight			- the weight of the parcel
//								mDistance		- how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Letter::Letter(int trackID, string recipient, string sender, 
								int weight, int distance)
	: Parcel(trackID, recipient, sender, weight, distance) {
	
	const double mPRICEPEROZ = 0.45;//$ per oz
	const int mSPEED = 100;//miles per day
	
	mCost = mPRICEPEROZ * weight;

	mTime = (distance / mSPEED) + mTime;
}

//***************************************************************************
// Function:		print
// Description: Prints Letter data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Letter::print(ostream& rcOut) {
	Parcel::print(rcOut);
}

//***************************************************************************
// Function:		read
// Description: assigns sequenced data into Letter members
// Parameters:	rcIn - the istream operator
// Returned:		the boolean state of the function
//***************************************************************************
bool Letter::read(istream& rcIn) {
	bool wasRead = Parcel::read(rcIn);
	const double mPRICEPEROZ = 0.45;//$ per oz
	const int mSPEED = 100;//miles per day

	mCost = mPRICEPEROZ * mWeight;

	mTime = (mDistance / mSPEED) + mTime;

	return wasRead;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Letter "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Letter::addInsurance() {
	const double mINSURANCERATE = 0.45;//$, flat
	
	if (mInsured == false) {
		mInsured = true;

		cout << "Added Insurance for $" << mINSURANCERATE;

		mCost = mINSURANCERATE + mCost;
	}
	else {
		cout << "Letter has already been insured.";
		//there was no error handling specified if user chooses to insure twice
	}
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Letter "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Letter::addRush() {
	const double mRUSHPERCENT = 0.10;//%of current cost

	if (mRushed == false) {
		mRushed = true;

		cout << "Added Rush for $" << (mRUSHPERCENT * mCost);

		mCost = mCost + (mRUSHPERCENT * mCost);
	}
	else {
		cout << "Letter has already been rushed.";
		//there was no error handling specified if user chooses to rush twice
	}
}
