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
			printf("���ʤ��\n");
			break;
		}
		else if (ret == '#')
		{
			printf("����ʤ��\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		comboard(board, ROW, COL);
		showboard(board, ROW, COL);
		ret = Is_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("���ʤ��\n");
			break;
		}
		else if (ret == '#')
		{
			printf("����ʤ��\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
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
		printf("�����룺>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
		}
	}
		while (input);
}

int main()
{
	test();
	return 0;
}