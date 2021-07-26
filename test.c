#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
char ret = 0;
void menu()
{
	printf("**********************************\n");
	printf("*****  1.play        0.exit  *****\n");
	printf("**********************************\n");
}
	
void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	showboard(board, ROW, COL);
	while (1)
	{
		getboard(board, ROW, COL);
		showboard(board, ROW, COL);
		ret= Is_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家胜利\n");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑胜利\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
		comboard(board, ROW, COL);
		showboard(board, ROW, COL);
		ret = Is_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家胜利\n");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑胜利\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
	}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	}
		while (input);
}

int main()
{
	test();
	return 0;
}