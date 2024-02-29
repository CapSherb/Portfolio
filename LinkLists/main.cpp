#include <iostream>
#include "linkList.h"
using namespace std;

/**
 * Clears console screen - Begins following outputs at the top of console
 */
void clearScreen() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    int i = 0;
    while (i < 20) {
        std::cout << " " << std::endl;
        i++;
    }
    std::cout << "\x1B[2J\x1B[H";
}

/**
 * Main operation function
 * @return 0 is run was sucessful
 */
int main() {
    //----------|Variables|----------//
    bool keepGoing = true; //Variable to tell program to loop or not
    LinkList list1; //List creation/declaration
    int menuSelect; //Variable to store user's choice from menu
    int userValue; //Variable to store user's input value for node
    int userIndex; //Variable to store user's input for index

    //-----------|Main Program Loop|-----------//
    do{
        clearScreen();
        cout << "Choose one of the following: " << endl;
        cout << " 1 - Append number to list" << endl;
        cout << " 2 - Add number to the front of the list" << endl;
        cout << " 3 - Add number to specified index in the list" << endl;
        cout << " 4 - Delete an element from the end of the list" << endl;
        cout << " 5 - Delete an element from the front of the list" << endl;
        cout << " 6 - Delete an element from a specified index" << endl;
        cout << " 7 - Print the list" << endl;
        cout << " 8 - Empty the list" << endl;
        cout << " 9 - End the program" << endl;
        cin >> menuSelect;
        switch (menuSelect) { //Switch case for performing user's choice of operation

            //Case for when user chooses option 1
            //Adds element to end of list(tail)
            case 1:
                cout << "Enter a value to store in the list: ";
                cin >> userValue;
                list1.insert_end(userValue);
                break;

            //Case for when user chooses option 2
            //Adds element to front of list(head)
            case 2:
                cout << "Enter a value to store in the list: ";
                cin >> userValue;
                list1.insert_front(userValue);
                break;

            //Case for when user chooses option 3
            //Adds element to user selected index
            case 3:
                cout << "Enter a value to store in the list: ";
                cin >> userValue;
                if(!(list1.isEmpty())) {
                    cout << "The list is currently " << list1.size() << " elements long" << endl;
                    cout << "Please choose an index between 0(head) and " << list1.size() << "(tail): ";
                    cin >> userIndex;
                    if(userIndex == 0) {
                        list1.insert_front(userValue);
                    } else {
                        list1.insert_middle(userValue, userIndex);
                    }

                } else {
                    list1.insert_end(userValue);
                }
                break;

            //Case for when user selects option 4
            //Removes element from end of list(tail)
            case 4:
                if(list1.isEmpty()) {
                    cout << "This list is currently empty" << endl;
                } else {
                    cout << list1.remove_end() << " has been removed from the end of the list." << endl;
                }
                system("PAUSE");
                break;

            //Case for when user chooses option 5
            //Removes element from front of list(head)
            case 5:
                if(list1.isEmpty()) {
                    cout << "This list is currently empty" << endl;
                } else {
                    cout << list1.remove_front() << " has been removed from the front of the list." << endl;
                }
                system("PAUSE");
                break;

            //Case for when user chooses option 6
            //Deletes element from user selected index in list
            case 6:
                if(list1.isEmpty()) {
                    cout << "This list is currently empty" << endl;
                } else {
                    cout << "The list is currently " << list1.size() << " elements long" << endl;
                    cout << "Please choose an index between 1(head) and " << list1.size() << "(tail): ";
                    cin >> userIndex;
                    if(userIndex == 1) {
                        cout << list1.remove_front() << " has been removed from the selected index." << endl;
                    } else {
                        cout << list1.remove_middle(userIndex) << " has been removed from the selected index." << endl;
                    }

                }
                system("PAUSE");
                break;

            //Case for when user selects option 7
            //Prints list
            case 7:
                if(list1.isEmpty()) {
                    cout << "This list is currently empty" << endl;
                } else {
                    list1.printList();
                }
                system("PAUSE");
                break;

            //Case for when user selects option 8
            //Empties and deletes all elements in the list
            case 8:
                list1.makeEmpty();
                cout << "The list has been emptied" << endl;
                system("PAUSE");
                break;

            //Case for when user selects option 9
            //Ends program loop
            case 9:
                keepGoing = false;
                break;
            //Default case, sends error message and repeats program for invalid input
            default:
                cout << "Please select a valid input" << endl;
                system("PAUSE");
                break;
        }

    }while(keepGoing);



    return 0;
}
