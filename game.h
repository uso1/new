#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void initboard(char board[ROW][COL], int row, int col);
void showboard(char board[ROW][COL], int row, int col);
void getboard(char board[ROW][COL], int row, int col);
void comboard(char board[ROW][COL], int row, int col);
char Is_win(char board[ROW][COL], int row, int col);