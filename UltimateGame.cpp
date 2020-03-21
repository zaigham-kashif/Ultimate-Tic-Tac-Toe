#include<iostream>
#include<fstream>
#include"TicTacToe.h"
#include<conio.h>

using namespace std;

void calBoard(int board_no, int& board_row, int& board_col);
int BoardNo(int row, int col);
void PrintExtreamBoard(TicTacToe Board[][3]);
void UltimateBoardRead(TicTacToe Board[][3], int& player1, int& player2, int &r, int &c);


int main()
{
	TicTacToe board[3][3];
	TicTacToe ultimateBoard;

	int board_no = 0, box_no = 0;
	int row = 0, col = 0;
	int row_board = 0, col_board = 0;
	int player1 = 1, player2 = 0;
	int save;

	ofstream fout;

	cout << "				--------------------------------" << endl;
	cout << "				Select an option from menu below" << endl;
	cout << "				1-> New  Game" << endl;
	cout << "				2-> Save Game" << endl;
	cout << "				";
	cin >> save;

	if (save == 1)
	{
		fout.open("UltimateBoard.txt");

		cout << "						--------------" << endl;
		cout << "						Ultimate Board " << endl;
		cout << "						--------------" << endl;
		PrintExtreamBoard(board);

		do
		{
			cout << endl;
			cout << endl;
			cout << "					Enter board number to start with : ";
			cin >> board_no;
			if (board_no <= 9)
			{
				calBoard(board_no, row_board, col_board);
			}
			else
			{
				cout << endl;
				cout << "						******Invalid Board No******" << endl;
			}
		} while (board_no > 9 || board_no <= 0);
	}
	else if (save == 2)
	{
		fout.open("UltimateBoard.txt", ios::app);
		UltimateBoardRead(board, player1, player2, row_board, col_board);
	}


	while (ultimateBoard.check_onPlayer1() != true && ultimateBoard.check_onPlayer2() != true && ultimateBoard.boardFill() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j].check_onPlayer1() == true)
				{
					ultimateBoard.setPlayer2(0);
					ultimateBoard.setPlayer1(1);
					ultimateBoard.setValue(i + 1, j + 1);
				}
				else if (board[i][j].check_onPlayer2() == true)
				{
					ultimateBoard.setPlayer2(1);
					ultimateBoard.setPlayer1(0);
					ultimateBoard.setValue(i + 1, j + 1);
				}
				else if (board[i][j].boardFill() == true)
				{
					ultimateBoard.setElement(i, j, 3);
				}
			}
		}

		if (player1 == 1)
		{
			system("CLS");


			while (player1 == 1 && ultimateBoard.boardFill() == false && ultimateBoard.check_onPlayer1() != true && ultimateBoard.check_onPlayer2() != true)
			{
				if (board[row_board][col_board].check_onPlayer1() != true && board[row_board][col_board].check_onPlayer2() != true && board[row_board][col_board].boardFill() == false)
				{
					board[row_board][col_board].setPlayer1(1);
					board[row_board][col_board].setPlayer2(0);

					do
					{
						if (board[row_board][col_board].getMoveValidation() != 0)
						{
							system("CLS");
							cout << endl;
							cout << "						  -----------" << endl;
							cout << "						  Board No: " << BoardNo(row_board, col_board) << endl;
							cout << "						  -----------" << endl;
							cout << endl;
							PrintExtreamBoard(board);
						}
						cout << endl;
						cout << "						****************" << endl;
						cout << "						*Player1's Turn*" << endl;
						cout << "						****************" << endl;
						

						do
						{
							cout << endl;
							cout << endl;
							cout << "					      Enter Box Number : ";
							cin >> box_no;
							if (box_no <= 9 )
							{
								calBoard(box_no, row, col);
								row = row + 1;
								col = col + 1;
							}
							else
							{
								cout << endl;
								cout << "					 *****Invalid Box Numer*****" << endl;
							}

						} while (box_no > 9 || box_no <= 0);


						board[row_board][col_board].setValue(row, col);
						if (board[row_board][col_board].getMoveValidation() == 0)
						{
							cout << endl;
							cout << "						*****Invalid move***** " << endl;
						}
					} while (board[row_board][col_board].getMoveValidation() == 0);

					fout << row_board;
					fout << " ";
					fout << col_board;
					fout << " ";
					fout << row;
					fout << " ";
					fout << col;
					fout << " ";
					fout << 1;
					fout << endl;

					row_board = row - 1;
					col_board = col - 1;

					system("CLS");
					cout << "						  -----------" << endl;
					cout << "						  Board No: " << BoardNo(row_board, col_board) << endl;
					cout << "						  -----------" << endl;
					cout << endl;
					PrintExtreamBoard(board);

					player1 = 0;
					player2 = 1;
				}
				else if (board[row_board][col_board].check_onPlayer1() == true)
				{
					cout << endl;
					cout << endl;
					cout << "					Player 1 has won board no : " << BoardNo(row_board, col_board) << endl;
										
					cout << "						--------------" << endl;
					cout << "						Ultimate Board " << endl;
					cout << "						--------------" << endl;
					PrintExtreamBoard(board);
					
					cout << endl;
					cout << endl;
					cout << "					Select A Board to Take Next Move : ";
					cin >> board_no;
					calBoard(board_no, row_board, col_board);
				}
				else if (board[row_board][col_board].check_onPlayer2() == true)
				{
					
					cout << endl;
					cout << endl;
					cout << "					Player 2 has won board no : " << BoardNo(row_board, col_board) << endl;
				
					cout << "						--------------" << endl;
					cout << "						Ultimate Board " << endl;
					cout << "						--------------" << endl;
					PrintExtreamBoard(board);
					
					cout << endl;
					cout << endl;
					cout << "					Select A Board to Take Next Move : ";
					cin >> board_no;
					calBoard(board_no, row_board, col_board);
				}
				else if (board[row_board][col_board].boardFill() == true)
				{
					cout << endl;
					cout << endl;
					cout << "					Board No " << BoardNo(row_board, col_board) << "	is tie" << endl;

					cout << "						--------------" << endl;
					cout << "						Ultimate Board " << endl;
					cout << "						--------------" << endl;
					PrintExtreamBoard(board);
				
					cout << endl;
					cout << endl;
					cout << "					Select A Board to Take Next Move : ";
					cin >> board_no;
					calBoard(board_no, row_board, col_board);
				}
			}
		}
		else if (player2 == 1)
		{
			

			system("CLS");

			while (player2 == 1 && ultimateBoard.boardFill() == false && ultimateBoard.check_onPlayer1() != true && ultimateBoard.check_onPlayer2() != true)
			{
				if (board[row_board][col_board].check_onPlayer1() != true && board[row_board][col_board].check_onPlayer2() != true && board[row_board][col_board].boardFill() == false)
				{
					board[row_board][col_board].setPlayer2(1);
					board[row_board][col_board].setPlayer1(0);

					do
					{

						if (board[row_board][col_board].getMoveValidation() != 0)
						{
							system("CLS");
							cout << "						  -----------" << endl;
							cout << "						  Board No: " << BoardNo(row_board, col_board) << endl;
							cout << "						  -----------" << endl;
							cout << endl;
							PrintExtreamBoard(board);
						}
						cout << endl;
						cout << "						****************" << endl;
						cout << "						*Player2's Turn*" << endl;
						cout << "						****************" << endl;

						

						do
						{
							cout << endl;
							cout << endl;
							cout << "					      Enter Box Number : ";
							cin >> box_no;
							if (box_no <= 9)
							{
								calBoard(box_no, row, col);
								row = row + 1;
								col = col + 1;
							}
							else
							{
								cout << endl;
								cout << "				*****Invalid Box Number*****" << endl;
							}

						} while (box_no > 9 || box_no <= 0);


						board[row_board][col_board].setValue(row, col);
						if (board[row_board][col_board].getMoveValidation() == 0)
						{
							cout << endl;
							cout << "					*****Invalid move***** " << endl;
						}
					} while (board[row_board][col_board].getMoveValidation() == 0);

					fout << row_board;
					fout << " ";
					fout << col_board;
					fout << " ";
					fout << row;
					fout << " ";
					fout << col;
					fout << " ";
					fout << 2;
					fout << endl;

					row_board = row - 1;
					col_board = col - 1;

					system("CLS");

					cout << "						  -----------" << endl;
					cout << "						  Board No: " << BoardNo(row_board, col_board) << endl;
					cout << "						  -----------" << endl;
					cout << endl;
					PrintExtreamBoard(board);
					
					player1 = 1;
					player2 = 0;

				}
				else if (board[row_board][col_board].check_onPlayer1() == true)
				{
					cout << endl;
					cout << endl;
					cout << "					Player 1 has won board no : " << BoardNo(row_board, col_board) << endl;

					cout << endl;
					cout << "						--------------" << endl;
					cout << "						Ultimate Board " << endl;
					cout << "						--------------" << endl;
					PrintExtreamBoard(board);					

					cout << endl;
					cout << endl;
					cout << "					Select A Board to Take Next Move : ";
					cin >> board_no;
					calBoard(board_no, row_board, col_board);

				}
				else if (board[row_board][col_board].check_onPlayer2() == true)
				{
					cout << endl;
					cout << endl;
					cout << "					Player 2 has won board no : " << BoardNo(row_board, col_board) << endl;

					cout << "						--------------" << endl;
					cout << "						Ultimate Board " << endl;
					cout << "						--------------" << endl;
					PrintExtreamBoard(board);
					
					cout << endl;
					cout << endl;
					cout << "					Select A Board to Take Next Move : ";
					cin >> board_no;
					calBoard(board_no, row_board, col_board);
				}
				else if (board[row_board][col_board].boardFill() == true)
				{
					cout << endl;
					cout << endl;
					cout << "					Board No " << BoardNo(row_board, col_board) << "	is tie" << endl;

					cout << "						--------------" << endl;
					cout << "						Ultimate Board " << endl;
					cout << "						--------------" << endl;
					PrintExtreamBoard(board);

					cout << endl;
					cout << endl;
					cout << "					Select A Board to Take Next Move : ";
					cin >> board_no;
					calBoard(board_no, row_board, col_board);
				}
			}
		}
	}
	if (ultimateBoard.check_onPlayer1() == true)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		PrintExtreamBoard(board);
		cout << endl;
		cout << "						-------------------------" << endl;
		cout << "						Player 1 has won the game" << endl;
		cout << "						-------------------------" << endl;
	}
	else if (ultimateBoard.check_onPlayer2() == true)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		PrintExtreamBoard(board);
		cout << endl;
		cout << "					-------------------------" << endl;
		cout << "					Player 2 has won the game" << endl;
		cout << "					-------------------------" << endl;
	}
	else if (ultimateBoard.boardFill()==true)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		PrintExtreamBoard(board);
		cout << endl;
		cout << "							-----------" << endl;
		cout << "							Game is Tie" << endl;
		cout << "							-----------" << endl;
	}
}

void calBoard(int board_no, int& board_row, int& board_col)
{
	if (board_no % 3 == 0)
	{
		board_row = (board_no / 3) - 1;
	}
	else
	{
		board_row = (board_no / 3);
	}

	if (board_no == 1 || board_no == 4 || board_no == 7)
	{
		board_col = 0;
	}
	else if (board_no == 2 || board_no == 5 || board_no == 8)
	{
		board_col = 1;
	}
	else if (board_no == 3 || board_no == 6 || board_no == 9)
	{
		board_col = 2;
	}
}

int BoardNo(int row, int col)
{
	int board_no = 0;
	if (row == 0 && col == 0)
	{
		board_no = 1;
	}
	else if (row == 0 && col == 1)
	{
		board_no = 2;

	}
	else if (row == 0 && col == 2)
	{
		board_no = 3;

	}
	else if (row == 1 && col == 0)
	{
		board_no = 4;

	}
	else if (row == 1 && col == 1)
	{
		board_no = 5;

	}
	else if (row == 1 && col == 2)
	{
		board_no = 6;

	}
	else if (row == 2 && col == 0)
	{
		board_no = 7;

	}
	else if (row == 2 && col == 1)
	{
		board_no = 8;

	}
	else if (row == 2 && col == 2)
	{
		board_no = 9;
	}

	return board_no;

}

void PrintExtreamBoard(TicTacToe Board[][3])
{
	int a = 0;
	int b = 0;
	
	cout << endl;
	cout << endl;

	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			b = 0;

			cout << "				#|";
			for (int x = 0; x < 9;x++)
			{
				if ((x + 1) % 3 == 0)
				{
					cout << "   |#";
				}
				else
				{
					cout << "   | ";

				}
			}
			cout << endl;

			cout << "				#|";
			for (int x = 0; x < 9; x++)
			{
				if ((x + 1) % 3 == 0 && Board[j][b].CheckValue(k, a) == 0)
				{
					cout << "   |#";
				}
				else if ((x + 1) % 3 == 0 && Board[j][b].CheckValue(k, a) == 1)
				{
					cout << " * |#";
				}
				else if ((x + 1) % 3 == 0 && Board[j][b].CheckValue(k, a) == 2)
				{
					cout << " o |#";
				}
				else if (Board[j][b].CheckValue(k, a) == 0)
				{
					cout << "   | ";
				}
				else if (Board[j][b].CheckValue(k, a) == 1)
				{
					cout << " * | ";
				}
				else if (Board[j][b].CheckValue(k, a) == 2)
				{
					cout << " o | ";
				}
				a++;

				if ((x + 1) % 3 == 0)
				{
					b++;
					a = 0;
				}
			}
			cout << endl;

			cout << "				#|";
			for (int x = 0; x < 9; x++)
			{
				if ((x + 1) % 3 == 0)
				{
					cout << "   |#";
				}
				else
				{
					cout << "   | ";

				}
			}
			cout << endl;

			cout << "				  ";
			for (int x = 0; x < 9; x++)
			{
				cout << "___  ";		
			}
			cout << endl;
			
		}

		cout << "				  ";
		for (int k = 0; k < 9; k++)
		{
			cout << "#### " ;
		}
		cout << endl;
	}
	
}

void UltimateBoardRead(TicTacToe Board[][3], int& player1, int& player2,int &r,int &c)
{

	int row_board = 0, col_board = 0, row = 0, col = 0, value = 0;
	ifstream fin;
	fin.open("UltimateBoard.txt");
	while (!fin.eof())
	{
		fin >> row_board;
		fin >> col_board;
		fin >> row;
		row = row - 1;
		fin >> col;
		col = col - 1;
		fin >> value;
		if (row >= 0 && col >= 0)
		{
			Board[row_board][col_board].setElement(row, col, value);
			r = row;
			c = col;
		}
	}
	

	if (value == 1)
	{
		player2 = 1;
		player1 = 0;
	}
	else if (value == 2)
	{
		player1 = 1;
		player2 = 0;
	}
}