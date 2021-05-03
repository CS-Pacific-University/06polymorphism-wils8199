//**********************************************************************
// File Name:     Source.cpp
// Author:        CASPER XALLAN - wils8199
// Date:          4/29
// Class:         CS250
// Assignment:    06 Polymorphism_Classes
// Hours Worked:  26
// Computer OS:   Windows 10
// Purpose:       This program manages types of mail as class objects.
//**********************************************************************
// Notes: 
//**********************************************************************
//HELP:
//fixed set precision? LATERLATER
//DO THE CONSTANTS
//COST COMES AFTER.cpp

//the spacing betwen sender and reciever!! tab or not
//printAll nullptrs

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

void menu(int& rControl,
  const int& rReturn,
  const int& rChoice1, 
  const int& rChoice2,
  const int& rChoice3,
  const int& rChoice4,
  const int& rChoice5,
  const int& rTerminate);
bool mailslot(const string filename,
  int& rControl,
  Parcel* paParcels[], 
  int& rParcelcount);
void printAll(Parcel* paParcels[],
  int& rParcelcount);
void addInsurance(Parcel* paParcels[],
  int& rParcelcount,
  int& rControl, 
  const int& rIfInvalid);
void addRush(Parcel* paParcels[],
  int& rParcelcount,
  int& rControl,
  const int& rIfInvalid);
void deliver(Parcel* paParcels[],
  int& rParcelcount,
  int& rControl,
  const int& rIfInvalid);
void nukeAll(Parcel* paParcels[],
  int& rParcelcount);
int pickParcel(Parcel* paParcels[],
  int& rParcelcount,
  int& rControl,
  const int& rIfInvalid);

//***************************************************************************
// Function:      main
// Description:   Main function ties together the program.
// Parameters:    All
// Returned:      Program results
//***************************************************************************
int main() {
  const int RETURN = 0, PRINTALL = 1, INSURE = 2, RUSH = 3;
  const int DELIVER = 4, BYE = 5, TERMINATE = 6;
  const int MAX = 25;
  const string FILENAME = "Roster.txt";
  int mailcount = 0, control = 0;
  bool postmaster = false;
  Parcel* pMail[MAX] = { nullptr };

  cout << fixed << setprecision(2);

  cout << "Mail Simulator!" << endl;
  postmaster = mailslot(FILENAME, control, pMail, mailcount);

  while (control < BYE) {
    
    menu(control, RETURN, PRINTALL, INSURE, RUSH, DELIVER, BYE, TERMINATE);

    if (control == PRINTALL) {
      printAll(pMail, mailcount); 
    }

    if (control == INSURE) {
      addInsurance(pMail, mailcount, control, RETURN);
    }

    if (control == RUSH) {
      addRush(pMail, mailcount, control, RETURN);
    }

    if (control == DELIVER) {
      deliver(pMail, mailcount, control, RETURN);
    }

  }

  nukeAll(pMail, mailcount);//deletes all Parcels

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
// Parameters:    rControl    - the decisive variable
//                rReturn     - restarts the while loop with the menu
//                rChoice1    - the 1st option
//                rChoice2    - the 2nd option
//                rChoice3    - the 3rd option
//                rChoice4    - the 4th option
//                rChoice5    - the 5th option, quits program successfully
//                rTerminate  - terminates program; unsucccessful quit
// Returned:      None
//***************************************************************************

void menu(int& rControl, const int& rReturn, const int& rChoice1, 
            const int& rChoice2, const int& rChoice3, const int& rChoice4, 
            const int& rChoice5, const int& rTerminate) {

  const string OPTION1 = "Print All";
  const string OPTION2 = "Add Insurance";
  const string OPTION3 = "Add Rush";
  const string OPTION4 = "Deliver";
  int choice;

  cout << endl;
  cout << "1. " << OPTION1 << endl;
  cout << "2. " << OPTION2 << endl;
  cout << "3. " << OPTION3 << endl;
  cout << "4. " << OPTION4 << endl;
  cout << "5. Quit" << endl;

  do {//If the user inputs a bad Choice display the Choice> prompt again
//until valid input is given.
    cout << endl << "Choice> ";
    cin >> choice;
    cout << endl;
  } while (!(choice == rChoice1 || choice == rChoice2 || choice == rChoice3 
              || choice == rChoice4 || choice == rChoice5));

  rControl = choice;//fix the var
}

//***************************************************************************
// Function:      mailslot
// Description:   Enters Parcels into the pointer array from the file
// Parameters:    filename      - the file which will read in Parcels
//                rControl      - the decisive variable
//                paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
// Returned:      the bool status of reading in
//***************************************************************************
bool mailslot(const string filename, int& rControl,
                Parcel* paParcels[], int& rParcelcount) {
  
  const char LETTER = 'L', POSTCARD = 'P', PACKAGE = 'O';
  ifstream inFile;
  char mailtype;
  bool wasRead = true;

  do {
    inFile.open(filename);
    //validate existence 
  } while (!(inFile.is_open()));

  while (!inFile.eof() && wasRead != false) {
    inFile >> mailtype;
    
    if (mailtype == LETTER) {
      paParcels[rParcelcount] = new Letter;
      wasRead = paParcels[rParcelcount]->read(inFile);
    }

    if (mailtype == POSTCARD) {
      paParcels[rParcelcount] = new Postcard;
      wasRead = paParcels[rParcelcount]->read(inFile);
    }

    if (mailtype == PACKAGE) {
      paParcels[rParcelcount] = new Package;
      wasRead = paParcels[rParcelcount]->read(inFile);
    }

    rParcelcount++;
  }

  //close file
  inFile.close();

  return wasRead;
}

//***************************************************************************
// Function:      printAll
// Description:   Prints the menu and lets the user choose
// Parameters:    paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
// Returned:      None
//***************************************************************************
//When you access the array, skip any position that contains a nullptr.
void printAll(Parcel* paParcels[], int& rParcelcount) {

  for (int i = 0; i < rParcelcount; i++) {//might need to be <=
    if (paParcels[i] != nullptr) {
      paParcels[i]->print(cout);
      cout << endl;
    }
  }
}

//***************************************************************************
// Function:      getTID
// Description:   Inputs and verifies a user-selected TID#.
// Parameters:    paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
//                rControl      - the decisive variable
//                rIfInvalid     - the default for rControl if TID is invalid
// Returned:      None
//***************************************************************************
int pickParcel(Parcel* paParcels[], int& rParcelcount, int& rControl,
                const int& rIfInvalid) {

  int TID, mailslotID = 0;
  bool valid = false;

  cout << "TID> ";
  cin >> TID;

  for (int i = 0; i < rParcelcount; i++) {
    if (paParcels[i] != nullptr) {
      if (TID == paParcels[i]->getTID()) {
        valid = true;
        mailslotID = i;
      }
    }
  }

  if (valid == false) {
    rControl = rIfInvalid;
  }

  return mailslotID;
}

//***************************************************************************
// Function:      addInsurance
// Description:   Calls addInsurance on a user-selected Parcel
// Parameters:    paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
//                rControl      - the decisive variable
//                rIfInvalid     - the default for rControl if TID is invalid
// Returned:      None
//***************************************************************************
void addInsurance(Parcel* paParcels[], int& rParcelcount, int& rControl, 
                    const int& rIfInvalid) {

  int whichParcel = pickParcel(paParcels, rParcelcount, rControl, rIfInvalid);

  if (rControl != rIfInvalid) {
    paParcels[whichParcel]->addInsurance();
    cout << endl;
    paParcels[whichParcel]->print(cout);
    cout << endl;
  }

}

//***************************************************************************
// Function:      addRush
// Description:   Calls addRush on a user-selected Parcel
// Parameters:    paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
//                rControl      - the decisive variable
//                rIfInvalid     - the default for rControl if TID is invalid
// Returned:      None
//***************************************************************************
void addRush(Parcel* paParcels[], int& rParcelcount, int& rControl,
              const int& rIfInvalid) {

  int whichParcel = pickParcel(paParcels, rParcelcount, rControl, rIfInvalid);

  if (rControl != rIfInvalid) {
    paParcels[whichParcel]->addRush();
    cout << endl;
    paParcels[whichParcel]->print(cout);
    cout << endl;
  }

}

//***************************************************************************
// Function:      deliver
// Description:   Prints the menu and lets the user choose
// Parameters:    paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
//                rControl      - the decisive variable
//                rIfInvalid     - the default for rControl if TID is invalid
// Returned:      None
//***************************************************************************
void deliver(Parcel* paParcels[], int& rParcelcount, int& rControl,
              const int& rIfInvalid) {
  //When you deliver a Parcel, deallocate that object and set the pointer
  //in that spot in the array to nullptr. When you access the array, 
  //skip any position that contains a nullptr.

  const string SENT = "Delivered!";
  int whichParcel = pickParcel(paParcels, 
                                rParcelcount, rControl, rIfInvalid);

  if (rControl != rIfInvalid) {
    cout << endl << SENT << endl;
    cout << paParcels[whichParcel]->getTime() << " Day";
    cout << ", $" << paParcels[whichParcel]->getCost() << endl;
    paParcels[whichParcel]->print(cout);
    paParcels[whichParcel] = { nullptr };
    cout << endl;
  }
}

//***************************************************************************
// Function:      nukeAll
// Description:   deletes all contents of the Parcel pointer array
// Parameters:    paParcels[]   - the pointer array of Parcels
//                rParcelcount  - the number of Parcels in the pointer array
// Returned:      None
//***************************************************************************
void nukeAll(Parcel* paParcels[], int& rParcelcount) {

  for (int i = 0; i < rParcelcount; i++) {
    delete paParcels[i];//use delete or nllptr?
  }
}