/*
 * hw5_1_Ekperigin.c
 *
 *  Created on: Mar 1, 2017
 *      Author: Ebisan
 */

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
// BOARD SIZE CONSTANT
#define BOARD_SIZE 8
// PLAYER CONSTANTS
#define PLAYER1 1
#define PLAYER2 2
// BOARD SPACE CONSTANTS
#define EMPTY_SPACE 0
#define P1_SPACE 1
#define P2_SPACE 2


int validateInput(void);// function prototype
int playMove(int x, int y, int PLAYER, int board[BOARD_SIZE][BOARD_SIZE]); // function prototype
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]); // function prototype

int main(void)
{

	int BoardArray[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE}}; // assigning boardarray to empty space macro
	// assigning specific array positions to players
	BoardArray[3][3] = P1_SPACE;
	BoardArray[4][4] = P1_SPACE;
	BoardArray[3][4] = P2_SPACE;
	BoardArray[4][3]= P2_SPACE;
	int firstX,firstY,flag,turns = PLAYER1; //initializing variables
	float p1Score = 2, p2Score = 2; // Initialize float variables
	char p1FirstName[40], p1LastName[40], p2FirstName[40], p2LastName[40]; // Define the character Arrays
	puts("Welcome to X Game!\n"); // skip to line
	printf("Enter Player 1's First Name: ");
	scanf("%s", p1FirstName); // No need for & because array is already the memory address
	printf("Enter Player 1's Last Name: ");
	scanf("%s", p1LastName);
	printf("Enter Player 2's First Name: ");
	scanf("%s", p2FirstName);
	printf("Enter Player 2's Last Name: ");
	scanf("%s", p2LastName);

	printf("\n");
	printBoard(BoardArray); // print generic board using array

	do{ //loop to allow user enter valid coordinates and rotate turns
			printf("%s %s's Score (B): %.1f\n",p1FirstName, p1LastName, p1Score );
			printf("%s %s's Score (W): %.1f\n",p2FirstName, p2LastName, p2Score );
			printf("\n");
			if(turns%2 == PLAYER1){ // determine whose turn it is
				printf("%s %s, It is your turn.",p1FirstName, p1LastName);
			}
			else{
				printf("%s %s, It is your turn.",p2FirstName, p2LastName);}
			printf("\n");
			printf("\n");
			printf("Enter First X coordinate: ");
			firstX = validateInput(); // validate the inputs that are entered
			printf("Enter first Y coordinate: ");;
			firstY = validateInput();

			playMove(firstX,firstY,turns, BoardArray); // takes user input and the board array

			printf("Enter an integer to continue(q to exit): \n");
			turns++; // Increment turns to determine next Player
	}while(scanf("%d", &flag));

}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
	int x,y;
	// printing the numbers
	printf("   ");
	for(x = 1; x<=BOARD_SIZE; x++){// printing the horizontal numbers in order
		printf("%2d", x);
	}
	printf("\n");
	for(y = 1; y<BOARD_SIZE+1; y++){ //printing the vertical numbers
		printf("%2d ", y);

		for(x=0;x<BOARD_SIZE;x++) //nested for to print the dots, b's or w's
		{
			if(board[x][y-1] == P1_SPACE) // if the array space is assigned to Player1 (-1 to compensate for y = 1)
			{
					printf(" B");
			}
			else if (board[x][y-1] == P2_SPACE) // if the array space is assigned to Player2 (-1 to compensate for y = 1)
			{
				printf(" W");
			}
			else
			printf(" .");
		}
		printf("\n");
	}
}



int validateInput(void) // function to validate input
{
	int check;
	while(!(scanf("%d", &check)) || (check < 1 || check > BOARD_SIZE))
	{
		while(getchar()!= '\n'){}
		printf("Invalid Input. Enter Again: ");
	}
	return check;
}

int playMove(int x, int y, int turns, int board[BOARD_SIZE][BOARD_SIZE])
{
	if(turns%2 == PLAYER1) // checking when turn is player one
	{
		board[x-1][y-1] = P1_SPACE; // assigning the array position to board one (-1 to compensate for y = 1 and x = 1)
	} else {
		board[x-1][y-1] = P2_SPACE; // assigning the array position to board two (-1 to compensate for y = 1 and x = 1)
	}
	printBoard(board); // recursive print board function to print in the right letters for each player
	return 1;

}
