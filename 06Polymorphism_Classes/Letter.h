//***************************************************************************
// File name:			Letter.h
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Declares a defined subclass Letter
//***************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Letter: public Parcel {
public:
	//Constructor
	Letter(int trackID = 0, string recipient = "", string sender = "", int weight = 0, int distance = 0);//how to subclass

	//virtual fuctions
	void print(ostream&);
	bool read(istream&);

	double getCost();
	int getTime();

	void addInsurance();
	void addRush();

private:
	static const float mPRICEPEROZ = 0.45;//$ per oz
	static const int mSPEED = 100; //miles per day
	static const double mINSURANCERATE = 0.45;//$, flat
	static const double mRUSHPERCENT = 0.10;//%of current cost
};
