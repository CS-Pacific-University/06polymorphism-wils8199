//***************************************************************************
// File name:			Postcard.h
// Author:				Casper Xallan
// Date:					4/29/21
// Class:					CS250
// Assignment:		06Polymorphism_Classes
// Purpose:				Declares a defined subclass Postcard
//***************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Postcard: public Parcel {
public:
	//Constructor
	Postcard(int trackID = 0, string recipient = "", string sender = "", int weight = 0, int distance = 0, string message = "0");//how to subclass

	//virtual fuctions
	void print(ostream&);
	bool read(istream&);

	double getCost();
	int getTime();

	void addInsurance();
	void addRush();

private:
	string mMessage;

	static const double mPRICE = 0.15;//$, flat
	static const int mSPEED = 10;//miles per day
	static const double mINSURANCERATE = 0.15;//$, flat
	static const double mRUSHRATE = 0.025;//$, flat
};
