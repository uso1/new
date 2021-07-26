#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
			board[i][j] = ' ';
	}
}

void showboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
			
		}
		printf("\n");
		for (j = 0;j < col;j++)
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			
		}
		printf("\n");
	}
}
void getboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("玩家走:>");
		scanf("%d %d", &i, &j);
		if (i<1||i > row|| j<1|| j>col)
			printf("没有该格子，请重新输入\n");
		else
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("此格子已经被占,请重新输入\n");
		}
	}
}
void comboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑走:\n");
	while (1)
	{
		i = rand() % 3;
		j = rand() % 3;
			if (board[i][j] == ' ')
			{
				board[i][j] = '#';
				break;
			}
	}
}
char Is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == '*')
			return '*';
		else if (board[0][0] == '#')
			return '#';
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[1][1] == '*')
			return '*';
		else if (board[1][1] == '#')
			return '#';
	}
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][1] == '*')
				return '*';
			else if (board[i][1] == '#')
				return '#';
		}
		for (j = 0;j < col;j++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
			{
				if (board[0][j] == '*')
					return '*';
				else if (board[0][j] == '#')
					return '#';
			}
		}
	}
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
}
