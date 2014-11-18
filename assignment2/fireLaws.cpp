/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/9/14
 * Last Modification Date: 10/12/14
 * Filename: fireLaws.cpp
 *
 * Overview: 
 * 	This program will read a capacity and number of people to determine
 *  	if the meeting is too large. The program will also say how many 
 *  	more/less people can attend the meeting.
 *
 * Input:
 * 	The input will be two whole numbers.
 * 	Ex.
 * 	Capacity: 100
 * 	People: 50
 *
 * Output:
 * 	The output will either say the meeting is illegal and illegal. If legal,
 * 	it will say how many more people can attend. If illegal, it will say how
 * 	many people can't attend.
 *
 *****************************************************************************/

#include <iostream>
#include <cmath>

int main()
{
   int capacity, people;
   
   std::cout << "Meeting Legality Check\n";
   std::cout << "What is the building capacity?\n";
   std::cin >> capacity;
   std::cout << "How many people will attend the meeting?\n";
   std::cin >> people;
   
   if (capacity >=  people)
   {   
      std::cout << "Your meeting is legal!\n";
      std::cout << "You can bring " << capacity - people;
      std::cout << " more people to the meeting\n";
   }
   else
   { 
      std::cout << "This meeting it illegal!\n";
      std::cout << "You need to reduce the amount of people by ";
      std::cout << people - capacity << std::endl;
   }
   return 0;

}

