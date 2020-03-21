#include "TicTacToe.h"
#include<iostream>
#include<fstream>

using namespace std;

TicTacToe::TicTacToe()
{
	pr_sizeOfBoard = 3;

	//allocating memory
	pr_Board = new int* [pr_sizeOfBoard];
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		pr_Board[i] = new int[pr_sizeOfBoard];
	}

	//intializing every element with zero
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		for (int j = 0; j < pr_sizeOfBoard; j++)
		{
			pr_Board[i][j] = 0;
		}
	}

	pr_moveValidation = 1;
	pr_player1_flag = 1;
	pr_player2_flag = 0;
	pr_saveState = 0;
}

TicTacToe::TicTacToe(int size)
{
	pr_sizeOfBoard = size;

	//allocating memory
	pr_Board = new int* [pr_sizeOfBoard];
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		pr_Board[i] = new int[pr_sizeOfBoard];
	}

	//intializing every element with zero
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		for (int j = 0; j < pr_sizeOfBoard; j++)
		{
			pr_Board[i][j] = 0;
		}
	}

	pr_moveValidation = 1;
	pr_player1_flag = 1;
	pr_player2_flag = 0;
	pr_saveState = 0;
	


}

TicTacToe::TicTacToe(TicTacToe& copy_obj)
{
	pr_moveValidation = copy_obj.pr_moveValidation;
	pr_player1_flag = copy_obj.pr_player1_flag;
	pr_player2_flag = copy_obj.pr_player2_flag;
	pr_sizeOfBoard = copy_obj.pr_sizeOfBoard;
	pr_saveState = copy_obj.pr_saveState;

	pr_Board = new int* [copy_obj.pr_sizeOfBoard];
	for (int i = 0; i < copy_obj.pr_sizeOfBoard; i++)
	{
		pr_Board[i] = new int[copy_obj.pr_sizeOfBoard];
	}

	for (int i = 0; i < copy_obj.pr_sizeOfBoard; i++)
	{
		for (int j = 0; j < copy_obj.pr_sizeOfBoard; j++)
		{
			pr_Board[i][j] = copy_obj.pr_Board[i][j];
		}
	}
	
}

void TicTacToe::setSize(int size)
{
	pr_sizeOfBoard = size;
}

int TicTacToe::getSize() 
{
	return pr_sizeOfBoard;
}

void TicTacToe::setValue(int row, int col)
{
	ofstream fout;
	if (pr_saveState == 1)
	{
		fout.open("board.txt");
		fout << pr_sizeOfBoard;
		fout << endl;
		pr_saveState = 2;
	}
	else if (pr_saveState == 2)
	{
		fout.open("board.txt", ios::app);
	}
	if (pr_player1_flag == 1)
	{
		if (pr_Board[row - 1][col - 1] == 0)
		{
			pr_Board[row - 1][col - 1] = 1;
			pr_moveValidation = 1;
			fout << row ;
			fout << " ";
			fout << col ;
			fout << " ";
			fout << 1;
			fout << endl;
		}
		else
		{
			pr_moveValidation = 0;
		}
	}
	else if (pr_player2_flag == 1)
	{
		if (pr_Board[row - 1][col - 1] == 0)
		{
			pr_Board[row - 1][col - 1] = 2;
			pr_moveValidation = 1;
			fout << row ;
			fout << " ";
			fout << col ;
			fout << " ";
			fout << 2;
			fout << endl;
		}
		else
		{
			pr_moveValidation = 0;
		}
	}
}

void TicTacToe::printBoard() const
{
	int s = pr_sizeOfBoard;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	/*for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		s = pr_sizeOfBoard;
		cout << "					";
		while (s != 0)
		{
			cout << "-----";
			s = s - 1;
		}
		cout << endl;
		s = pr_sizeOfBoard;
		cout << "					";
		while (s != 0)
		{
			cout << "|   |";
			s = s - 1;
		}
		cout << endl;
		s = pr_sizeOfBoard;
		cout << "					";
		while (s != 0)
		{
			for (int j = 0; j < pr_sizeOfBoard; j++)
			{
				if (pr_Board[i][j] == 0)
				{
					cout << "|   |";
				}
				else if (pr_Board[i][j] == 1)
				{
					cout << "| * |";
				}
				else if (pr_Board[i][j] == 2)
				{
					cout << "| o |";
				}
				s = s - 1;
			}
			
		}
		cout << endl;
		s = pr_sizeOfBoard;
		cout << "					";
		while (s != 0)
		{
			cout << "|   |";
			s = s - 1;
		}
		cout << endl;
		s = pr_sizeOfBoard;
		cout << "					";
		while (s != 0)
		{
			cout << "-----";
			s = s - 1;
		}
		cout << endl;
	}*/

	for (int y = 0; y < s; y++)
	{

		cout << "					";
		for (int x = 0; x < s - 1; x++)
		{
			if (x < s - 1)
			{
				cout << "    |";
			}
		}
		cout << endl;
		cout << "					";
		for (int x = 0; x < s; x++)
		{

			if (x < s - 1 && pr_Board[y][x] == 1)
			{
				cout << " *  |";
			}
			else if (x < s - 1 && pr_Board[y][x] == 2)
			{
				cout << " o  |";

			}
			else if (x < s - 1 && pr_Board[y][x] == 0)
			{
				cout << "    |";
			}
			else if(pr_Board[y][x]==1)
			{
				cout << " *  ";
			}
			else if (pr_Board[y][x] == 2)
			{
				cout << " o  ";
			}

		}
		cout << endl;
		cout << "					";
		for (int x = 0; x < s - 1; x++)
		{
			if (x < s - 1)
			{

				cout << "    |";
			}
		}
		cout << endl;
		if (y < s - 1)
		{
			cout << "					";
			for (int x = 0; x < s; x++)
			{
				cout << "____ ";
			}
			cout << endl;
			cout << "					";
			for (int x = 0; x < s; x++)
			{
				cout << "     ";
			}
			cout << endl;
		}
	}
}

void TicTacToe::setPlayer1(int flag)
{
	pr_player1_flag = flag;
}

void TicTacToe::setPlayer2(int flag)
{
	pr_player2_flag = flag;
}

int TicTacToe::getMoveValidation()
{
	return pr_moveValidation;
}

bool TicTacToe::check_onPlayer1()
{

	int size = pr_sizeOfBoard - 1;
	int counter = 0;
	int s = size;

	//check on rows
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		while (size != 0)
		{
			if (pr_Board[i][size] == pr_Board[i][size - 1] && pr_Board[i][size] == 1)
			{
				counter++;
			}
			size = size - 1;
		}
		size = pr_sizeOfBoard - 1;
		if (counter == size)
		{
			return true;
		}
		counter = 0;
	}
	//end

	//check on columns
	counter = 0;
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		while (size != 0)
		{
			if (pr_Board[size][i] == pr_Board[size - 1][i] && pr_Board[size][i] == 1)
			{
				counter++;
			}
			size = size - 1;
		}
		size = pr_sizeOfBoard - 1;
		if (counter == size)
		{
			return true;
		
		}
		counter = 0;
	}
	//end

	//check on right diagonal
	size = pr_sizeOfBoard - 1;
	counter = 0;
	while (size != 0)
	{
		if (pr_Board[size][size] == pr_Board[size - 1][size - 1] && pr_Board[size][size] == 1)
		{
			counter++;
		}
		size = size - 1;
	}
	size = pr_sizeOfBoard - 1;
	if (size == counter)
	{
		return true;
	}
	counter = 0;
	//end


	//check on left diagonal
	while (size != 0)
	{
		if (pr_Board[size][s - size] == pr_Board[size - 1][s - (size - 1)] && pr_Board[size][s - size] == 1)
		{
			counter++;
		}
		size = size - 1;
	}
	size = pr_sizeOfBoard - 1;
	if (size == counter)
	{
		return true;
	}
	counter = 0;
	//end

	return false;
}

bool TicTacToe::check_onPlayer2()
{
	int size = pr_sizeOfBoard - 1;
	int counter = 0;
	int s = size;

	//check on rows
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		while (size != 0)
		{
			if (pr_Board[i][size] == pr_Board[i][size - 1] && pr_Board[i][size] == 2)
			{
				counter++;
			}
			size = size - 1;
		}
		size = pr_sizeOfBoard - 1;
		if (counter == size)
		{
			return true;
		}
		counter = 0;
	}
	//end

	//check on columns
	counter = 0;
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		while (size != 0)
		{
			if (pr_Board[size][i] == pr_Board[size - 1][i] && pr_Board[size][i] == 2)
			{
				counter++;
			}
			size = size - 1;
		}
		size = pr_sizeOfBoard - 1;
		if (counter == size)
		{
			return true;

		}
		counter = 0;
	}
	//end

	//check on right diagonal
	size = pr_sizeOfBoard - 1;
	counter = 0;
	while (size != 0)
	{
		if (pr_Board[size][size] == pr_Board[size - 1][size - 1] && pr_Board[size][size] == 2)
		{
			counter++;
		}
		size = size - 1;
	}
	size = pr_sizeOfBoard - 1;
	if (size == counter)
	{
		return true;
	}
	counter = 0;
	//end


	//check on left diagonal
	while (size != 0)
	{
		if (pr_Board[size][s - size] == pr_Board[size - 1][s - (size - 1)] && pr_Board[size][s - size] == 2)
		{
			counter++;
		}
		size = size - 1;
	}
	size = pr_sizeOfBoard - 1;
	if (size == counter)
	{
		return true;
	}
	counter = 0;
	//end

	return false;
}

bool TicTacToe::boardFill()
{
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		for (int j = 0; j < pr_sizeOfBoard; j++)
		{
			if (pr_Board[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int TicTacToe::getPlayer1()
{
	return pr_player1_flag;
}

int TicTacToe::getPlayer2()
{
	return pr_player2_flag;
}

void TicTacToe::setMoveValidation(int flag)
{
	pr_moveValidation = flag;
}

void TicTacToe::boardRead()
{
	int row, col, turn;
	ifstream fin;
	fin.open("board.txt");
	fin.seekg(2);
	while (!fin.eof())
	{
		fin >> row;
		fin >> col;
		fin >> turn;
		pr_Board[row - 1][col - 1] = turn;
		if (turn == 1)
		{
			pr_player1_flag = 0;
			pr_player2_flag = 1;
		}
		else if (turn == 2)
		{
			pr_player1_flag = 1;
			pr_player2_flag = 0;
		}
		
	}



}

void TicTacToe::setSaveState(int save)
{
	pr_saveState = save;
}

int TicTacToe::getSaveState() const
{
	return pr_saveState;
}


int TicTacToe::CheckValue(int row, int col)
{

	return pr_Board[row][col];
}

void TicTacToe::setElement(int row, int col, int value)
{
	pr_Board[row][col] = value;
}

TicTacToe::~TicTacToe()
{
	for (int i = 0; i < pr_sizeOfBoard; i++)
	{
		delete[]pr_Board[i];
	}
	delete[]pr_Board;
	pr_Board = nullptr;
}

