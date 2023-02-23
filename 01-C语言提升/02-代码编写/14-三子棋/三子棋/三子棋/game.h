#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define Row 3
#define Col 3





void InitBoard(char Board[Row][Col], int row, int col);
void GameStart(char Board[Row][Col], int row, int col);
void DisplayBoard(char Board[Row][Col], int row, int col);
void PlayerMove (char Board[Row][Col], int row, int col);
void ComMove (char Board[Row][Col], int row, int col);
char IsWin(char Board[Row][Col], int row, int col);
int IsFull(char Board[Row][Col], int row, int col);


char Board[Row][Col] = { 0 };
