
#ifndef CAL_SCREENS_H
#define CAL_SCREENS_H
#include <iostream>
void clearScreen() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    int i = 0;
    while (i < 20) {
        std::cout << " " << std::endl;
        i++;
    }
    std::cout << "\x1B[2J\x1B[H";
}




int uChoice;
int plUChoice;


void choices() {
    try {

        std::cout << "\nPick one of the following: " << std::endl;
        std::cout << " 0 - Back to home page" << std::endl;
        std::cout << " 1 - Show a 12-month calendar" << std::endl;
        std::cout << " 2 - Show a single month's calendar" << std::endl;
        std::cout << " 3 - Show a list of upcoming events" << std::endl;
        std::cout << " 4 - Enter the Schedule planner" << std::endl;
        std::cout << " 5 - Change the set year" << std::endl;
        std::cout << " *Enter a negative number to end the program*" << std::endl;
        std::cin >> uChoice;
        if(uChoice > 5) {
            throw 1;
        }
    }
    catch(int) {
        clearScreen();
        std::cout << "***********|User Selection Error|*************" << std::endl;
        std::cout << "Please enter a number corresponding to a listed choice" << std::endl;
        std::cout << "Please try again"<< std::endl;
        std::cout<<std::endl;
        system("PAUSE");
        choices();
    }

}


/****************|Header title thing|*******************/
void homeScreen() {
    try {
        std::cout << "Welcome to the best calendar and schedule planner you will ever use!" << std::endl;
        std::cout << "Choose what you would like to do: " << std::endl;
        std::cout << " 1 - Show 12-month calendar" << std::endl;
        std::cout << " 2 - Show a single month's calendar" << std::endl;
        std::cout << " 3 - Show a list of upcoming events" << std::endl;
        std::cout << " 4 - Enter the Schedule planner" << std::endl;
        std::cin >> uChoice;
        if(uChoice < 1 || uChoice > 4) {
            throw 1;
        }
    }
    catch(int) {
        clearScreen();
        std::cout << "***********|User Selection Error|*************" << std::endl;
        std::cout << "Please enter a number (1 - 4) corresponding to a listed choice" << std::endl;
        std::cout << "Please try again"<< std::endl;
        std::cout<<std::endl;
        system("PAUSE");
        homeScreen();
    }

}

void plScreen() {
    try {
        std::cout << "Pick one of the following: " << std::endl;
        std::cout << " 0 - Back to home screen" << std::endl;
        std::cout << " 1 - Add a new event" << std::endl;
        std::cout << " 2 - Delete an event" << std::endl;
        std::cin >> plUChoice;
        if (plUChoice < 0 || plUChoice > 2) {
            throw 1;
        }
    }
    catch(int) {
        clearScreen();
        std::cout << "***********|User Selection Error|*************" << std::endl;
        std::cout << "Please enter a number (0 - 2) corresponding to a listed choice" << std::endl;
        std::cout << "Please try again"<< std::endl;
        std::cout<<std::endl;
        system("PAUSE");
        plScreen();
    }
}





#endif //CAL_SCREENS_H
