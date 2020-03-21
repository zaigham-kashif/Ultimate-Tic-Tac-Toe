#pragma once
class TicTacToe
{
	private:
		int pr_sizeOfBoard;// for total number of rows and columns
		int** pr_Board;
		int pr_player1_flag;// for player1's turn
		int pr_player2_flag;// for player2's turn
		int pr_moveValidation;
		int pr_saveState;// to determin weather to open file in append mode or not
	public:
		//Constructors

		TicTacToe();   //default constructor
		TicTacToe(int);
		TicTacToe(TicTacToe& copy_obj);//copy constructor

		//Member Functions

		void setSize(int);
		int  getSize();
		void setValue(int , int);
		void printBoard() const;
		void setPlayer1(int);        
		void setPlayer2(int);
		int  getMoveValidation();
		bool check_onPlayer1();// To check if player 1 has won or not
		bool check_onPlayer2();// To check if player 2 has won or not
		bool boardFill();// To cheak if the board is full or not
		int  getPlayer1();
		int  getPlayer2();
		void setMoveValidation(int);
		void boardRead();
		void setSaveState(int);
		int  getSaveState() const ;
		int CheckValue(int, int);
		void setElement(int, int, int);

		//destructors
		~TicTacToe();

};

