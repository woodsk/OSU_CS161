/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/11/14
 * Last Modification Date: 10/12/14
 * Filename: numGuess.cpp
 *
 * Overview: 
 * 	This program is a game with 2 players. Player 1 enters a secret number
 * 	between 1 and 100. PLayer 2 then has 3 attempt to guess the number. 
 * 	Number of attempts and the guess range will be given prior to each 
 * 	guess. If player 2 guesses correctly, the game congratulates the user.
 * 	When the game is over, the game will ask to play again. A yes entry
 * 	will restart the game, a no entry will end the program. 
 *
 * Input:
 *	The input from player 1 will be a whole number between 1 and 100.
 *	The input from player 2 will be a whole number. Player 2 guesses
 *	until the number is guessed or 3 attempts are used.
 *	The final input is 1 or 0, 1 to play again or 0 to end the game.
 *
 * Output:
 *	Ex.
 *	Enter secret number: 30
 *	(lines clear) 
 *	Attempts left: 3
 *	Guess: 20
 *	Too low, GUess between 21-100
 *	Attempts left: 2
 *	Guess: 30
 *	Congratulations! 
 *	Play again? Enter 1 for yes 0 for no.
 * ***************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
   int repeat = 1;
//would repeat = 0 also work?
   
   do
   {
      int secretNumber;

      cout << "Welcome to the guessing game!" << endl;
      cout << "Player 1 will select the secret number." << endl;
      cout << "Player 2 will have 3 chances to guess the number." << endl;
      cout << "Player 1: Enter a whole number between 1 and 100." << endl;
      cin >> secretNumber;
  
      cout << string(100, '\n');
// to clear lines

      cout << "Player 2: The secret number is between 1 and 100." << endl;

      int guess, attempts = 3, min = 1, max = 100;
// should max and min be declared after each if statement? guesses can still 
// fall outside of range     
   
      while (attempts > 0) 
      {
         cout << "Attmepts remaining: " << attempts << endl;
         cout << "Guess the secret number: " << endl;
         cin >> guess;
         cout << "You guessed: " << guess << endl;
	
         if (guess == secretNumber)
         {
            cout << "Congratulations! You guessed the secret number!" << endl;
            attempts = 0;
         }
         
         else if (guess > secretNumber)
         {   
            cout << "Your guess was too high!" << endl;
            max = guess;
            cout << "The secret number is between " << min << " and "
            << max - 1 << "." << endl;
            attempts--;
         }
         
         else
         {   
            cout << "Your guess was too low!" << endl;
            min = guess;
            cout << "The secret number is between " << min + 1 << " and " 
            << max << "." << endl;
            attempts--;
         }   
         
      }
//should move this so it doesn't repeat if guessed correctly      
      
      cout << "You are out of attempts!" << endl;
      cout << "The secret number was " << secretNumber << "." << endl;
      
      cout << string(5, '\n');
      
      cout << "Would you like to play again? Enter 1 for yes and 0 for no: ";
      cin >> repeat;
      
      cout << string (100, '\n');
     
   } while (repeat == 1);
// no way to prevent invalid entries
       
cout << "The game is over!" << endl; 
  
return 0;

}
