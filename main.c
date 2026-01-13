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

char choicedPlayer;


int main() 
{
	printf("\033[34m\033[1mWelcome to Tic-tac-toe Game in C\033[0m\n");
	Sleep(300);
	printf("Which one would you like to start with, X or O?\n");
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
			printf("\n\033[31mERROR:\033[0m Invalid input! Please enter X or O!\n");
		}
	}
	
	terminalClear();
	//Sleep(1000);
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
	int i,j,k;
	
	for(i=0;i<3;i++)
	{
		if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
		{
			whoWin = 'X';
		}	
	}
	
	for(i=0;i<3;i++)
	{
		if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
		{	
			whoWin = 'O';
		}	
	}
	
	for(j=0;j<3;j++)
	{
		if(board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X')
		{
			whoWin = 'X';
		}	
	}
	
	for(j=0;j<3;j++)
	{
		if(board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O')
		{	
			whoWin = 'O';
		}	
	}
	if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		whoWin = 'O';
	}
	if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		whoWin = 'X';
	}
	if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		whoWin = 'O';
	}
	if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		whoWin = 'X';
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
		if(whoWin =='X')
		{
			printf("Congratulations, X won!");
			break;
		}
		if(whoWin == 'O')
		{
			printf("Congratulations, O won!");
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
        		printf("\n\033[31mERROR:\033[0m This box is already full! Please move it elsewhere.\n");
       	 		Sleep(1500); // Kullanýcý hatayý okuyabilsin diye bekle
			}
			else
			{
				if(choicedPlayer == 'X')
	        	{
	        		choicedPlayer = 'O';
	        		board[row][column] = 'X';
		            printf("\nSelected!\n");
		            Sleep(100);
				}
				
				else if(choicedPlayer == 'O')
	        	{
	        		choicedPlayer = 'X';
	        		board[row][column] = 'O';
		            printf("\nSelected!\n");
		            Sleep(100);
				}	
			}
        }
        else if(selectedDirection != 'Q' || selectedDirection != 'q')
        {
        	printf("\nProgram is closed");
        	Sleep(200);
		}
		else
		{
			terminalClear();
			printf("\nWarning: %c is not a valid value. Please enter valid input!\n", selectedDirection);
		}
	}
}

