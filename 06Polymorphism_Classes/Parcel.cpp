//***************************************************************************
// File name:			Parcel.cpp
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Implements constructors and function of class Parcel
//***************************************************************************

#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//***************************************************************************
// Function:			Parcel
// Description:		Grants Parcel.cpp access to private data in Parcel.h
// Parameters:		mTrackID - the tracking number
//								mSendTo - the address of the recipient
//								mSendFrom - the address of the sender
//								mWeight - the weight of the parcel
//								mDistance - how far the parcel needds to travel
// Returned:			none
//***************************************************************************
Parcel::Parcel(int trackID, string recipient, string sender, int weight, int distance) {
	mTrackID = trackID;
	mSendTo = recipient;
	mSendFrom = sender;
	mWeight = weight;
	mDistance = distance;

	mCost = 0.00;

	mTime = 1;

	mInsured = false;
	mRushed = false;
}

//***************************************************************************
// Function:		print
// Description: Prints Parcel data in a digestible sequence
// Parameters:	rcOut - the ostream operator
// Returned:		none
//***************************************************************************
void Parcel::print(ostream& rcOut) {
	rcOut << "TID: " << mTrackID << "\t" << "From: " << mSendFrom << setw(10) << "To: " << mSendTo;

	if (mInsured == true) {
		cout << "\t" << INSURED;
	}

	if (mRushed == true) {
		cout << "\t" << RUSHED;
	}
}

//***************************************************************************
// Function:		read
// Description: reads sequenced data into Parcel members
// Parameters:	rcIn - the istream operator
// Returned:		none
//***************************************************************************
bool Parcel::read(istream& rcIn) {
	rcIn >> mTrackID;
	rcIn >> mSendTo;
	rcIn >> mSendFrom;
	rcIn >> mWeight;
	rcIn >> mDistance;

	return true;
}

//***************************************************************************
// Function:		getCost
// Description: Returns the cost of mailing the Parcel
// Parameters:	none
// Returned:		the cost to ship the Parcel
//***************************************************************************
double Parcel::getCost() {
	return mCost;
}

//***************************************************************************
// Function:		getTime
// Description: Returns the time it will take mailing the Parcel
// Parameters:	none
// Returned:		the time it will take to ship the Parcel
//***************************************************************************
int Parcel::getTime() {
	return mTime;
}

//***************************************************************************
// Function:		getTID
// Description: Returns the tracking number
// Parameters:	none
// Returned:		the tracking number
//***************************************************************************
int Parcel::getTID() {
	return mTrackID;
}

//***************************************************************************
// Function:		addInsurance
// Description: Makes the Parcel "Insured"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Parcel::addInsurance() {
	mInsured = true;
}

//***************************************************************************
// Function:		addRush
// Description: Makes the Parcel "Rushed"
// Parameters:	none
// Returned:		none
//***************************************************************************
void Parcel::addRush() {
	mRushed = true;
}
