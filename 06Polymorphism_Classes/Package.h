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
		Package(int trackID = 0, string recipient = "", string sender = "", 
							int weight = 0, int distance = 0, int volume = 0);

		//virtual fuctions
		void print(ostream&);
		bool read(istream&);

		void addInsurance();
		void addRush();
		
	private:
		int mVolume;
};