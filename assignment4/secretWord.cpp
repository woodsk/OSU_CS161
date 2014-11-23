/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/22/14
*   Last Modification Date: 10/26/14
*   Filename: secretWord.cpp
*
*   Overview: This program will ask the user if they want to play the secret
*   word game. The game will then prmopt player 1 to enter a word. The game
*   will hide this word from player 2, and ask them to guess one letter at a
*   time. The correct guessed will be shown in the correct position, and
*   the number of guesses will print to the screen. The game will continue
*   until the word is guess, or guesses is 0.
*
*   Input: The first input will be a string, accepted as the secret word. The
*   inputs will be inslge letter guesses by player 2. Non-letters will result
*   in an error message. FInally, there will be a repeat input.

*   Output: The output will ask the suer to enter a secret word. Next the screen
*   is cleared. The output will show the word with correct letters guesses,
*   number of guesses left, and a prompt to enter a new guess. One the word is
*   guess or guesses equals 0, the game ends and the secret word is revealed.
*
******************************************************************************/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        string secretWord, displayWord, letterGuess, badGuess;
        bool correctGuess = 0;
        int guess = 0, i = 0, winGuess = 0;

        cout << "Secret Word Game!" << endl;
        cout << "Player 1, enter your secret word." << endl;
        getline(cin, secretWord);

        for (i = 0; i < secretWord.length(); i++)
        {
            while (!isalpha(secretWord.at(i)))
            {
                cout << "Please use letters only. Re-enter the secret word." << endl;
                cin.clear();
                cin.ignore();
                getline(cin, secretWord);
            }
        }

        displayWord = secretWord;

        for (i = 0; i < secretWord.length(); i++)
        {
            if (isalpha(displayWord.at(i)))
                displayWord[i] = '-';
        }

        guess = secretWord.length()*2;
        cout << string(100, '\n');  

        cout << "Player 2, attempt to guess the word by guessing one ";
        cout << "letter at a time." << endl;
        cout << "You have " << guess<< " guesses." << endl;
        cout << "The secret word has " << secretWord.length() << " letters. ";
        cout << displayWord << endl;
        cout << "Please guess a letter." << endl;

        while (guess > 0 && displayWord != secretWord)
        {
            cin >> letterGuess;
            while (!isalpha(letterGuess.at(0)) || (letterGuess.length() != 1))
            {
                cout << "Please only guess one letter." << endl;
                cin.clear();
                cin.ignore();
                cin >> letterGuess;
            }

            --guess;

            for (i = 0; i < secretWord.length(); i++)
            {
                if (letterGuess.at(0) == secretWord.at(i))
                {
                    displayWord.at(i) = secretWord.at(i);
                    correctGuess = 1;
                }
            }
            if (correctGuess == 1)
            {
                cout << "Good guess!" << endl;
                correctGuess = 0;
            }
            

	    else
            {
                badGuess = badGuess + ' ' + letterGuess.at(0) + ' ';
            }

            cout << "You have " << guess << " guesses left." << endl;
            cout << "Letters guessed: " << badGuess << endl;
            cout << "Guess a letter in the secret word: " << displayWord << endl;
        }

        if (displayWord == secretWord)
        {
            winGuess = ((secretWord.length() *2) - guess);

            cout << "Congratulations! You guessed the secret word in "
            << winGuess << " tries!" << endl;

        }
        else
	{
            cout << "Sorry, you are out of guesses. The secret word was " <<
            secretWord << "." << endl;
	}

        cout << "Would you like to play again? (y/n)" << endl;
        cin >> again;

        cin.clear();
        cin.ignore(100, '\n');
    
    }

    return 0;
}
