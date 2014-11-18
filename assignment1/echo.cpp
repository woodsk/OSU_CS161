/* 
 * Author: Kevin Woods
 * Date: 10/2/14
 * Description:This program will prompt the user to input a value. The program
 * 		will then "echo" or print this input as output on the screen.
 * 	
*/

#include <iostream>

int main()
{
   int input_value;
    
   std::cout<<"Enter your favorite number: ";
   std::cin>>input_value;
   std::cout<<"Your favorite number is: "<<input_value<<std::endl;

  return 0
}
