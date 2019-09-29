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

//
int displayArray(char guessArray[Rows][Columns])
{
	
	return 0;
}

