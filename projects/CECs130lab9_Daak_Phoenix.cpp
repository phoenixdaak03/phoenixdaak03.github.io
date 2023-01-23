//Phoenix Daak
//CSE 130-01
//04-01-2022
//Lab #9

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

class tiktak
{
	public:
		void outline_of_board();
		void computerchoice();
		void humanchoice();
		void gameboard();
		void checkifwin();
		void winner();
		int turn;
	private:
		char game_board[9];
};

void tiktak::checkifwin()
{
	if (game_board[0] == game_board[1] && game_board[1] == game_board[2])
	{
		winner();
	}
	
	if (game_board[3] == game_board[4] && game_board[4] == game_board[5])
	{
		winner();
	}
	if (game_board[6] == game_board[7] && game_board[7] == game_board [8])
	{
		winner();
	}
	if (game_board[0] == game_board[3] && game_board[3] == game_board[6])
	{
		winner();
	}
	if (game_board[1] == game_board[4] && game_board[4] == game_board[7])
	{
		winner();
	}
	if (game_board[2] == game_board[5] && game_board[5] == game_board[8])
	{
		winner();
	}
	if (game_board[0] == game_board[4] && game_board[4] == game_board [8])
	{
		winner();
	}
	if (game_board[2] == game_board[4] && game_board[4] == game_board[6])
	{
		winner();
	}
	
}

	
void tiktak::winner()
{
	if(turn == 0)
	{
		cout << "\n\nYou won!!\n\n";
		std::terminate();
	}
	else if (turn == 1)
	{
		cout <<"\n\nYou lost!!\n\n";
		std::terminate();
	}
}

void tiktak::gameboard()
{
	game_board[0] = {'0'};
	game_board[1] = {'1'};
	game_board[2] = {'2'};
	game_board[3] = {'3'};
	game_board[4] = {'4'};
	game_board[5] = {'5'};
	game_board[6] = {'6'};
	game_board[7] = {'7'};
	game_board[8] = {'8'};
}
void tiktak::outline_of_board()
{
			cout << "\n\n\t" << game_board[0] << " | " << game_board[1] << " | " << game_board[2]
			 	 << "\n\t---------"
		  	 	 << "\n\t" << game_board[3] << " | " << game_board[4] << " | " << game_board[5]
		  		 << "\n\t---------"
		   		 << "\n\t" << game_board[6] << " | " << game_board[7] << " | " << game_board[8];
}

//computers move
void tiktak::computerchoice()
{
	int computer_choice;
	
	do 
	{
		computer_choice = rand()%(0, 9);
	}
	while (game_board[computer_choice] == 'x' || game_board[computer_choice] == 'o');
			
	game_board[computer_choice] = {'o'};
}

//human's move
void tiktak::humanchoice()
{
	int human_choice;
	
	do 
	{
		cout << "\n\nPick a space you would like to make a move on:";	 
		cin  >> human_choice;
	}
	while (game_board[human_choice] == 'x' || game_board[human_choice] == 'o');
			
	game_board[human_choice] = {'x'};
	
}

//main function
int main()
{
	cout << "*****WELCOME TO TIK TAK TOE*****"
		 << "\n\nStrategy: Try to win against the computer by getting three in a row";
		 
	tiktak game;
	
	game.gameboard();
	
	game.outline_of_board();
	
	srand(time(0));
	
	int first_move;
	first_move = rand()%2;
	
	if (first_move == 0)
	{
		cout << "\n\nYou have the first move"
			 << "\n\nYou are x's";
		int i;
		for (i = 0; i < 10; i++)
		{
			game.turn = 0;
			
			game.humanchoice();
			
			game.outline_of_board();
		
			game.checkifwin();
			
			game.turn = 1;
			
			game.computerchoice();
		
			game.outline_of_board();
			
			game.checkifwin();
		}
	}
	else
	{
		cout << "\n\nThe Computer has the first move";
		
		int human_choice = 0;
		
		int i;
		for (i = 0; i < 10; i++)
		{
			game.turn = 1;
			
			game.computerchoice();
		
			game.outline_of_board();
			
			game.checkifwin();
			
			game.turn = 0;
			
			game.humanchoice();
			
			game.outline_of_board();
			
			game.checkifwin();
			
			cout <<"\n\nComputer's Turn...";
		   	
		}
	}
	
	return 0;
}
	


