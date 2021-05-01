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
// Parameters:		mTrackID - the tracking number
//								mSendTo - the address of the recipient
//								mSendFrom - the address of the sender
//								mWeight - the weight of the parcel
//								mDistance - how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Postcard::Postcard(int trackID, string recipient, string sender, int weight, int distance, string message)
	: Parcel(trackID, recipient, sender, weight, distance) {

	mMessage = message;

	mCost = mPRICE;

	mTime = (distance / mSPEED);

	mInsured = false;
	mRushed = false;
}

//***************************************************************************
// Function:		print
// Description: Prints Postcard data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Postcard::print(ostream& rcOut) {
	this->print(rcOut);//is this correct???
}

//***************************************************************************
// Function:		read
// Description: assigns sequenced data into Postcard members
// Parameters:	rcIn - the istream operator
// Returned:		none
//***************************************************************************
bool Postcard::read(istream& rcIn) {
	this->read(rcIn);

	rcIn >> mMessage;
}

//***************************************************************************
// Function:		getCost
// Description: Returns the cost of mailing the Postcard
// Parameters:	none
// Returned:		the cost to ship the Postcard
//***************************************************************************
double Postcard::getCost() {
	return mCost;
}

//***************************************************************************
// Function:		getTime
// Description: Returns the time it will take mailing the Postcard
// Parameters:	none
// Returned:		the time it will take to ship the Postcard
//***************************************************************************
int Postcard::getTime() {
	return mTime;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Postcard "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Postcard::addInsurance() {
	mInsured = true;
	mCost = mINSURANCERATE + mCost;
	cout << "Added Insurance for $" << mINSURANCERATE;
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Postcard "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Postcard::addRush() {
	mRushed = true;
	mCost = mCost + mRUSHRATE;
	cout << "Added Rush for $" << mRUSHRATE;
}