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
	Parcel(int trackID = 0, string recipient = "", string sender = "", int weight = 0.00, int distance = 0.00);//should I initialize like this? is constr necessary?
	
	void print(ostream&);
	bool read(istream&);

	double getCost();
	int getTime();
	int getTID();

	void addInsurance();
	void addRush();
	
private: //can or should these be protected??
	int mTrackID;
	string mSendTo;
	string mSendFrom;

protected: //can or should these be private??
	//These will be defined by functions in the subcalsses.
	int mWeight;//oz
	int mDistance;//miles
	
	bool mInsured = false;
	bool mRushed = false;

	double mCost = 0.00;//$		//initialize here or Parcel.cpp?
	int mTime = 1;//days

	static const string INSURED = "INSURED";
	static const string RUSHED = "RUSH";
};

