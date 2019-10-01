#include <iostream>

using namespace std;

const int Rows = 8;
const int Columns = 8;
int remainingGuesses = 5; // users guesses till they reach the maxiumm guess

int main()
{
	// Method Declaration
	int initializeArray(char guessArray[Rows][Columns]);
	int displayArray(char guessArray[Rows][Columns]);
	int populateArray(char guessArray[Rows][Columns]);
	int coutGameRules();
	int gameLogic(char guessArray[Rows][Columns]);

	do
	{
		initializeArray(guessArray);  
		displayArray(guessArray);
		populateArray(guessArray);
		coutGameRules();
		gameLogic(guessArray); 

		cout << "Do you want to play again? Enter 'Y' or 'N' " << endl;
		cin >> answer; 

		if (answer == 'Y' || answer == 'N')
		{
			remainingGuesses = 5; // Reset amount of guesses
		}
	} while (answer == 'Y' || answer == 'N'); // Execute the code if user enters 'Y' or 'N'

	return 0; 
}

//
int initializeArray(char guessArray[Rows][Columns])
{
	int rows, columns;

	remainingGuesses = 5;

	for (rows = 0; rows < Rows; rows++)
	{
		for (columns = 0; columns < Columns; columns++)
		{
			guessArray[rows][columns] = '?'; 
		}
	}
	return 0;
}

// First iterate the array and place question marks in every position
int initializeArray(char guessArray[Rows][Columns])
{
	int rows, columns;

	remainingGuesses = 5;

	for (rows = 0; rows < Rows; rows++)
	{
		for (columns = 0; columns < Columns; columns++)
		{
			guessArray[rows][columns] = '?'; 
		}
	}
	return 0;
}

// Secondly print the array onto the console
int displayArray(char guessArray[Rows][Columns])
{
	int rows, columns;
	cout << endl;
	cout << "  "; // Adds 2 space to the top row
	for (columns = 0; columns < Columns; columns++)
	{
		cout << setw(2) << columns + 1;  // add 1 since we start at 0
	}
	cout << endl;
	cout << "-------------------------" << endl;
	for (rows = 0; columns < Rows; rows++)
	{
		cout << " " << rows + 1 << "|"; // add 1 since we start at 0
		for (columns = 0; columns < Columns; columns++)
		{
			cout << setw(2) << guessArray[Rows][Columns];  // displays the array so the spacing can be more readable
		}
	}
	cout << "-------------------------" << endl;
	return 0;
}

// Thirdly explain the rules
int coutGameRules()
{
	cout << "**" << "**********************" << "**" << endl;
	cout << "**" << "                      " << "**" << endl;
	cout << "**" << "       Find Gold!     " << "**" << endl;
	cout << "**" << "                      " << "**" << endl;
	cout << "**" << "   You have 5 guesses " << "**" << endl;
	cout << "**" << "                      " << "**" << endl;
	cout << "**" << "     You have...      " << "**" << endl;
	cout << "**" << "    5 pieces of gold  " << "**" << endl;
	cout << "**" << "       and 1 bomb!    " << "**" << endl;
	cout << "**" << "                      " << "**" << endl;
	cout << "**" << "        Have Fun      " << "**" << endl;
	cout << "**" << "           and        " << "**" << endl;
	cout << "**" << "        Good Luck!    " << "**" << endl;
	cout << "**" << "                      " << "**" << endl;
	cout << "**" << "**********************" << "**" << endl;
	cout << endl;
	cout << endl;

	return 0;
}

//
int populateArray(char guessArray[Rows][Columns])
{
 
}

