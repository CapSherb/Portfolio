#include <iostream>
#include <cstdlib>
#include "calendar.h"
#include "screens.h"
using namespace std;


/****************|Objects & Variables|*******************/
Planner p1;
int Planner::numEvents = 0;
int currScreen = 0;
int plScreenSelect;
char yesno;
void fullCal();
void smallCal();

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n "<< "";
}

int main() {

/****************|Header title thing|*******************/

    do {
        if (currScreen == 0) {
            clear();
            homeScreen();
            currScreen = uChoice;
        } else if (currScreen == 1) {
            p1.setYear();
            clear();
            fullCal();
            currScreen = uChoice;
        } else if (currScreen == 2) {
            clear();
            smallCal();
            currScreen = uChoice;
        } else if (currScreen == 3) {
            clear();
            if (p1.getNumEvents() == 0) {
                std::cout << "You currently have no scheduled events\nWould you like to go to the Schedule Planner? (y/n):";
                std::cin >> yesno;
                if(yesno == 'y') {
                    currScreen = 4;
                } else {
                    currScreen = 0;
                }
            } else {
                p1.printEvents();
                p1.printAnnuals();
                system("PAUSE");
                choices();
                currScreen = uChoice;
            }
        } else if (currScreen == 4) {
            clear();
            plScreen();
            plScreenSelect = plUChoice;
            if (plScreenSelect == 0) {
                currScreen = 0;
            } else if (plScreenSelect == 1) {
                p1.addEvent();
            } else if (plScreenSelect == 2) {
                p1.deleteEvent();
            }
        } else if (currScreen == 5) {
            p1.setYear();
            cout << "The currently selected year is now " << p1.getYear() << endl;
            choices();
            currScreen = uChoice;
        }
    }while(currScreen >=0);
    return 0;
}

void fullCal() {
    clear();
    p1.printCalendar();
    cout<<endl;
    system("PAUSE");
    choices();
}

void smallCal() {
    clear();
    if (p1.getYear() == NULL)
        p1.setYear();
    else {
        cout << "Your currently selected year is " << p1.getYear() << "\nWould you like to change this? (y/n):";
        cin >> yesno;
        if (yesno == 'y')
            p1.setYear();
    }
    p1.setMonth();
    p1.printMonth(p1.getMonth());
    cout<<endl;
    system("PAUSE");
    choices();
}

