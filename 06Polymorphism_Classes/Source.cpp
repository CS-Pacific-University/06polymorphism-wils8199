//**********************************************************************
// File Name:     Source.cpp
// Author:        CASPER XALLAN - wils8199
// Date:          4/29
// Class:         CS250
// Assignment:    06 Polymorphism_Classes
// Hours Worked:
// Computer OS:   Windows 10
// Purpose:       This program manages types of mail as class objects.
//**********************************************************************
// Notes: 
//**********************************************************************
//HELP:
//fixed set precision? LATERLATER
//the spacing betwen sender and reciever!! tab or not
//should const paramters be all caps
//initializing doubles and strings in the classes
//are the print fxns in parcle have strings that are magic constants
//am i printing correctly in print fxns of the cpp
//constructor: public parcel or parcel
//can I just use protected vars
//how to access protected vs private variables? normally "protectedVar" or with "Parcel.protectedVar"
//how can private vars be accessed thru derived classes - see bools in Parcel
//does calling the Parcel constructor in Letter also set the protected variables
//can virtual functions be called in the derived class? like calling addInsurance from Parcel in the addInsurance of Letter?
//do we use "virtual" before our functions in Parcel and "const override" at ou functions in the derived classes?
//do we still need to have virtual functions in our derived classes if we don't override the fxn in Parcel? Is it possible to use a Parcel function on one of its derivative objects?

#include "Parcel.h"
#include "Letter.h"
#include "Package.h"
#include "Postcard.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
//fixed setprecision;

void menu(int& control, const int& control1, const int& control2, const int& control3, const int& control4, const int& control5, const int& control6);
bool mailslot(const string filename, int& control, Parcel* pParcels[], int& parcelcount);
void printAll();
void addInsurance();
void addRush();
void deliver();
void nukeAll();

//***************************************************************************
// Function:      main
// Description:   Main function ties together the program.
// Parameters:    All
// Returned:      Program results
//***************************************************************************
int main() {
  const int PRINTALL = 1, INSURE = 2, RUSH = 3, DELIVER = 4;
  const int BYE = 5, TERMINATE = 6;
  const int MAX = 25;
  const string FILENAME = "Roster.txt";
  int mailcount = 0, control = 0;
  bool postmaster = false;
  Parcel* pMail[MAX] = { nullptr };

  cout << fixed << setprecision(2);//look online & back @ wednesday wk12 lecture & week 13 lab on fri

  cout << "Mail Simulator!" << endl << endl;

  while (control < BYE) {
    
    menu(control, PRINTALL, INSURE, RUSH, DELIVER, BYE, TERMINATE);
    
    //If the user inputs a bad TID display the menu and display the Choice> prompt

    if (control == PRINTALL) {
      //printAll(pMail, mailcount); 
    }

    if (control == INSURE) {
      //addInsurance(pMail, mailcount, control);
    }

    if (control == RUSH) {
      //addRush(pMail, mailcount, control);
    }

    if (control == DELIVER) {
      //deliver(pMail, mailcount, control);
    }
  }

  //nukeAll(pMail, mailcount);//deletes the Parcels

  if (control == BYE) {
    cout << "Exit Success";
    return EXIT_SUCCESS;
  }

  else {
    cout << "Input was invalid.";
    return EXIT_FAILURE;
  }

}

//***************************************************************************
// Function:      menu
// Description:   Prints the menu and lets the user choose
// Parameters:    choice1, choice2, and choice3 - the given numbered options
// Returned:      None
//***************************************************************************
//If the user inputs a bad Choice display the Choice> prompt again until valid input is given.
void menu(int& control, const int& control1, const int& control2, const int& control3, const int& control4, const int& control5, const int& control6) {
  const string OPTION1 = "Print All";
  const string OPTION2 = "Add Insurance";
  const string OPTION3 = "Add Rush";
  const string OPTION4 = "Deliver";
  int choice;

  cout << string(28, '-') << endl;
  cout << "1. " << OPTION1 << endl;
  cout << "2. " << OPTION2 << endl;
  cout << "3. " << OPTION3 << endl;
  cout << "4. " << OPTION4 << endl;
  cout << "5. Quit" << endl;
  cout << string(28, '-') << endl;

  do {
    cout << endl << "Choice> ";
    cin >> choice;
    cout << endl;
  } while (!(choice == control1 || choice == control2 || choice == control3 || choice == control4 || choice == control5));

  control = choice;//fix the var
}