//connect4.swag
#include <iostream>
#include <fstream>
using namespace std;

void drawboard(ostream &, char [][7], int, int);
void drawcolorboard(ostream &, char [][7], int, int);

int main () {

	ofstream outfile;
	outfile.open("gamelog01.txt");
	
	char board [6][7] = {0};
	
	int people;
	int game;
	int pMove=0;
	
	int column;
	int row=0;
	
	int hcCheck;
	int hrCheck;
	int vcCheck;
	int vrCheck;
	int dcCheck;
	int drCheck;
	
	cout << "how many players?" << endl;
	cin >> people;
	//board[row y][column x]
	
	if (people==2) //human game
	{
		for(game=0;game<42;game++)
		{
			drawcolorboard(cout, board, 6, 7);
			drawboard(outfile, board, 6, 7);
				
			if (pMove==0) //player1
			{
				cout << "which column would you like to play Player 1?" << endl;
				cin >> column;
				
				if (column<0 || column>6)
				{
					cout << "Column does not exist try again" << endl;
				}
				else 
				{
					row=0;
					while ((board[row][column]=='X' || board[row][column]=='O') && row<6 )
					{
						row++;
					}
						if (row==6)
						{
							cout << "That column is full pick another" <<endl;
						}
						else 
						{
							board[row][column] = 'X';
							pMove++;
						}
						
				// check for win
					for (hrCheck=0;hrCheck<6;hrCheck++) //horizontal win check
					{
						for (hcCheck=0;hcCheck<4;hcCheck++)
						{
							if (board[hrCheck][hcCheck]=='X' && 
								board[hrCheck][hcCheck+1]=='X' && 
								board[hrCheck][hcCheck+2]=='X' && 
								board[hrCheck][hcCheck+3]=='X')
							{
								cout << "Good Job Player 1 you're the winner!!1!" << endl;
								game=game+43;
							}
							else
							{
								cout;
							}
						}
					}
					for (vcCheck=0;vcCheck<7;vcCheck++) //verticle win check
					{
						for(vrCheck=0;vrCheck<3;vrCheck++)
						{
							if(board[vrCheck][vcCheck]=='X' && 
								board[vrCheck+1][vcCheck]=='X' && 
								board[vrCheck+2][vcCheck]=='X' && 
								board[vrCheck+3][vcCheck]=='X')
								{
									cout << "Good Job Player 1 you're the winner!!1!" << endl;
									game=game+43;
								}
							else
							{
								cout;
							}
						}
					}
					for (drCheck=0;drCheck<3;drCheck++)//diagonal win
					{
						for (dcCheck=0;dcCheck<7;dcCheck++)
						{
							if (dcCheck<3)//0-2
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck+1]=='X' && 
									board[drCheck+2][dcCheck+2]=='X' && 
									board[drCheck+3][dcCheck+3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else if (dcCheck>3)//4-6
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck-1]=='X' && 
									board[drCheck+2][dcCheck-2]=='X' && 
									board[drCheck+3][dcCheck-3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else //for 3
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck+1]=='X' && 
									board[drCheck+2][dcCheck+2]=='X' && 
									board[drCheck+3][dcCheck+3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else if(board[drCheck][dcCheck]=='X' && 
										board[drCheck+1][dcCheck-1]=='X' && 
										board[drCheck+2][dcCheck-2]=='X' && 
										board[drCheck+3][dcCheck-3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else 
								{
									cout;
								}
							}
						}
					}
				}
			}
			else //player2
			{
				cout << "which column would you like to play Player 2?" << endl;
				cin >> column;
				
				if (column<0 && column>6)
				{
					cout << "Column does not exist try again" << endl;
				}
				else 
				{
					row=0;
					while ((board[row][column]=='X' || board[row][column]=='O') && row<6 )
					{
						row++;
					}
						if (row==6)
						{
							cout << "That column is full pick another" <<endl;
						}
						else 
						{
							board[row][column]='O';
							pMove--;
						}
						
				// check for win
					for (hrCheck=0;hrCheck<6;hrCheck++) //horizontal win check
					{
						for (hcCheck=0;hcCheck<4;hcCheck++)
						{
							if (board[hrCheck][hcCheck]=='O' && 
								board[hrCheck][hcCheck+1]=='O' && 
								board[hrCheck][hcCheck+2]=='O' && 
								board[hrCheck][hcCheck+3]=='O')
							{
								cout << "Good Job Player 2 you're the winner!!1!" << endl;
								game=game+43;
							}
							else
							{
								cout;
							}
						}
					}
					for (vcCheck=0;vcCheck<7;vcCheck++) //verticle win check
					{
						for(vrCheck=0;vrCheck<3;vrCheck++)
						{
							if(board[vrCheck][vcCheck]=='O' && 
								board[vrCheck+1][vcCheck]=='O' && 
								board[vrCheck+2][vcCheck]=='O' && 
								board[vrCheck+3][vcCheck]=='O')
								{
									cout << "Good Job Player 2 you're the winner!!1!" << endl;
									game=game+43;
								}
							else 
							{
								cout;
							}
						}
					}
					for (drCheck=0;drCheck<3;drCheck++)//diagonal win
					{
						for (dcCheck=0;dcCheck<7;dcCheck++)
						{
							if (dcCheck<3)//0-2
							{
								if(board[drCheck][dcCheck]=='O' && 
									board[drCheck+1][dcCheck+1]=='O' && 
									board[drCheck+2][dcCheck+2]=='O' && 
									board[drCheck+3][dcCheck+3]=='O')
									{
										cout << "Good Job Player 2 you're the winner!!1!" << endl;
										game=game+43;
									}
								else 
								{
									cout;
								}
							}
							else if (dcCheck>3)//4-6
							{
								if(board[drCheck][dcCheck]=='O' && 
									board[drCheck+1][dcCheck-1]=='O' && 
									board[drCheck+2][dcCheck-2]=='O' && 
									board[drCheck+3][dcCheck-3]=='O')
									{
										cout << "Good Job Player 2 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else //for 3
							{
								if(board[drCheck][dcCheck]=='O' && 
									board[drCheck+1][dcCheck+1]=='O' && 
									board[drCheck+2][dcCheck+2]=='O' && 
									board[drCheck+3][dcCheck+3]=='O')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else if(board[drCheck][dcCheck]=='O' && 
										board[drCheck+1][dcCheck-1]=='O' && 
										board[drCheck+2][dcCheck-2]=='O' && 
										board[drCheck+3][dcCheck-3]=='O')
									{
										cout << "Good Job Player 2 you're the winner!!1!" << endl;
										game=game+43;
									}
								else 
								{
									cout;
								}
							}
						}
					}
				}
			}
			
		}
		cout << "Game Over!" << endl;
	}
	else if (people==1) //AI game
	{
		int aiMove;
		int airTh;
		int aicTh;
		int airT;
		int aicT;
		int airOW;
		int aicOW;
		
		for(game=0;game<42;game++)
		{
			drawcolorboard(cout, board, 6, 7);
			drawboard(outfile, board, 6, 7);
				
			if (pMove==0) //person
			{
				cout << "which column would you like to play?" << endl;
				cin >> column;
				
				if (column<0 || column>6)
				{
					cout << "Column does not exist try again" << endl;
				}
				else 
				{
					row=0;
					while ((board[row][column]=='X' || board[row][column]=='O') && row<6 )
					{
						row++;
					}
						if (row==6)
						{
							cout << "That column is full pick another" <<endl;
						}
						else 
						{
							board[row][column] = 'X';
							pMove++;
						}
						
				// check for win
					for (hrCheck=0;hrCheck<6;hrCheck++) //horizontal win check
					{
						for (hcCheck=0;hcCheck<4;hcCheck++)
						{
							if (board[hrCheck][hcCheck]=='X' && 
								board[hrCheck][hcCheck+1]=='X' && 
								board[hrCheck][hcCheck+2]=='X' && 
								board[hrCheck][hcCheck+3]=='X')
							{
								cout << "Good Job Player 1 you're the winner!!1!" << endl;
								game=game+43;
							}
							else
							{
								cout;
							}
						}
					}
					for (vcCheck=0;vcCheck<7;vcCheck++) //verticle win check
					{
						for(vrCheck=0;vrCheck<3;vrCheck++)
						{
							if(board[vrCheck][vcCheck]=='X' && 
								board[vrCheck+1][vcCheck]=='X' && 
								board[vrCheck+2][vcCheck]=='X' && 
								board[vrCheck+3][vcCheck]=='X')
								{
									cout << "Good Job Player 1 you're the winner!!1!" << endl;
									game=game+43;
								}
							else
							{
								cout;
							}
						}
					}
					for (drCheck=0;drCheck<3;drCheck++)//diagonal win
					{
						for (dcCheck=0;dcCheck<7;dcCheck++)
						{
							if (dcCheck<3)//0-2
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck+1]=='X' && 
									board[drCheck+2][dcCheck+2]=='X' && 
									board[drCheck+3][dcCheck+3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else if (dcCheck>3)//4-6
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck-1]=='X' && 
									board[drCheck+2][dcCheck-2]=='X' && 
									board[drCheck+3][dcCheck-3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else //for 3
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck+1]=='X' && 
									board[drCheck+2][dcCheck+2]=='X' && 
									board[drCheck+3][dcCheck+3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else if(board[drCheck][dcCheck]=='X' && 
										board[drCheck+1][dcCheck-1]=='X' && 
										board[drCheck+2][dcCheck-2]=='X' && 
										board[drCheck+3][dcCheck-3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else 
								{
									cout;
								}
							}
						}
					}
				}
			}
			else //AI
			{
				aiMove=6;
				while(aiMove>0)
				{
					if(aiMove==6) //3 win
					{
						for(airTh=0;airTh<3;airTh++) //3 win diagonal
						{
							for(aicTh=0;aicTh<7;aicTh++)
							{
								if(aicTh<3) //column 0-2
								{
									if(airTh==0) //row 0
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else if(airTh==1) //row 1
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //row 2
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh-2][aicTh-1]=='O' || board[airTh-2][aicTh-1]=='X') &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
								else if(aicTh>3) //column 4-6
								{
									if(airTh==0) //row 0
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh-3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else if(airTh==1) //row 1
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //row 2
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh-2][aicTh+1]=='O' || board[airTh-2][aicTh+1]=='X') &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
								else //columns 3
								{
									if(airTh==0) //row 0
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh-3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else if(airTh==1) //row 1
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //row 2
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+3][aicTh+3]=='O' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh+1]=='O' &&
											board[airTh+2][aicTh+2]=='O' &&
											(board[airTh-2][aicTh-1]=='O' || board[airTh-2][aicTh-1]=='X') &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+3][aicTh-3]=='O' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh+1][aicTh-1]=='O' &&
											board[airTh+2][aicTh-2]=='O' &&
											(board[airTh-2][aicTh+1]=='O' || board[airTh-2][aicTh+1]=='X') &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								
								}
							}
						}
						for(airTh=0;airTh<6;airTh++) //3 win horizontal
						{
							for(aicTh=0;airTh<4;airTh++)
							{
								if(airTh==0)
								{
									if(aicTh==0) //column 0
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //columns 1-3
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											(board[airTh][aicTh-1]!='O' || board[airTh][aicTh-1]!='X'))
										{
											board[airTh][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
								else 
								{
									if(aicTh==0) //column 0
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											(board[airTh-1][aicTh+3]=='O' || board[airTh-1][aicTh+3]=='X') &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh-1][aicTh+1]=='O' || board[airTh-1][aicTh+1]=='X') &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh-1][aicTh+2]=='O' || board[airTh-1][aicTh+2]=='X') &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //columns 1-3
									{
										if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											(board[airTh-1][aicTh+3]=='O' || board[airTh-1][aicTh+3]=='X') &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh-1][aicTh+1]=='O' || board[airTh-1][aicTh+1]=='X') &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+3]=='O' &&
											(board[airTh-1][aicTh+2]=='O' || board[airTh-1][aicTh+2]=='X') &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='O' &&
											board[airTh][aicTh+1]=='O' &&
											board[airTh][aicTh+2]=='O' &&
											(board[airTh-1][aicTh-1]=='O' || board[airTh-1][aicTh-1]=='X') &&
											(board[airTh][aicTh-1]!='O' || board[airTh][aicTh-1]!='X'))
										{
											board[airTh][aicTh-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
							}
						}
						for(airTh=0;airTh<3;airTh++) //3 win verticle
						{
							for(aicTh=0;aicTh<7;airTh++)
							{
								if(board[airTh][aicTh]=='O' &&
									board[airTh+1][aicTh]=='O' &&
									board[airTh+2][aicTh]=='O' &&
									(board[airTh+3][aicTh]!='O' || board[airTh+3][aicTh]!='X'))
								{
									board[airTh+3][aicTh]='O';
									pMove--;
									aiMove=aiMove-7;
								}
								else
								{
									cout;
								}
							}
						}
						aiMove=aiMove-1;
					}
					else if (aiMove==5) //3 block
					{
						for(airTh=0;airTh<3;airTh++) //3 block diagonal
						{
							for(aicTh=0;aicTh<7;aicTh++)
							{
								if(aicTh<3) //column 0-2
								{
									if(airTh==0) //row 0
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else if(airTh==1) //row 1
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //row 2
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh-2][aicTh-1]=='O' || board[airTh-2][aicTh-1]=='X') &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
								else if(aicTh>3) //column 4-6
								{
									if(airTh==0) //row 0
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh-3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else if(airTh==1) //row 1
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //row 2
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh-2][aicTh+1]=='O' || board[airTh-2][aicTh+1]=='X') &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
								else //columns 3
								{
									if(airTh==0) //row 0
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh-3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else if(airTh==1) //row 1
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //row 2
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh+2][aicTh+3]=='O' || board[airTh+2][aicTh+3]=='X') &&
											(board[airTh+3][aicTh+3]!='O' || board[airTh+3][aicTh+3]!='X'))
										{
											board[airTh+3][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]=='O' || board[airTh][aicTh+1]=='X') &&
											(board[airTh+1][aicTh+1]!='O' || board[airTh+1][aicTh+1]!='X'))
										{
											board[airTh+1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+3][aicTh+3]=='X' &&
											(board[airTh+1][aicTh+2]=='O' || board[airTh+1][aicTh+2]=='X') &&
											(board[airTh+2][aicTh+2]!='O' || board[airTh+2][aicTh+2]!='X'))
										{
											board[airTh+2][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh+1]=='X' &&
											board[airTh+2][aicTh+2]=='X' &&
											(board[airTh-2][aicTh-1]=='O' || board[airTh-2][aicTh-1]=='X') &&
											(board[airTh-1][aicTh-1]!='O' || board[airTh-1][aicTh-1]!='X'))
										{
											board[airTh-1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh+2][aicTh-3]=='O' || board[airTh+2][aicTh-3]=='X') &&
											(board[airTh+3][aicTh-3]!='O' || board[airTh+3][aicTh-3]!='X'))
										{
											board[airTh+3][aicTh-3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh][aicTh-1]=='O' || board[airTh][aicTh-1]=='X') &&
											(board[airTh+1][aicTh-1]!='O' || board[airTh+1][aicTh-1]!='X'))
										{
											board[airTh+1][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+3][aicTh-3]=='X' &&
											(board[airTh+1][aicTh-2]=='O' || board[airTh+1][aicTh-2]=='X') &&
											(board[airTh+2][aicTh-2]!='O' || board[airTh+2][aicTh-2]!='X'))
										{
											board[airTh+2][aicTh-2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh+1][aicTh-1]=='X' &&
											board[airTh+2][aicTh-2]=='X' &&
											(board[airTh-2][aicTh+1]=='O' || board[airTh-2][aicTh+1]=='X') &&
											(board[airTh-1][aicTh+1]!='O' || board[airTh-1][aicTh+1]!='X'))
										{
											board[airTh-1][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								
								}
							}
						}
						for(airTh=0;airTh<6;airTh++) //3 block horizontal
						{
							for(aicTh=0;airTh<4;airTh++)
							{
								if(airTh==0)
								{
									if(aicTh==0) //column 0
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //columns 1-3
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											(board[airTh][aicTh-1]!='O' || board[airTh][aicTh-1]!='X'))
										{
											board[airTh][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
								else 
								{
									if(aicTh==0) //column 0
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											(board[airTh-1][aicTh+3]=='O' || board[airTh-1][aicTh+3]=='X') &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh-1][aicTh+1]=='O' || board[airTh-1][aicTh+1]=='X') &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh-1][aicTh+2]=='O' || board[airTh-1][aicTh+2]=='X') &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else //columns 1-3
									{
										if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											(board[airTh-1][aicTh+3]=='O' || board[airTh-1][aicTh+3]=='X') &&
											(board[airTh][aicTh+3]!='O' || board[airTh][aicTh+3]!='X'))
										{
											board[airTh][aicTh+3]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh-1][aicTh+1]=='O' || board[airTh-1][aicTh+1]=='X') &&
											(board[airTh][aicTh+1]!='O' || board[airTh][aicTh+1]!='X'))
										{
											board[airTh][aicTh+1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+3]=='X' &&
											(board[airTh-1][aicTh+2]=='O' || board[airTh-1][aicTh+2]=='X') &&
											(board[airTh][aicTh+2]!='O' || board[airTh][aicTh+2]!='X'))
										{
											board[airTh][aicTh+2]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airTh][aicTh]=='X' &&
											board[airTh][aicTh+1]=='X' &&
											board[airTh][aicTh+2]=='X' &&
											(board[airTh-1][aicTh-1]=='O' || board[airTh-1][aicTh-1]=='X') &&
											(board[airTh][aicTh-1]!='O' || board[airTh][aicTh-1]!='X'))
										{
											board[airTh][aicTh-1]='X';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
								}
							}
						}
						for(airTh=0;airTh<3;airTh++) //3 block verticle
						{
							for(aicTh=0;aicTh<7;airTh++)
							{
								if(board[airTh][aicTh]=='X' &&
									board[airTh+1][aicTh]=='X' &&
									board[airTh+2][aicTh]=='X' &&
									(board[airTh+3][aicTh]!='O' || board[airTh+3][aicTh]!='X'))
								{
									board[airTh+3][aicTh]='X';
									pMove--;
									aiMove=aiMove-7;
								}
								else
								{
									cout;
								}
							}
						}
						
						aiMove=aiMove-1;
					}
					else if (aiMove==4) //2 block
					{
						
						for(airT=0;airT<4;airT++) //2 block diagonal
						{
							for(aicT=0;aicT<7;aicT++)
							{
								if(aicT==0) //column 0
								{
									if(board[airT][aicT]=='X' &&
										board[airT+1][aicT+1]=='X' &&
										(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
										(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
									{
										board[airT+2][aicT+2]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else if(board[airT][aicT]=='X' &&
										board[airT+2][aicT+2]=='X' &&
										(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
										(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
									{
										board[airT+1][aicT+1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
								else if(aicT==6) //column 6
								{
									if(board[airT][aicT]=='X' &&
										board[airT+1][aicT-1]=='X' &&
										(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
										(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
									{
										board[airT+2][aicT-2]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else if(board[airT][aicT]=='X' &&
										board[airT+2][aicT-2]=='X' &&
										(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
										(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
									{
										board[airT][aicT]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if(airT==0) //at row 0
									{
										if(aicT==1)
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT+2]=='X' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else if (aicT>1 && aicT<5)
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+1][aicT-1]=='X' &&
													(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
													(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT-1]=='X' &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
										}
									}
									else if(airT==1) //at row 1
									{
										if(aicT==1)
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT+2]=='X' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else if (aicT>1 && aicT<5)
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT+2]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+1][aicT-1]=='X' &&
													(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
													(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+1][aicT-1]=='X' &&
													(board[airT-1][aicT+1]!='O' || board[airT-1][aicT+1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT-2]=='X' &&
												(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
												(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
											{
												board[airT+1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT-1]=='X' &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT-2]=='X' &&
												(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
												(board[airT-1][aicT+1]!='O' || board[airT-1][aicT+1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
									}
									else //row 2or3
									{
										if(aicT==1)
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT-2][aicT-1]=='O' || board[airT-2][aicT-1]=='X') &&
												(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT+2]=='X' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else if (aicT>1 && aicT<5)
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT+1]=='X' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+1][aicT+1]=='X' &&
													(board[airT-2][aicT-1]=='O' || board[airT-2][aicT-1]=='X') &&
													(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+2][aicT+2]=='X' &&
													(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
													(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+1][aicT-1]=='X' &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+1][aicT-1]=='X' &&
													(board[airT-2][aicT+1]=='O' || board[airT-2][aicT+1]=='X') &&
													(board[airT-1][aicT+1]!='O' || board[airT-1][aicT+1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
													board[airT+2][aicT-2]=='X' &&
													(board[airT][aicT-1]=='O' || board[airT][aicT-+1]=='X') &&
													(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
											{
												board[airT+1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else
										{
											if(board[airT][aicT]=='X' &&
												board[airT+1][aicT-1]=='X' &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='X' &&
												board[airT+2][aicT-2]=='X' &&
												(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
												(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
											{
												board[airT+1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
									}
								}
							}
						}
						for(airT=0;airT<6;airT++) //2 win horizontal
						{
							for(aicT=0;aicT<7;aicT++)
							{
								if(aicT==0) //column 0
								{
									if(airT==0)
									{
										if(board[airT][aicT]=='X' &&
											board[airT][aicT+1]=='X' &&
											(board[airT][aicT+2]!='O' || board[airT][aicT+2]!='X'))
										{
											board[airT][aicT]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if (board[airT][aicT]=='X' &&
												board[airT][aicT+2]=='X' &&
												(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airT>0)
									{
										if(board[airT][aicT]=='X' &&
											board[airT][aicT+2]=='X' &&
											(board[airT-1][aicT+1]=='O' || board[airT-1][aicT+1]=='X') &&
											(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='X' &&
												board[airT][aicT+2]=='O' &&
												(board[airT-1][aicT+1]=='O' || board[airT-1][aicT+1]=='X') &&
												(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}	
									else
									{
										cout;
									}
								}	
								else if(aicT==6) //column 6
								{
									if(airT==0)
									{
										if(board[airT][aicT]=='X' &&
											board[airT][aicT-1]=='X' &&
											(board[airT][aicT-2]!='O' || board[airT][aicT-2]!='X'))
										{
											board[airT][aicT-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='X' &&
												board[airT][aicT-2]=='X' &&
												(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airT>0)
									{
										if(board[airT][aicT]=='X' &&
											board[airT][aicT-1]=='X' &&
											(board[airT-1][aicT-2]=='O' || board[airT-1][aicT-2]=='X') &&
											(board[airT][aicT-2]!='O' || board[airT][aicT-2]!='X'))
										{
											board[airT][aicT-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='X' &&
												board[airT][aicT-2]=='X' &&
												(board[airT-1][aicT-1]=='O' || board[airT-1][aicT-1]=='X') &&
												(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if (airT==0)
									{
										if (board[airT][aicT]=='X' &&
											board[airT][aicT+1]=='X' &&
											(board[airT][aicT+2]!='O' || board[airT][aicT+2]!='X'))
										{
											board[airT][aicT+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if (board[airT][aicT]=='X' &&
											board[airT][aicT+1]=='X' &&
											(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='X' &&
											board[airT][aicT+2]=='X' &&
											(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										if (board[airT][aicT]=='X' &&
											board[airT][aicT+1]=='X' &&
											(board[airT-1][aicT+2]=='O' || board[airT-1][aicT+2]=='X') &&
											(board[airT][aicT+2]!='O' || board[airT][aicT+2]!='X'))
										{
											board[airT][aicT+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if (board[airT][aicT]=='X' &&
											board[airT][aicT+1]=='X' &&
											(board[airT-1][aicT-1]=='O' || board[airT-1][aicT-1]=='X') &&
											(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='X' &&
											board[airT][aicT+2]=='X' &&
											(board[airT-1][aicT+1]=='O' || board[airT-1][aicT+1]=='X') &&
											(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
								}
							}
						}
						for (airT=0;airT<4;airT++) //2 block verticle 
						{
							for(aicT=0;aicT<7;aicT++)
							{
								if(board[aicT][airT]=='X' &&
									board[aicT][airT+1]=='X' &&
									(board[aicT][airT+2]!='X' || board[aicT][airT+2]!='O'))
								{
									board[aicT][airT+2]='O';
									pMove--;
									aiMove=aiMove-7;
								}
								else
								{
									cout;
								}
							}
						}
					aiMove=aiMove-1;
					}
					else if (aiMove==3) //2 win
					{
						for(airT=0;airT<4;airT++) //2 win diagonal
						{
							for(aicT=0;aicT<7;aicT++)
							{
								if(aicT=0) //column 0
								{
									if(board[airT][aicT]=='O' &&
										board[airT+1][aicT+1]=='O' &&
										(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
										(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
									{
										board[airT+2][aicT+2]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else if(board[airT][aicT]=='O' &&
										board[airT+2][aicT+2]=='O' &&
										(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
										(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
									{
										board[airT+1][aicT+1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
								else if(aicT=6) //column 6
								{
									if(board[airT][aicT]=='O' &&
										board[airT+1][aicT-1]=='O' &&
										(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
										(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
									{
										board[airT+2][aicT-2]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else if(board[airT][aicT]=='O' &&
										board[airT+2][aicT-2]=='O' &&
										(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
										(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
									{
										board[airT+1][aicT-1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if(airT==0) //at row 0
									{
										if(aicT==1)
										{
											if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT+2]=='O' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else if (aicT>1 && aicT<5)
										{
											if(board[airT][aicT]=='O' &&
												(board[airT][aicT+1]=='X' || board[airT][aicT+1]=='O') &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT][aicT+2]=='O' || board[airT][aicT+2]=='X') &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
													(board[airT][aicT-1]=='X' || board[airT][aicT-1]=='O') &&
													board[airT+1][aicT-1]=='O' &&
													(board[airT][aicT-2]=='O' || board[airT][aicT-2]=='X') &&
													(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
													(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else
										{
											if(board[airT][aicT]=='O' &&
												(board[airT][aicT-1]=='X' || board[airT][aicT-1]=='O') &&
												board[airT+1][aicT-1]=='O' &&
												(board[airT][aicT-2]=='O' || board[airT][aicT-2]=='X') &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
										}
									}
									else if(airT==1) //at row 1
									{
										if(aicT==1)
										{
											if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT+2]=='O' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else if (aicT>1 && aicT<5)
										{
											if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT+2]=='O' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
													board[airT+1][aicT-1]=='O' &&
													(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
													(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
													board[airT+1][aicT-1]=='O' &&
													(board[airT-1][aicT+1]!='O' || board[airT-1][aicT+1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
													board[airT+2][aicT-2]=='O' &&
													(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
													(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
											{
												board[airT+1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else
										{
											if(board[airT][aicT]=='O' &&
												(board[airT][aicT-1]=='X' || board[airT][aicT-1]=='O') &&
												board[airT+1][aicT-1]=='O' &&
												(board[airT][aicT-2]=='O' || board[airT][aicT-2]=='X') &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT-1][aicT+1]!='O' || board[airT-1][aicT+1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
										}
									}
									else //row 2or3
									{
										if(aicT==1)
										{
											if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT-2][aicT-1]=='O' || board[airT-2][aicT-1]=='X') &&
												(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT+2]=='O' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else if (aicT>1 && aicT<5)
										{
											if(board[airT][aicT]=='O' &&
												board[airT+1][aicT+1]=='O' &&
												(board[airT+1][aicT+2]=='O' || board[airT+1][aicT+2]=='X') &&
												(board[airT+2][aicT+2]!='O' || board[airT+2][aicT+2]!='X'))
											{
												board[airT+2][aicT+2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
													board[airT+1][aicT+1]=='O' &&
													(board[airT-2][aicT-1]=='O' || board[airT-2][aicT-1]=='X') &&
													(board[airT-1][aicT-1]!='O' || board[airT-1][aicT-1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT+2]=='O' &&
												(board[airT][aicT+1]=='O' || board[airT][aicT+1]=='X') &&
												(board[airT+1][aicT+1]!='O' || board[airT+1][aicT+1]!='X'))
											{
												board[airT+1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+1][aicT-1]=='O' &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
													board[airT+1][aicT-1]=='O' &&
													(board[airT-2][aicT+1]=='O' || board[airT-2][aicT+1]=='X') &&
													(board[airT-1][aicT+1]!='O' || board[airT-1][aicT+1]!='X'))
											{
												board[airT-1][aicT+1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT-2]=='O' &&
												(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
												(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
											{
												board[airT+1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
										else
										{
											if(board[airT][aicT]=='O' &&
												board[airT+1][aicT-1]=='O' &&
												(board[airT+1][aicT-2]=='O' || board[airT+1][aicT-2]=='X') &&
												(board[airT+2][aicT-2]!='O' || board[airT+2][aicT-2]!='X'))
											{
												board[airT+2][aicT-2]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else if(board[airT][aicT]=='O' &&
												board[airT+2][aicT-2]=='O' &&
												(board[airT][aicT-1]=='O' || board[airT][aicT-1]=='X') &&
												(board[airT+1][aicT-1]!='O' || board[airT+1][aicT-1]!='X'))
											{
												board[airT+1][aicT-1]='O';
												pMove--;
												aiMove=aiMove-7;
											}
											else
											{
												cout;
											}
										}
									}
								}
							}
						}
						for(airT=0;airT<6;airT++) //2 win horizontal
						{
							for(aicT=0;aicT<7;aicT++)
							{
								if(aicT==0) //column 0
								{
									if(airT==0)
									{
										if(board[airT][aicT]=='O' &&
											board[airT][aicT+1]=='O' &&
											(board[airT][aicT+2]!='O' || board[airT][aicT+2]!='X'))
										{
											board[airT][aicT]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if (board[airT][aicT]=='O' &&
												board[airT][aicT+2]=='O' &&
												(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airT>0)
									{
										if(board[airT][aicT]=='O' &&
											board[airT][aicT+2]=='O' &&
											(board[airT-1][aicT+1]=='O' || board[airT-1][aicT+1]=='X') &&
											(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='O' &&
												board[airT][aicT+2]=='O' &&
												(board[airT-1][aicT+1]=='O' || board[airT-1][aicT+1]=='X') &&
												(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
									}	
									else
									{
										cout;
									}
								}	
								else if(aicT==6) //column 6
								{
									if(airT==0)
									{
										if(board[airT][aicT]=='O' &&
											board[airT][aicT-1]=='O' &&
											(board[airT][aicT-2]!='O' || board[airT][aicT-2]!='X'))
										{
											board[airT][aicT-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='O' &&
												board[airT][aicT-2]=='O' &&
												(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airT>0)
									{
										if(board[airT][aicT]=='O' &&
											board[airT][aicT-1]=='O' &&
											(board[airT-1][aicT-2]=='O' || board[airT-1][aicT-2]=='X') &&
											(board[airT][aicT-2]!='O' || board[airT][aicT-2]!='X'))
										{
											board[airT][aicT-2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='O' &&
												board[airT][aicT-2]=='O' &&
												(board[airT-1][aicT-1]=='O' || board[airT-1][aicT-1]=='X') &&
												(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
								}
								else //columns 1-5
								{
									if (airT==0)
									{
										if (board[airT][aicT]=='O' &&
											board[airT][aicT+1]=='O' &&
											(board[airT][aicT+2]!='O' || board[airT][aicT+2]!='X'))
										{
											board[airT][aicT+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if (board[airT][aicT]=='O' &&
											board[airT][aicT+1]=='O' &&
											(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='O' &&
											board[airT][aicT+2]=='O' &&
											(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airT>0)
									{
										if (board[airT][aicT]=='O' &&
											board[airT][aicT+1]=='O' &&
											(board[airT-1][aicT+2]=='O' || board[airT-1][aicT+2]=='X') &&
											(board[airT][aicT+2]!='O' || board[airT][aicT+2]!='X'))
										{
											board[airT][aicT+2]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if (board[airT][aicT]=='O' &&
											board[airT][aicT+1]=='O' &&
											(board[airT-1][aicT-1]=='O' || board[airT-1][aicT-1]=='X') &&
											(board[airT][aicT-1]!='O' || board[airT][aicT-1]!='X'))
										{
											board[airT][aicT-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airT][aicT]=='O' &&
											board[airT][aicT+2]=='O' &&
											(board[airT-1][aicT+1]=='O' || board[airT-1][aicT+1]=='X') &&
											(board[airT][aicT+1]!='O' || board[airT][aicT+1]!='X'))
										{
											board[airT][aicT+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
							}
						}
						for (airT=0;airT<4;airT++) //2 win verticle 
						{
							for(aicT=0;aicT<7;aicT++)
							{
								if(board[aicT][airT]=='O' &&
									board[aicT][airT+1]=='O' &&
									(board[aicT][airT+2]!='X' || board[aicT][airT+2]!='O'))
								{
									board[aicT][airT+2]='O';
									pMove--;
									aiMove=aiMove-7;
								}
								else
								{
									cout;
								}
							}
						}
					aiMove=aiMove-1;
					}
					else if(aiMove==2) //1 win
					{
						for(airOW=0;airOW<6;airOW++) //1 win diagonal
						{
							for (aicOW=0;aicOW<7;aicOW++)
							{
								if (aicOW==0) //column 0
								{
									if(board[airOW][aicOW]=='O' && 
										(board[airOW][aicOW+1]=='O' || board[airOW][aicOW+1]=='X')&& 
										(board[airOW+1][aicOW+1]!='O' || board[airOW+1][aicOW+1]!='X'))
									{
										board[airOW+1][aicOW+1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else 
									{
										cout;
									}
								}
								else if (aicOW==6) //column 6
								{
									if(board[airOW][aicOW]=='O' && 
										(board[airOW][aicOW-1]=='O' || board[airOW][aicOW-1]=='X')&& 
										(board[airOW+1][aicOW-1]!='O' || board[airOW+1][aicOW-1]!='X'))
									{
										board[airOW+1][aicOW-1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if (board[airOW][aicOW]=='O' && 
										(board[airOW][aicOW-1]=='O' || board[airOW][aicOW-1]=='X')&&
										(board[airOW+1][aicOW-1]!='O' || board[airOW+1][aicOW-1]!='X'))
									{
										board[airOW+1][aicOW-1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else if(board[airOW][aicOW]=='O' && 
											(board[airOW][aicOW+1]=='O' || board[airOW][aicOW+1]=='X')&& 
											(board[airOW+1][aicOW+1]!='O' || board[airOW+1][aicOW+1]!='X'))
									{
										board[airOW+1][aicOW+1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
							}
						}
						for(airOW=0;airOW<6;airOW++) //1 win horizontal
						{
							for(aicOW=0;aicOW<7;aicOW++)
							{
								if(aicOW==0) //column 0
								{
									if(airOW==0)
									{
										if(board[airOW][aicOW]=='O' &&
											(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airOW>0)
									{
										if(board[airOW][aicOW]=='O' && 
											(board[airOW-1][aicOW+1]=='O' || board[airOW-1][aicOW+1]=='X')&&
											(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
								else if(aicOW==6) //column 6
								{
									if(airOW==0)
									{
										if(board[airOW][aicOW]=='O' &&
											(board[airOW][aicOW-1]!='O' || board[airOW][aicOW]!='X'))
										{
											board[airOW][aicOW-1] =='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airOW>0)
									{
										if(board[airOW][aicOW]=='O' && 
											(board[airOW-1][aicOW-1]=='O' || board[airOW-1][aicOW-1]=='X')&&
											(board[airOW][aicOW-1]!='O' || board[airOW][aicOW-1]!='X'))
										{
											board[airOW][aicOW-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if(airOW==0)
									{
										if(board[airOW][aicOW]=='O' &&
											(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airOW>0)
									{
										if(board[airOW][aicOW]=='O' && 
											(board[airOW-1][aicOW-1]=='O' || board[airOW-1][aicOW-1]=='X')&&
											(board[airOW][aicOW-1]!='O' || board[airOW][aicOW-1]!='X'))
										{
											board[airOW][aicOW-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airOW][aicOW]=='O' && 
												(board[airOW-1][aicOW+1]=='O' ||board[airOW-1][aicOW+1]=='X')&&
												(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
							}
						}
						for(airOW=0;airOW<5;airOW++) //1 win verticle
						{
							for(aicOW=0;aicOW<7;aicOW++)
							{
								if(board[airOW][aicOW]=='O' && 
									(board[airOW+1][aicOW]!='X' || board[airOW+1][aicOW]!='O'))
								{
									board[airOW+1][aicOW]='O';
									pMove--;
									aiMove=aiMove-7;
								}
								else
								{
									cout;
								}
							}
						}
						aiMove=aiMove-1;
					}
					else //1 block 
					{
						
						for(airOW=0;airOW<6;airOW++) //1 block diagonal
						{
							for (aicOW=0;aicOW<7;aicOW++)
							{
								if (aicOW==0) //column 0
								{
									if(board[airOW][aicOW]=='X' && 
										(board[airOW][aicOW+1]=='O' || board[airOW][aicOW+1]=='X')&& 
										(board[airOW+1][aicOW+1]!='O' || board[airOW+1][aicOW+1]!='X'))
									{
										board[airOW+1][aicOW+1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else 
									{
										cout;
									}
								}
								else if (aicOW==6) //column 6
								{
									if(board[airOW][aicOW]=='X' && 
										(board[airOW][aicOW-1]=='O' || board[airOW][aicOW-1]=='X')&& 
										(board[airOW+1][aicOW-1]!='O' || board[airOW+1][aicOW-1]!='X'))
									{
										board[airOW+1][aicOW-1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if (board[airOW][aicOW]=='X' && 
										(board[airOW][aicOW-1]=='O' || board[airOW][aicOW-1]=='X')&&
										(board[airOW+1][aicOW-1]!='O' || board[airOW+1][aicOW-1]!='X'))
									{
										board[airOW+1][aicOW-1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else if(board[airOW][aicOW]=='X' && 
											(board[airOW][aicOW+1]=='O' || board[airOW][aicOW+1]=='X')&& 
											(board[airOW+1][aicOW+1]!='O' || board[airOW+1][aicOW+1]!='X'))
									{
										board[airOW+1][aicOW+1]='O';
										pMove--;
										aiMove=aiMove-7;
									}
									else
									{
										cout;
									}
								}
							}
						}
						for(airOW=0;airOW<6;airOW++) //1 block horizontal
						{
							for(aicOW=0;aicOW<7;aicOW++)
							{
								if(aicOW==0) //column 0
								{
									if(airOW==0)
									{
										if(board[airOW][aicOW]=='X' &&
											(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airOW>0)
									{
										if(board[airOW][aicOW]=='X' && 
											(board[airOW-1][aicOW+1]=='O' || board[airOW-1][aicOW+1]=='X')&&
											(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else 
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
								else if(aicOW==6) //column 6
								{
									if(airOW==0)
									{
										if(board[airOW][aicOW]=='X' &&
											(board[airOW][aicOW-1]!='O' || board[airOW][aicOW]!='X'))
										{
											board[airOW][aicOW-1] =='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airOW>0)
									{
										if(board[airOW][aicOW]=='X' && 
											(board[airOW-1][aicOW-1]=='O' || board[airOW-1][aicOW-1]=='X')&&
											(board[airOW][aicOW-1]!='O' || board[airOW][aicOW-1]!='X'))
										{
											board[airOW][aicOW-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
								else //columns 1-5
								{
									if(airOW==0)
									{
										if(board[airOW][aicOW]=='X' &&
											(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else if(airOW>0)
									{
										if(board[airOW][aicOW]=='X' && 
											(board[airOW-1][aicOW-1]=='O' ||board[airOW-1][aicOW-1]=='X')&&
											(board[airOW][aicOW-1]!='O' || board[airOW][aicOW-1]!='X'))
										{
											board[airOW][aicOW-1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else if(board[airOW][aicOW]=='X' && 
												(board[airOW-1][aicOW+1]=='O' || board[airOW-1][aicOW+1]=='X')&&
												(board[airOW][aicOW+1]!='O' || board[airOW][aicOW+1]!='X'))
										{
											board[airOW][aicOW+1]='O';
											pMove--;
											aiMove=aiMove-7;
										}
										else
										{
											cout;
										}
									}
									else
									{
										cout;
									}
								}
							}
						}
						for(airOW=0;airOW<5;airOW++) //1 block verticle
						{
							for(aicOW=0;aicOW<7;aicOW++)
							{
								if(board[airOW][aicOW]=='O' && 
									(board[airOW+1][aicOW]!='X' || board[airOW+1][aicOW]!='O'))
								{
									board[airOW+1][aicOW]='O';
									pMove--;
									aiMove=aiMove-7;
								}
								else
								{
									cout;
								}
							}
						}	
					}
				}
				
				// check for win
					for (hrCheck=0;hrCheck<6;hrCheck++) //horizontal win check
					{
						for (hcCheck=0;hcCheck<4;hcCheck++)
						{
							if (board[hrCheck][hcCheck]=='X' && 
								board[hrCheck][hcCheck+1]=='X' && 
								board[hrCheck][hcCheck+2]=='X' && 
								board[hrCheck][hcCheck+3]=='X')
							{
								cout << "Good Job Player 1 you're the winner!!1!" << endl;
								game=game+43;
							}
							else
							{
								cout;
							}
						}
					}
					for (vcCheck=0;vcCheck<7;vcCheck++) //verticle win check
					{
						for(vrCheck=0;vrCheck<3;vrCheck++)
						{
							if(board[vrCheck][vcCheck]=='X' && 
								board[vrCheck+1][vcCheck]=='X' && 
								board[vrCheck+2][vcCheck]=='X' && 
								board[vrCheck+3][vcCheck]=='X')
								{
									cout << "Good Job Player 1 you're the winner!!1!" << endl;
									game=game+43;
								}
							else
							{
								cout;
							}
						}
					}
					for (drCheck=0;drCheck<3;drCheck++)//diagonal win
					{
						for (dcCheck=0;dcCheck<7;dcCheck++)
						{
							if (dcCheck<3)//0-2
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck+1]=='X' && 
									board[drCheck+2][dcCheck+2]=='X' && 
									board[drCheck+3][dcCheck+3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else if (dcCheck>3)//4-6
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck-1]=='X' && 
									board[drCheck+2][dcCheck-2]=='X' && 
									board[drCheck+3][dcCheck-3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else
								{
									cout;
								}
							}
							else //for 3
							{
								if(board[drCheck][dcCheck]=='X' && 
									board[drCheck+1][dcCheck+1]=='X' && 
									board[drCheck+2][dcCheck+2]=='X' && 
									board[drCheck+3][dcCheck+3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else if(board[drCheck][dcCheck]=='X' && 
										board[drCheck+1][dcCheck-1]=='X' && 
										board[drCheck+2][dcCheck-2]=='X' && 
										board[drCheck+3][dcCheck-3]=='X')
									{
										cout << "Good Job Player 1 you're the winner!!1!" << endl;
										game=game+43;
									}
								else 
								{
									cout;
								}
							}
						}
					}
			}
		}
		cout << "Game Over!" << endl;
	}
	else 
	{
		cout << "can't have that number of people" << endl;
	}
	
	outfile.close();
	return 0;
} 

void drawboard(ostream & out, char b[][7], int r, int c) {
	out << endl;
	for (int x = r-1; x >= 0; x--) {
		out << "|";
		for (int y = 0; y < c-1; y++)
			out << "----";
		out << "---|" << endl << "|";
		for (int y = 0; y < c-1; y++)
			if (b[x][y] == 0)
				out << "   |";
			else
				out << " " << b[x][y] << " |";
		if (b[x][c-1] == 0)
			out << "   | " << x << endl;
		else
			out << " " << b[x][c-1] << " | " << x << endl;
	}
	
	out << "|";
	for (int y = 0; y < c-1; y++)
		out << "----";
	out << "---|" << endl;
	
	out << " ";
	for (int y = 0; y < c; y++)
		out << " " << y << "  ";
	out << endl << endl;

} 

void drawcolorboard(ostream & out, char b[][7], int r, int c) {
	out << "\033[1;37m"; 
	out << endl;
	for (int x = r-1; x >= 0; x--) {
		out << "|";
		for (int y = 0; y < c-1; y++)
			out << "----";
		out << "---|" << endl << "|";
		for (int y = 0; y < c-1; y++)
			if (b[x][y] == 0)
				out << "   |";
			else if (b[x][y] == 'X')
				out << " \033[1;31m" << b[x][y] << "\033[1;37m |";
			else
				out << " \033[1;34m" << b[x][y] << "\033[1;37m |";				
		if (b[x][c-1] == 0)
			out << "   | " << x << endl;
		else if (b[x][c-1] == 'X')
			out << " \033[1;31m" << b[x][c-1] << "\033[1;37m |" << x << endl;
		else
			out << " \033[1;34m" << b[x][c-1] << "\033[1;37m |" << x << endl;
	}
	
	out << "|";
	for (int y = 0; y < c-1; y++)
		out << "----";
	out << "---|" << endl;
	
	out << " ";
	for (int y = 0; y < c; y++)
		out << " " << y << "  ";
	out << "\033[0m";
	out << endl << endl;

}