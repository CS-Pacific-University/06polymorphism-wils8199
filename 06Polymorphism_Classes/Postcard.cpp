//***************************************************************************
// File name:			Postcard.cpp
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Implements constructors and function of subclass Postcard
//***************************************************************************

#include "Postcard.h"
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//***************************************************************************
// Function:			Postcard
// Description:		Grants Postcard.cpp access to private data in Postcard.h
// Parameters:		mTrackID		- the tracking number
//								mSendTo			- the address of the recipient
//								mSendFrom		- the address of the sender
//								mWeight			- the weight of the parcel
//								mDistance		- how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Postcard::Postcard(int trackID, string recipient, string sender, 
										int weight, int distance, string message)
	: Parcel(trackID, recipient, sender, weight, distance) {

	const double mPRICE = 0.15;//$, flat
	const int mSPEED = 10;//miles per day
	
	mMessage = message;

	mCost = mPRICE;

	mTime = mTime + (distance / mSPEED);
}

//***************************************************************************
// Function:		print
// Description: Prints Postcard data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Postcard::print(ostream& rcOut) {
	Parcel::print(rcOut);

	cout << mMessage;
}

//***************************************************************************
// Function:		read
// Description: assigns sequenced data into Postcard members
// Parameters:	rcIn - the istream operator
// Returned:		the boolean state of the function
//***************************************************************************
bool Postcard::read(istream& rcIn) {
	bool wasRead = Parcel::read(rcIn);
	const double mPRICE = 0.15;//$, flat
	const int mSPEED = 10;//miles per day

	mCost = mPRICE;

	mTime = mTime + (mDistance / mSPEED);
	
	rcIn >> mMessage;

	return wasRead;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Postcard "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Postcard::addInsurance() {
	const double mINSURANCERATE = 0.15;//$, flat

	if (mInsured == false) {
		mInsured = true;

		cout << "Added Insurance for $" << mINSURANCERATE;

		mCost = mINSURANCERATE + mCost;
	}
	else {
		cout << "Postcard has already been insured.";
		//there was no error handling specified if user chooses to insure twice
	}
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Postcard "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Postcard::addRush() {
	const double mRUSHRATE = 0.25;//$, flat

	if (mRushed == false) {
		mRushed = true;

		cout << "Added Rush for $" << mRUSHRATE;

		mCost = mCost + mRUSHRATE;
	}
	else {
		cout << "Postcard has already been insured.";
		//there was no error handling specified if user chooses to insure twice
	}
}