//---------------------------------------------------------
// File : lineCalc.cpp
// Class: COP 2006, Fall 2022
// Devel: Richard Beuck
// Desc : Using structures to take in the coordinates for
//        2 points and calculate the equation of a line
//        along with the associated values for the line
//---------------------------------------------------------
#include <iostream>
#include <cmath>

//Structures

struct Point { //function for creating a point
    float xCoor;
    float yCoor;
};

struct LinePoints { //function for assigning points to a line
    Point p1;
    Point p2;
};

//Function Declarations
Point getPoint();
std::string displayPoint(Point p);
float getSlope(LinePoints line);
float getY_Intercept(LinePoints line);
float getLineLength(LinePoints line);
float getLineAngle(LinePoints line);
void additionalInfo(LinePoints line);

//Function Definitions
//-------------------------------------------------------//
int main() {

    char calcYN; //conditional operator for do/while loop, if 'Y' then loop
    do {

        //declaring and assigning values for the line that the user wants to calculate
        LinePoints line;
        std::cout << "First point: " << std::endl;
        line.p1 = getPoint();
        std::cout << "Second point: " << std::endl;
        line.p2 = getPoint();

        //finding y-int and slope of line to use in following code
        float b = getY_Intercept(line);
        float m = getSlope(line);

        std::cout << "From points " << displayPoint(line.p1) << " and " << displayPoint(line.p2)
        << " we get the following information:\n" << std::endl;

        if (fabsf(m) == INFINITY) { //if the line is vertical, the output will be made accordingly

            std::cout << "The line made from these points is vertical, therefore: " << std::endl;
            std::cout << " - The slope, m, is infinite" << std::endl;

            if (line.p1.xCoor == 0) { //if the line is on the y-axis, output the following
                std::cout << " - This line matches up with the y-axis, meaning there are infinite Y-Intercepts"
                             "\n - The equation of this line is x = 0\n" << std::endl;

            } else { //if line is not on y-axis, output the following
                std::cout << " - This line does not match with the y-axis, meaning there are no Y-Intercepts"
                             "\n - The equation of this line is x = " << line.p1.xCoor << "\n" << std::endl;
            }

            additionalInfo(line);// dist and angle of line

            //asking user if they would like to calculate another line and assigning
            //answer to conditional variable for loop, anything but 'Y' ends loop
            std::cout << "Would you like to calculate another line? (Y/N):";
            std::cin >> calcYN;
            std::cout << std::endl;

        } else {

            std::cout << "The line made by these two points is not vertical, therefore: " << std::endl;
            //output for Y-Intercept of the line
            std::cout << " - The Y-Intercept of the line is b = " << b << ", or (0, " << b << ")"
            << std::endl;

            //output for slope of the line
            std::cout << " - The slope of the line is m = " << m
            << "\n" << std::endl;

            //output for the equation of the line
            std::cout << "With the Y-Intercept and slope found, we can write the equation for the line: "
            << std::endl;

            if (b >= 0) { //if b is positive, use plus sign in equation

                if (m == 0) { //if line is horizontal, write equation accordingly as y = b
                    std::cout << "(Since it is horizontal, it is in the form y = b)" << std::endl;
                    std::cout << "y = " << b << "\n" << std::endl;
                } else {
                    std::cout << "(Since it is not horizontal, it is in the form y = mx + b)" << std::endl;
                    std::cout << "y = " << m << "x + " << b << "\n" << std::endl;
                }
            } else { // if b is negative, change to minus sign in equation and make b positive

                if (m == 0) {//if line is horizontal, b can be left negative and be written in form y = b
                    std::cout << "(Since it is horizontal, it is in the form y = b)" << std::endl;
                    std::cout << "y = " << b << "\n" << std::endl;
                } else {
                    std::cout << "(Since it is not horizontal, it is in the form y = mx + b)" << std::endl;
                    std::cout << "y = " << m << "x - " << fabsf(b) << "\n" << std::endl;
                }
            }

            additionalInfo(line); // dist and angle of line

            //asking user if they would like to calculate another line and assigning
            //answer to conditional variable for loop, anything but 'Y' ends loop
            std::cout << "Would you like to calculate another line? (Y/N):";
            std::cin >> calcYN;
            std::cout << std::endl;
        }
    }while(calcYN == 'Y' || calcYN == 'y');


    return 0;
} //end main


/**
 * Inputting coordinates of a point
 * @return - Point object from user assigned coordinates
 */
Point getPoint() {
    Point pt;
    std::cout << " - Enter the x coordinate for this point:";
    std::cin >> pt.xCoor;

    std::cout << " - Enter the y coordinate for this point:";
    std::cin >> pt.yCoor;
    std::cout << std::endl;
    return pt;
}//end getPoint

/**
 * Writing a given point in ordered pair form
 * @param p - Point object to enter x and y values into string
 * @return - the ordered pair (x, y) from given point as a string
 */
std::string displayPoint(Point p) {
    std::string pt = "(" + std::to_string(p.xCoor) + ", " + std::to_string(p.yCoor) + ")";

    return pt;
}//end displayPoint


/**
 * Calculating the slope of a given line
 * @param line - a line struct with points assigned by user
 * @return - the value of the slope of the given line as a float (change in y/change in x)
 */
float getSlope(LinePoints line) {
    float slope;

    //find difference in y coordinates
    float yDiff = (line.p2.yCoor) - (line.p1.yCoor);

    //find difference in x coordinates
    float xDiff = (line.p2.xCoor) - (line.p1.xCoor);

    //divide the two differences, y on top, x on bottom
    slope = (float)yDiff/(float)xDiff;

    return slope;
}//end getSlope

/**
 * Calculating where the line crosses the y axis
 * @param line - a line struct with points assigned by user
 * @return - the value for y where the given line crosses the y axis as a float
 */
float getY_Intercept(LinePoints line) {
    float yInt;

    yInt = (float)line.p1.yCoor - (getSlope(line) * (float)line.p1.xCoor);

    return yInt;
}//end getY_Intercept

/**
 * Calculating the distance between the two given points of the line
 * @param line - a line struct with points assigned by user
 * @return - the value for the distance between the 2 points as a float
 */
float getLineLength(LinePoints line) {
    float length;

    float xDiff = line.p2.xCoor - line.p1.xCoor;//calculate the change in x
    float yDiff = line.p2.yCoor - line.p1.yCoor;//calculate the change in y

    //input xDiff and yDiff into distance formula
    length = (float)sqrt((pow(xDiff, 2)) + (pow(yDiff, 2)));

    return length;
}//end getLineLength

/**
 * Calculating the angle of the line in degrees
 * @param line - a line struct with points assigned by user
 * @return - a float value for the angle of the line in degrees
 */
float getLineAngle(LinePoints line) {
    float angle;

    float xDiff = line.p2.xCoor - line.p1.xCoor;//calculate the change in x
    float yDiff = line.p2.yCoor - line.p1.yCoor;//calculate the change in y

    //calculate angle with xDiff and yDiff and the arctan function, and change from radians to degrees
    angle = std::abs((atan2f(yDiff, xDiff)) * (180/M_PI));

    //making sure it measures the angle from the right, not left (output obtuse side when slope < 0)
    if (getSlope(line) < 0) {
        return (180 - angle);
    } else {
        return angle;
    }
}//end getLineAngle

/**
 * Displaying the additional information of the line (length/distance & angle of line)
 * @param line - a line struct with points assigned by user
 */
void additionalInfo(LinePoints line) {
    std::cout << "Additional Information: " << std::endl;
    //output for the length of the line
    std::cout << " - The distance between the two given points is " << getLineLength(line) << std::endl;

    //output for the angle of the line
    std::cout << " - The angle of the line is " << getLineAngle(line) << " degrees" << "\n" << std::endl;

}// end additionalInfo





















