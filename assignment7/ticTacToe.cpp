/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/15/14
 *  Last Modification Date: 11/16/14
 *  Filename: ticTacToe.cpp
 *
 *  Overview:
 *      This program is a Tic Tac Toe game for 2 PLayers. The user must enter
 *      the number of games they would like to play as a command line argument.
 *      The game ends when someone wins or there is a tie.
 *
 *  Input:
 *      The first input for the program will be an integer entered as a command
 *      line argument for the number of games the user wants to play. The next
 *      the next inputs will be moves by player 1 or 2. The player will enter
 *      a number bettween 1 and 9 that corresponds with the space they wish to
 *      mark.
 *
 *  Output:
 *      The initial output for the program is the game board and initla rules.
 *      The ouput after each move will either be an error if the player did not
 *      choose an available space, or the ouput will be the next player's turn.
 *      Once there is a winner, the game will pronounce the winner. If the game
 *      ends in a tie, the game will say so.
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

//create board array
char boardArray[0][3];

void displayGame();

int winGame();

int main(int argc, char *argv[])
{

    boardArray[0][0] = '1';
    boardArray[0][1] = '2';
    boardArray[0][2] = '3';
    boardArray[1][0] = '4';
    boardArray[1][1] = '5';
    boardArray[1][2] = '6';
    boardArray[2][0] = '7';
    boardArray[2][1] = '8';
    boardArray[2][2] = '9';

    int gameNumber;

    //command line validation
    if(argc == 1)
    {
        gameNumber = 1;
    }

    else
    {
        gameNumber = atoi(argv[1]);
    }

    do
    {
	int i;

        //begin with player 1
        int playerNumber = 1;

	do
	{
	    displayGame();
		
            int play;

	    playerNumber = (playerNumber % 2) ? 1 : 2;

	    cout << "Player Number " << playerNumber << "'s turn:  ";

	    //input valiation from old exercises, not perfect
            while (! (cin >> play))
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error! Please enter an available space: " << endl;
            }

	    char boardSpace = (playerNumber == 1) ? 'X' : 'O';

	    if (play == 1 && boardArray[0][0] == '1')
            {
		boardArray[0][0] = boardSpace;
            }

            else if (play == 2 && boardArray[0][1] == '2')
            {
                boardArray[0][1] = boardSpace;
            }
	    
            else if (play == 3 && boardArray[0][2] == '3')
            {
                boardArray[0][2] = boardSpace;
            }

	    else if (play == 4 && boardArray[1][0] == '4')
            {
                boardArray[1][0] = boardSpace;
            }

	    else if (play == 5 && boardArray[1][1] == '5')
            {
                boardArray[1][1] = boardSpace;
            }

	    else if (play == 6 && boardArray[1][2] == '6')
            {
                boardArray[1][2] = boardSpace;
            }

	    else if (play == 7 && boardArray[2][0] == '7')
            {
                boardArray[2][0] = boardSpace;
            }

            else if (play == 8 && boardArray[2][1] == '8')
            {
                boardArray[2][1] = boardSpace;
            }

	    else if (play == 9 && boardArray[2][2] == '9')
            {
                boardArray[2][2] = boardSpace;
            }

	    //input validation
    	    else
	    {
		cout << "Error! Please enter an available space: ";
		playerNumber--;
		cin.ignore();
		cin.get();
	    }

	    i = winGame();
	    playerNumber++;

	} while (i == -1);

	displayGame();
        
        int ties = 0, wins1 = 0, wins2 = 0;
	if (i == 1)
        {
            cout << "Game Over! Player " << --playerNumber << " wins!" << endl;
            
            if (playerNumber == 1)
            {
                wins1++;
            }
            else
            {
                wins2++;
            }
	}
	
	else
        {
            cout << "Game Over! It was a tie!" << endl;
            ties++;
        }

        cout << "Player 1 has " << wins1 << " wins." << endl;
        cout << "Player 2 has " << wins2 << " wins." << endl;
        cout << "There have been " << ties << " ties." << endl;

	cin.ignore();
	cin.get();

	gameNumber--;

	boardArray[0][0] = '1';
        boardArray[0][1] = '2';
        boardArray[0][2] = '3';
        boardArray[1][0] = '4';
        boardArray[1][1] = '5';
        boardArray[1][2] = '6';
        boardArray[2][0] = '7';
        boardArray[2][1] = '8';
        boardArray[2][2] = '9';

    } while(gameNumber > 0);


    return 0;
}

int winGame()
{
    //top row win
    if (boardArray[0][0]  == boardArray[0][1] &&
        boardArray[0][1]  == boardArray[0][2])
    {
        return 1;
    }

    //middle row win
    else if (boardArray[1][0]  == boardArray[1][1]  &&
            boardArray[1][1]  == boardArray[1][2])
    {
        return 1;
    }

    //bottom row win
    else if (boardArray[2][0]  == boardArray[2][1] &&
            boardArray[2][1] == boardArray[2][2])
    {
        return 1;
    }

    //first column win
    else if (boardArray[0][0]  == boardArray[1][0] &&
            boardArray[1][0] == boardArray[2][0])
    {
        return 1;
    }

    //second column win
    else if (boardArray[0][1]  == boardArray[1][1]  &&
            boardArray[1][1]  == boardArray[2][1])
    {
        return 1;
    }

    //third column win
    else if (boardArray[0][2] == boardArray[1][2] &&
            boardArray[1][2] == boardArray[2][2])
    {
        return 1;
    }

    //first diagonal win
    else if (boardArray[0][0]  == boardArray[1][1]  &&
            boardArray[1][1]  == boardArray[2][2])
    {
        return 1;
    }

    //second diagonal win
    else if (boardArray[0][2] == boardArray[1][1] &&
            boardArray[1][1] == boardArray[2][0])
    {
        return 1;
    }

    //tie game
    else if (boardArray[0][0] != '1' && boardArray[0][1] != '2' &&
            boardArray[0][2] != '3' && boardArray[1][0]  != '4' &&
            boardArray[1][1]  != '5' && boardArray[1][2]  != '6'&&
            boardArray[2][0]  != '7' && boardArray[2][1] != '8' &&
            boardArray[2][1] != '9')
    {
        return 0;
    }

    //keep game going
    else
    {
        return -1;
    }
}

void displayGame()
{
    cout << endl << "Tic Tac Toe Game!" << endl;

    cout << endl << "..................." << endl;
    cout << ":     :     :     :" << endl;
    cout << ":  " << boardArray[0][0] << "  :  " << boardArray[0][1];
    cout << "  :  " << boardArray[0][2] << "  :" << endl;

    cout << "......:.....:......" << endl;
    cout << ":     :     :     :" << endl;

    cout << ":  " << boardArray[1][0] << "  :  " << boardArray[1][1];
    cout << "  :  " << boardArray[1][2] << "  :" << endl;

    cout << "......:.....:......" << endl;
    cout << ":     :     :     :" << endl;

    cout << ":  " << boardArray[2][0] << "  :  " << boardArray[2][1];
    cout << "  :  " << boardArray[2][2] << "  :" << endl;

    cout << ":.....:.....:.....:" << endl << endl;

    cout << endl << "Player 1 is X" << endl;
    cout << endl << "Player 2 is O" << endl << endl;
    cout << "Enter the number of the space you want to mark." << endl << endl;
}
