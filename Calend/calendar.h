
#ifndef CAL_CALENDAR_H
#define CAL_CALENDAR_H
#include <iostream>
#include <string>
#include  <bits/stdc++.h>
#include "screens.h"


class Calendar{
protected:
    int year;
    int month;
public:


    void setYear() {
        std::cout << "Enter a year: ";
        std::cin >> year;
    }

    void setYear(int y) {
        year = y;
    }

    int getYear() {
        return year;
    }


    int dayNumber(int day, int month, int year) {
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        year -= month < 3;
        return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
    }

    std::string getMonthName(int monthNumber) {
        std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return (months[monthNumber]);
    }
    int numberOfDays (int monthNumber, int year) {
        switch(monthNumber){
            case 0 :
            case 2 :
            case 4 :
            case 6 :
            case 7 :
            case 9 :
            case 11: return(31);
                break;
            case 1 :
                if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0))
                    return (29);
                else
                    return (28);
                break;
            case 3 :
            case 5 :
            case 8 :
            case 10 : return(30);
                break;
        }
        return 0;

    }


    void setMonth() {
        std::cout << "Enter a month number: ";
        std::cin >> month;
    }
    void setMonth(int m) {
        month = m;
    }

    int getMonth() {
        return month;
    }


    void printMonth(int m){
        int days;
        int current = dayNumber (1, m, year);
        days = numberOfDays (m - 1, year);
        std::cout<<std::endl<<"   --------"<<getMonthName (m - 1).c_str()<<"-------- "<<std::endl;
        std::cout<<" Sun Mon Tue Wed Thu Fri Sat \n";
        int k;
        for (k = 0; k < current; k++)
            std::cout<<"    ";
        for (int j = 1; j <= days; j++){
            printf("%4d", j);
            if (++k > 6){
                k = 0;
                std::cout<<std::endl;
            }
        }
        if (k){
            std::cout<<std::endl;
            current = k;
        }
    }

    struct Event{
        int eventMonth;
        int eventDay;
        std::string eventDescrip;
    };

    void printCalendar() {
        clearScreen();
        std::cout << "            |"<< year << "|           ";
        for (int i = 1; i <= 12; i++) {
            printMonth(i);
        }
    }



};


class Planner : public Calendar {
private:
    int uMonth;
    int uDay;
    std::string uDescrip;
    static int numEvents;
    Event* events = new Event[500];
    Event annualEvents[8] = {{1,1,"New Years Day"},
                             {2,  14, "Valentine's Day"},
                             {3,17, "St. Patrick's Day"},
                             {4,1,"April Fool's Day"},
                             {7,4,"Fourth of July"},
                             {10,31,"Halloween"},
                             {12, 25, "Christmas"},
                             {12, 31, "New Years Eve"}};


public:

    Planner() {
        numEvents = 0;
    }
    int getNumEvents() {
        return numEvents;
    }

    void printAnnuals() {
        std::cout << "\nAnnual Events: " << std::endl;
        for (int i = 0; i < 8; i++) {
            std::cout << " - " << annualEvents[i].eventMonth << "/" << annualEvents[i].eventDay << " - " << annualEvents[i].eventDescrip << "\n";
        }
    }
    void printEvents() {
        std::cout << "Your Events: " << std::endl;
        for (int i = 0; i < numEvents; i++) {
            std::cout << " "<< i+1 <<" - " << events[i].eventMonth << "/" << events[i].eventDay << " - " << events[i].eventDescrip << "\n";
        }
    }


    void addEvent() {
        try{
            std::cout << "Enter the month of your event: " << std::endl;
            std::cin >> uMonth;
            if (uMonth < 1 || uMonth > 12)
                throw 'x';
            std::cout << "Enter the day of your event: " << std::endl;
            std::cin >> uDay;
            if (uDay < 1 || uDay > 31){
                throw 1;
            }
            std::cin.ignore();
            std::cout << "Enter a short description of the event: ";
            std::getline(std::cin, uDescrip);
            events[numEvents].eventMonth = uMonth;
            events[numEvents].eventDay = uDay;
            events[numEvents].eventDescrip = uDescrip;
            numEvents++;
            std::cout << "Your new event is scheduled: " << &events[numEvents].eventMonth << "/" << &events[numEvents].eventDay;
        }
        catch(char) {
            std::cout << "***********|Month Number Error|*************" << std::endl;
            std::cout << "Please enter a number (1 - 12) corresponding to a month" << std::endl;
            std::cout << "Please try again"<< std::endl;
            std::cout<<std::endl;
            system("PAUSE");
            addEvent();
        }
        catch(int) {
            if (uMonth == 1 || uMonth == 3 || uMonth == 5 || uMonth == 7 || uMonth == 8 || uMonth == 10 || uMonth == 12) {
                std::cout << "***********|Day Number Error|*************" << std::endl;
                std::cout << "Please enter a number (1 - 31) corresponding to a day of the month" << std::endl;
                std::cout << "============ Please try again =============="<< std::endl;
                std::cout<<std::endl;
                system("PAUSE");
                addEvent();
            } else if (uMonth == 4 || uMonth == 6 || uMonth == 9 || uMonth == 11) {
                std::cout << "***********|Day Number Error|*************" << std::endl;
                std::cout << "Please enter a number (1 - 30) corresponding to a day of your chosen month" << std::endl;
                std::cout << "============ Please try again =============="<< std::endl;
                std::cout<<std::endl;
                system("PAUSE");
                addEvent();
            } else if (uMonth == 2 && year%4 != 0){
                std::cout << "***********|Day Number Error|*************" << std::endl;
                std::cout << "Please enter a number (1 - 28) corresponding to a day of your chosen month" << std::endl;
                std::cout << "============ Please try again =============="<< std::endl;
                std::cout<<std::endl;
                system("PAUSE");
                addEvent();
            } else {
                std::cout << "***********|Day Number Error|*************" << std::endl;
                std::cout << "Please enter a number (1 - 29) corresponding to a day of your chosen month" << std::endl;
                std::cout << "============ Please try again =============="<< std::endl;
                std::cout<<std::endl;
                system("PAUSE");
                addEvent();
            }

        }
    }

    void deleteEvent() {
        /**
        int delEvent;
        Event temp;
        std::cout << "Here are your events: " << std::endl;
        printEvents();
        std::cout << "\n Pick an event to delete: ";
        std::cin >> delEvent;
        for(int i = numEvents; i > delEvent; i++) {
            temp = events[i - 1];
            events[i-1] = events[i];
        }
        numEvents--;
         **/
    }

};



#endif //CAL_CALENDAR_H
