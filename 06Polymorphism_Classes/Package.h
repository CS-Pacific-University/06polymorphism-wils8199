//***************************************************************************
// File name:			Package.h
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Declares a defined subclass Package
//***************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Package : public Parcel {
public:
	//Constructor
	Package(int trackID = 0, string recipient = "", string sender = "", int weight = 0, int distance = 0, int volume = 0);//how to subclass

	//virtual fuctions
	void print(ostream&);
	bool read(istream&);

	double getCost();
	int getTime();

	void addInsurance();
	void addRush();

private:
	int mVolume;
	static const int mSIZE = 100;//volume

	bool mOvernight = false;
	static const int mOVERTIME = 1000;//miles

	static const double mPRICESMALL = 12;//$, flat
	static const double mPRICEBIG = 20;//$, flat
	static const double mINSURANCEPERCENT = 0.25;//$, percent of current const
	static const double mRUSHPERCENT = 0.75;//$, percent of current cost
};