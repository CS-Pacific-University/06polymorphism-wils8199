//***************************************************************************
// File name:			Parcel.h
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Declares a defined class Parcel
//***************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Parcel {
	public:
		//Constructor
		Parcel(int trackID = 0, string recipient = "", string sender = "",
						int weight = 0.00, int distance = 0.00);
	
		virtual void print(ostream&);
		virtual bool read(istream&);

		double getCost();
		int getTime();
		int getTID();

		virtual void addInsurance();
		virtual void addRush();	

	protected://These will be defined by functions in the subcalsses.
		int mTrackID;
		string mSendTo;
		string mSendFrom;
		int mWeight;//oz
		int mDistance;//miles
	
		bool mInsured = false;
		bool mRushed = false;

		double mCost = 0.00;//$		
		int mTime = 1;//days
};

