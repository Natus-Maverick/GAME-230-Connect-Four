//GAME 230 Project 2
//Project Name:Connect Four
//Author Name: Runze Guo
//Completed all Normal Mode objectives and objective I and J in Hard Mode, and made improvement to objective I.
//Since if the win_size was larger than row or column size would cause a 100% draw game, 
//Program considers the win_size over row or colunm size is invalid.
//Date: Oct 12, 2017


#include <iostream>
#include <string>


using namespace std;
void board(); //print table
int drop(int x, char symbol);	//drop to colunm x
bool check(int x, int y, char s, char wrap);	//check winner
char table[20][20];	//save board
int x = 0;	//colunm
int y = 0;	//line
char again; //new game check
int row_size = 6;	//set size of the board
int column_size = 7;
int win_size = 4;
char wrap;

void board()		//print the board
{
	cout << " ======Connect Four======\n";		//Title, column number, contents and frame
	cout << "  ";
	for (int num = 1; num <= column_size; num++)
	{
		cout << "  " << num;
	}
	cout << "  \n --";
	for (int num = 1; num <= column_size; num++)
	{
		cout << "---";
	}
	cout << "-\n";

	for (int a = 0; a < row_size; a++)
	{
		cout << "\044 ";
		for (int b = 0; b < column_size; b++) cout  << "  " << table[a][b];
		cout <<  "   \044\n";
	}
	cout << " --";
	for (int num = 1; num <= column_size; num++)
	{
		cout << "---";
	}
	cout << "-\n";
}

int main()		//main function
{
	cout << "Sizing the board and numbers to win:\n";
	cout << "Number of rows (4-20):";					//Choose size of row
	cin >> row_size;
	while ( cin.fail() || row_size < 4 || row_size >20)
	{
		cout << "Please enter a valid number (4-20):";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> row_size;
	}
	cout << "Number of columns (4-20):";				//Choose size of column
	cin >> column_size;
	while (cin.fail() || column_size < 4 || column_size >20)
	{
		cout << "Please enter a valid number (4-20):";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> column_size;
	}
	cout << "Require to win (3-20):";					//Choose the length to win
	cin >> win_size;
	while (cin.fail() || win_size < 3 || win_size >20 || win_size > row_size || win_size > column_size)		//Also avoid the win_size being larger than row or column size, even if it is not mentioned in Hard Mode "Objective I".
	{
		cout << "Please enter a valid number (3-20):";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> win_size;
	}
	char w;
	cout << "Enable wrap around mode? (Y/N):\n";					//Choose enable wrap around mode
	cin >> w;
	while (w != 'y' && w != 'Y' && w != 'n' && w != 'N')
	{
		cout << "Please enter Y/y or N/n!\nEnable wrap around mode? (y/n):\n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> w;
	}
	for (int i = 0; i < row_size; i++)		//empty the board
	{
		for (int j = 0; j < column_size; j++)
		{
			table[i][j] = 'I';
		}
	}
	while (check(x, y, 'O', w) != true)		//Player 1 goes with "X", check win condition for Player 2 before player 1's turn.
	{
		board();
		int top = 0;
		while (table[0][top] != 'I')		//Check if the board is full (draw) before drop
		{
			top++;
			if (top < column_size)
			{
				continue;
			}
			else if (top = column_size)
			{
				cout << "Draw!\n";			//Declare draw
				cout << "Another game?(y/n):\n";	//Ask for a new game
				cin >> again;
				while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')	//Check if the input is valid
				{
					cout << "Please enter Y/y or N/n!\nAnother game? (y/n):\n";	
					cin >> again;
				}
				if (again == 'y' || again == 'Y')		//If yes, clear the command line window and restart the main function.
				{
					system("cls");
					main();
				}
				else if (again == 'n' || again == 'N')	//If no, show thanks message and wait for exit.
				{
					cout << "Thanks for playing Connect Four!\n";
					system("pause");
					return 0;
				}
			}
		}

		cout << "Player 1's turn, enter the column number (1-" << column_size << ") : \n";
		cin >> x;
		while (cin.fail() || x < 1 || x > column_size || table[0][x - 1] != 'I')		//Check if the input is not a integer, over range, or the column is full
		{
			if (cin.fail() || x < 1 || x > column_size)
			{
				cout << "Please enter a valid number (1-" << column_size << "): \n";
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> x;
			}
			else if (table[0][x - 1] != 'I')
			{
				cout << "Column is FULL! Please enter a valid number (1-" << column_size << ") :\n";
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> x;
			}
		}
		y = drop(x, 'X');		//If the drop if valid, record the row it was dropped
		if (check(x, y, 'X', w) != true)		//Check win condition for Player 1 before Player 2's turn.
		{
			board();
			if (table[0][0] != 'I' && table[0][1] != 'I' && table[0][2] != 'I' && table[0][3] != 'I' && table[0][4] != 'I' && table[0][5] != 'I' &&table[0][6] != 'I')
			{
				cout << "Draw!\n";
				cout << "Another game?(y/n):\n";
				cin >> again;
				while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
				{
					cout << "Please enter Y/y or N/n!\nAnother game? (y/n):\n";
					cin >> again;
				}
				if (again == 'y' || again == 'Y')
				{
					system("cls");
					main();
				}
				else if (again == 'n' || again == 'N')
				{
					cout << "Thanks for playing Connect Four!\n";
					system("pause");
					return 0;
				}
			}
			cout << "Player 2's turn, enter the column number (1-" << column_size << ") : \n";
			cin >> x;
			while (cin.fail() || x < 1 || x > column_size || table[0][x - 1] != 'I')
			{
				if (cin.fail() || x < 1 || x > column_size)
				{
					cout << "Please enter a valid number (1-" << column_size << "): \n";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> x;
				}
				else if (table[0][x - 1] != 'I')
				{
					cout << "Column is FULL! Please enter a valid number (1-" << column_size << ") :\n";
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> x;
				}
			}
			y = drop(x, 'O');
		}
		else
		{
			board();
			cout << "Player 1 won!\n";			//Declare Player 1's victory
			cout << "Another game?(y/n):\n";
			cin >> again;
			while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
			{
				cout << "Please enter Y/y or N/n!\nAnother game? (y/n):\n";
				cin >> again;
			}
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				main();
			}
			else if (again == 'n' || again == 'N')
			{
				cout << "Thanks for playing Connect Four!\n";
				system("pause");
				return 0;
			}
		}
	}
	board();
	cout << "Player 2 won!\n";		//Declare Player 2's victory
	cout << "Another game?(y/n)\n";
	cin >> again;
	while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
	{
		cout << "Please enter Y/y or N/n!\nAnother game? (y/n):\n";
		cin >> again;
	}
	if (again == 'y' || again == 'Y')
	{
		system("cls");
		main();
	}
	else if (again == 'n' || again == 'N')
	{
		cout << "Thanks for playing Connect Four!\n";
		system("pause");
		return 0;
	}
	return 0;
}

int drop(int x, char symbol)		//Drop symbol "X" or "O" in column x, and return the number of row it was dropped
{
	int k;
	for (k = row_size; k > 0; k--)
	{
		if (table[k-1][x-1] == 'I')
		{
			table[k-1][x-1] = symbol;
			break;
		}
		else
		{
			continue;
		}
	}
	return k;
}

bool check(int x, int y, char s, char wrap)		//Check if "X" or "O" (declared by char s) win the game.
{
	int horizonal = 0;
	int vertical = 0;
	int diagonalL = 0;
	int diagonalR = 0;
	int line;
	int colunm;
	char table_check[39][39];			//Maximun size is 39
	if (wrap == 'Y' || wrap == 'y')
	{
		for (int ri = 0; ri < row_size; ri++)	//Copy the board to check board.
		{
			for (int ci = 0; ci < column_size; ci++)		//At the original positions.
			{
				table_check[ri][ci] = table[ri][ci];
			}
			for (int ci = column_size; ci < column_size + win_size - 1; ci++)	//Connect the front columns with the last column to make a warp around check.
			{
				table_check[ri][ci] = table[ri][ci - column_size];
			}
		}
	}
	else
	{
		for (int ri = 0; ri < row_size; ri++)	//Copy the board to check board.
		{
			for (int ci = 0; ci < column_size; ci++)		//At the original positions.
			{
				table_check[ri][ci] = table[ri][ci];
			}
		}
	}
	for (colunm = x - 1; table_check[y - 1][colunm] == s && colunm <= 6; colunm--, horizonal++);
	for (colunm = x; table_check[y - 1][colunm] == s && colunm >= 0; colunm++, horizonal++);
	if (horizonal >= win_size)
	{
		return true;
	}
	for (line = y - 1; table_check[line][x - 1] == s && line <= 5; line--, vertical++);
	for (line = y; table_check[line][x - 1] == s && line >= 0; line++, vertical++);
	if (vertical >= win_size)
	{
		return true;
	}
	for (line = y - 1, colunm = x - 1; table_check[line][colunm] == s && line >= 0 && colunm >= 0; line--, colunm--, diagonalL++);
	for (line = y, colunm = x; table_check[line][colunm] == s && line <= 5 && colunm <= 6; line++, colunm++, diagonalL++);
	if (diagonalL >= win_size)
	{
		return true;
	}
	for (line = y - 1, colunm = x - 1; table_check[line][colunm] == s && line >= 0 && colunm <= 6; line--, colunm++, diagonalR++);
	for (line = y, colunm = x - 2; table_check[line][colunm] == s && line <= 5 && colunm >= 0; line++, colunm--, diagonalR++);
	if (diagonalR >= win_size)
	{
		return true;
	}
	return false;
}