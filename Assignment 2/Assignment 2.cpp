#include <iostream>
#include <iomanip>


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

	char guessArray[Rows][Columns];
	char answer;

	do
	{
		initializeArray(guessArray);
		displayArray(guessArray);
		populateArray(guessArray);
		coutGameRules();
		gameLogic(guessArray);

		cout << "Do you want to play again? Enter 'Y' or 'N' " << endl;
		cin >> answer;

		if (answer == 'Y')
		{
			remainingGuesses = 5; // Reset amount of guesses
		}

		else if (answer == 'N')
		{
			break;
		}

	} while (answer == 'Y' || answer == 'N'); // Execute the code if user enters 'Y' or 'N'

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
	cout << "   "; // Adding 3 spaces to the top row ... formatting before the Column Labels, so they align with the columns in the array
	for (columns = 0; columns < Columns; columns++)
	{
		cout << setw(3) << columns + 1; // Since arrays start at 0, we add 1
	}
	cout << endl;
	cout << "  " << "--------------------------" << endl;

	for (rows = 0; rows < Rows; rows++)
	{
		cout << " " << rows + 1 << "|"; // Since arrays start at 0, we add 1
		for (columns = 0; columns < Columns; columns++)
		{
			cout << setw(3) << guessArray[rows][columns]; // Helps display the array with spacing to be more readable
		}
		cout << endl;
	}

	cout << "  " << "--------------------------" << endl;

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
	cout << "**" << "      and 1 bomb!     " << "**" << endl;
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

//place gold and bomb array secretly
int populateArray(char guessArray[Rows][Columns])
{
	int inputBombCounter = 0;
	int x, y;
	int inputGoldcounter = 0;
	srand(time(NULL)); // initiaze random seed


	do
	{
		x = rand() % Rows; // generate x numbers in rows
		y = rand() % Columns; // generate y numbers in columns 

		if (guessArray[x][y] != 'G')
		{
			guessArray[x][y] = 'G'; // Input 'G' for Gold in the random (x,y) coordinate
			inputGoldcounter++;
		}
	} while (inputGoldcounter < 5);

	do
	{
		x = rand() % Rows; // generate random 'x' numbers in rows
		y = rand() % Columns; // generate random 'y' numbers in columns 

		if (guessArray[x][y] != 'G') // return to the beginning of the loop if random rows and columns equal to 'G'
		{
			guessArray[x][y] = 'B'; // Input 'B' for Bomb in the random (x,y) coordinate
			inputBombCounter++;
		}
	} while (inputBombCounter < 1);

	return 0;
}


int gameLogic(char guessArray[Rows][Columns])
{
	int point = 0;
	int guessRow, guessColumn; // guess Rows and guess Columns

	do
	{
		cout << "Enter x coordinates: ";
		cin >> guessRow;

		while (!cin || guessRow > 8 || guessRow < 1)
		{
			cout << "Please enter the correct coordinates: ";
			cin.clear();
			cin.ignore();
			cin >> guessRow;
		}

		guessRow--;
		cout << endl;
		cout << "Enter y coordinates: ";
		cin >> guessColumn;

		while (!cin || guessColumn > 8 || guessColumn < 1)
		{
			cout << "Please enter the correct coordinates: ";
			cin.clear();
			cin.ignore();
			cin >> guessColumn;
		}

		guessColumn--;
		cout << endl;


		if (guessArray[guessRow][guessColumn] == 'G')
		{
			cout << "You FOUND GOLD!!" << "You've added an extra guess and now you have" << remainingGuesses << " guesses to go! ";
			guessArray[guessRow][guessColumn] == 'F'; // let's user whether they found the gold

			point += 1;
			cout << endl;
			cout << endl;
			continue; // return to the beginning of the loop
		}

		else if (guessArray[guessRow][guessColumn] == 'B')
		{
			cout << endl;
			cout << "BOMB! Game Over." << endl << endl;
			break; // lose the game
		}

		else
		{
			cout << "No Gold. Too Bad, So Sad!!" << endl;
			remainingGuesses--;
			cout << "Too Bad..." << remainingGuesses << " guesses to go!" << endl;
		}
	} while (remainingGuesses > 0);

	cout << "You've earned " << point << " points! " << endl;
	cout << "Better luck next time!!" << endl;

	cout << "Here's your board:" << endl << endl;

	for (guessColumn = 0; guessColumn < Columns; guessColumn++)
	{
		for (guessRow = 0; guessRow < Rows; guessRow++)
		{
			if (guessArray[guessRow][guessColumn] == '?')
			{
				guessArray[guessRow][guessColumn] = '  ';
			}
		}
	}

	cout << "   ";
	for (guessColumn = 0; guessColumn < Columns; guessColumn++)
	{
		cout << setw(3) << guessColumn + 1;  // add 1 since we start at 0
	}
	cout << endl;
	cout << " " << "-------------------------" << endl;

	for (guessRow = 0; guessRow < Rows; guessRow++)
	{
		cout << " " << guessRow + 1 << "|"; // add 1 since we start at 0
		for (guessColumn = 0; guessColumn < Columns; guessColumn++)
		{
			cout << setw(3) << guessArray[Rows][Columns];  // displays the array so the spacing can be more readable
		}
		cout << endl;
	}
	cout << " " << "-------------------------" << endl;

	return 0;
}
