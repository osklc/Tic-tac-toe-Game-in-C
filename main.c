#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void terminalClear();
void cursorControl();
void printBoard();
void boardFiller();
void winningQuestioner();

int row=0;
int column=0;
char board[3][3];
char whoWin;
int moveCount=0;

char choicedPlayer;


int main() 
{
	printf("\033[34m\033[1mWelcome to Tic-tac-toe Game in C\033[0m\n");
	Sleep(400);
	printf("Which one would you like to start with, X or O?");
	while(1)
	{
		choicedPlayer = getch();
		choicedPlayer = toupper(choicedPlayer);
		if(choicedPlayer == 'X' || choicedPlayer == 'O')
		{
			break;
		}
		else
		{
			printf("\n\033[3m\033[31mERROR:\033[0m Invalid input! Please enter X or O!");
		}
	}
	
	terminalClear();
	boardFiller();
	cursorControl();
	
	return 0;
}

void boardFiller()
{
	int m,n;
	
	for(m=0;m<3;m++)
	{
		for(n=0;n<3;n++)
		{
			board[m][n] = ' ';
		}
	}
}

void printBoard()
{
	int i,j;
	printf("\n");
	
	for(i=0;i<3;i++)
	{
		printf("\t       |       |       \n");
		printf("\t");
		for(j=0;j<3;j++)
		{
			if(i==row && j== column)
			{
				printf("  [%c]  ", board[i][j]);
			}
			else
			{
				printf("   %c   ",board[i][j]);
			}
			if(j<2)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < 2) {
            printf("\t_______|_______|_______\n");
        } else {
            printf("\t       |       |       \n");
        }
	}
}

void terminalClear()
{
	system("cls");
}

void winningQuestioner()
{
	int i;
	
	for(i=0; i<3; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
        	whoWin = board[i][0];
		}
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			whoWin = board[0][i];
		}
	}
	
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		whoWin = board[0][0];
	}
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		whoWin = board[0][2];
	}
		
}

void cursorControl()
{
	char selectedDirection = ' ';
	whoWin = ' ';
	
	while(selectedDirection != 'Q' && selectedDirection != 'q')
	{
		terminalClear();
		printBoard();
		winningQuestioner();
		if(moveCount==9)
		{
			printf("\n\033[3m\033[33mIt's a DRAW!\033[0m");
			getch();
			break;
		}
		if(whoWin != ' ')
		{
			printf("\n\033[3m\033[32mCongratulations!\033[0m Player %c WINS!", whoWin);
			getch();
			break;
		}
		
		printf("\nActive Cell: [%d , %d]", row, column); // For Debug
        printf("\n[W-A-S-D] Move  |  [F] Select  |  [Q] Quit");
        printf("\nSelection: ");
		selectedDirection = getch();
		
		if(selectedDirection == 'W' || selectedDirection == 'w')
        {
            row--; 
            if(row < 0) row = 0; // En üste çarparsa 0'da kalsýn
        }
        else if(selectedDirection == 'S' || selectedDirection == 's')
        {
            row++;
            if(row > 2) row = 2; // En alta çarparsa 2'de kalsýn
        }
        else if(selectedDirection == 'A' || selectedDirection == 'a')
        {
            column--;
            if(column < 0) column = 0; // Sola çarparsa 0'da kalsýn
        }
        else if(selectedDirection == 'D' || selectedDirection == 'd')
        {
            column++;
            if(column > 2) column = 2; // Saða çarparsa 2'de kalsýn
        }
        else if(selectedDirection == 'F' || selectedDirection == 'f')
        {
        	if(board[row][column] != ' ')
        	{
        		printf("\n\033[3m\033[31mERROR:\033[0m This box is already full! Please move it elsewhere.");
       	 		Sleep(1500); // Kullanýcý hatayý okuyabilsin diye bekle
			}
			else
			{
				board[row][column] = choicedPlayer;
				if(choicedPlayer == 'X')
	        	{
	        		moveCount++;
	        		choicedPlayer = 'O';
		            printf("\nSelected!\n");
		            Sleep(100);
				}
				
				else if(choicedPlayer == 'O')
	        	{
	        		moveCount++;
	        		choicedPlayer = 'X';
		            printf("\nSelected!\n");
		            Sleep(100);
				}	
			}
        }
        else if(selectedDirection == 'Q' || selectedDirection == 'q')
        {
        	printf("\nProgram is closed");
        	Sleep(200);
		}
		else
		{
			printf("\n\033[3m\033[31mERROR:\033[0m %c is not a valid value. Please enter valid input!", selectedDirection);
			Sleep(1000);
		}
	}
}

