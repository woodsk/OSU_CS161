/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/25/14
 *  Last Modification Date: 11/30/14
 *  Filename: geom.cpp
 *
 *  Overview:
 *          This program will prompt the user to enter x and y coordinates
 *          for two points. The program will then create a line connecting each
 *          point. The program will return the new line's length and slope.
 *
 *  Input:
 *          The input will be 4 integers. The first two integers are the x
 *          and y coordinates for the first point. The next two are the x and
 *          y coordinates for the second point.
 *
 *  Output:
 *          The outputs are double values for the line's length and slope.
 *
******************************************************************************/

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

class Point
{
    private:
	int x;
	int y;

    public:
	double distanceTo (const Point&);
        int getX() const
        {
            return x;
        }

        int getY() const
        {
            return y;
        }

        // Point constructor
        Point (double x = 0, double y = 0)
        {
            this->x = x;
            this->y = y;
        }
};

// calculate distance between points
double Point::distanceTo (const Point &point)
{
    double dx = static_cast <double> (x - point.getX());
    double dy = static_cast <double> (y - point.getY());

    //distance is sqrt(dx^2 + dy^2)
    return sqrt(pow(dx, 2) + pow(dy, 2));
}


class LineSegment
{
    private:
        Point pt1;
        Point pt2;

    public:
	// length of the line segment
        double length ()
        {
            return pt1.distanceTo(pt2);
        }

        // slope of the line segment
        double slope () const
        {
            double dx = static_cast <double> (pt1.getX() - pt2.getX());
            double dy = static_cast <double> (pt1.getY() - pt2.getY());
            return dy/dx;
        }

        // LineSegment constructor
        LineSegment (Point pt1, Point pt2)
        {
            this->pt1 = pt1;
            this->pt2 = pt2;
        }
};

int main ()
{
    int x1, y1, x2, y2;
    char again = 'y';

    do
    {
        cout << endl << "Enter the coordinates for two points below." << endl;
	cout << "Point 1 (x): ";
	cin >> x1;

	cout << "Point 1 (y): ";
	cin >> y1;

	cout << "Point 2 (x): ";
        cin >> x2;

        cout << "Point 2 (y): ";
        cin >> y2;

	// create LineSegment object
	LineSegment segment(Point(x1, y1), Point(x2, y2));

        cout << endl << "The line segment's length is: " << segment.length() 
        << endl;
	cout << "The line segment's slope is: ";

	//vertical line
	if (isinf(segment.slope()))
        {
  	    cout << "vertical.";
	}
	else
	{
	    cout << segment.slope();
	}

	cout << endl << "Repeat? Enter 'y' for yes, anything else for no."
	<< endl;
	cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
