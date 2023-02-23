#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void InitBoard(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}


void GameStart(char board[Row][Col], int row, int col)
{
	char ret = 'C';
	//初始化棋盘
	InitBoard(board, Row, Col);
	//显示棋盘
	DisplayBoard(board,row,col);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, row, col);
		//电脑下棋
		ComMove(board, row, col);
		ret = IsWin(board, row, col);
		if ('O' == ret)
		{
			printf("恭喜您，取得胜利！\n");
			break;
		}
		if ('X' == ret)
		{
			printf("很遗憾，您输了:(\n");
			break;
		}
		if ('Q' == ret)
		{
			printf("平局！！！\n");
			break;
		}
		if ('C' == ret)
		{
			printf("继续游戏：\n");
		}
		


	}


}


void DisplayBoard(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row-1; i++)
	{
		for (int j = 0; j < col-1; j++)
		{
			printf(" %c |", board[i][j]);
			if (j == col-2)
				printf("\n");
		}
		for (int j = 0; j < col - 1; j++)
		{
			printf("---|");
			if (j == col-2)
				printf("---\n");
		}
		if (i == row - 2)
		{
			for (int j = 0; j < col - 1; j++)
			{
				printf(" %c |", board[i][j]);
				if (j == col - 2)
					printf(" %c \n", board[i][j]);
			}
		}
	}
}


void PlayerMove(char board[Row][Col], int row, int col)
{
	int x = 0, y = 0;
	int IsLegal = 0;
	printf("请输入您要下棋的坐标,用空格分开：>\n");
	scanf("%d %d", &x, &y);
	do
	{
		
		if (1 <= x && 3 >= x && 1 <= y && 3 >= y)
		{

			board[x-1][y-1] = 'O';
			IsLegal = 0;
		}
	} while (IsLegal);
	DisplayBoard(board, row, col);
	
}


void ComMove(char board[Row][Col], int row, int col)
{
	int randrow = 0;
	int randcol = 0;
	while (1)
	{
		randrow = rand() % 3;
		randcol = rand() % 3;
		if (board[randrow][randcol] == ' ')
		{
			board[randrow][randcol] = 'X';
			printf("电脑下棋：\n");
			DisplayBoard(board, row, col);
			break;
		}
	}



	;
}


char IsWin(char board[Row][Col], int row, int col)
{
	//三行相等
	int ret = 0;
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1]&& board[i][1] == board[i][2]&& board[i][0]!=' ')
			return board[i][0];
	}
	for (int i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i]&& board[0][i] == board[2][i]&& board[0][i]!=0)
			return board[0][1];
	}
	if (board[0][0] == board[1][1]&& board[1][1] == board[2][2] && board[1][1]!=' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	ret = IsFull(board,row,col);
	if (1 == ret)
		return 'Q';
	return 'C';
}


int IsFull(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (board[j][j] == ' ')
				return 0;
	}
	return 1;
}


