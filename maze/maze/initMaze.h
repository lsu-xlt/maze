#pragma once
#include <iostream>
#include <vector>
#define MAXSIZE 100 //����ջ���������
#define TRUE 1
#define FALSE 0
#define WALL 'w' //����ǽ��ֵ
#define ROAD 'p' //����·��ֵ
#define ROW 25 //�����Թ�������
#define COL 25 //�����Թ�������
#define STARTROW 1//�����λ��
#define STARTCOL 0//�����λ��
#define ENDROW 19//�յ���λ��
#define ENDCOL 24//�յ���λ��
#define ROWS 23  // �Թ�������Ϊ23
#define COLS 23  // �Թ�������Ϊ23
//����һ������ṹ��
typedef struct {
	int x; //������
	int y; //������
} Point;

//����һ��ջ�ṹ��
typedef struct {
	Point data[MAXSIZE]; //�洢���������
	int top; //ջ��ָ��
} Stack;
//ģ�����,����bfsѰ���Թ�ͨ·
struct queue
{
	int pre;//��¼��һ��λ���ڶ����е�����
	int x;//��
	int y;//��
	char dir;//direction���򣬱�ʾ������ͨ���÷��򵽴����λ�õ�
};

void initializeMaze(char maze[ROWS][COLS]);// ��ʼ���Թ���������λ������Ϊǽ
bool isValid(int x, int y);// ��������Ƿ�����Ч��Χ��
void generateMaze(char maze[ROWS][COLS], int x, int y, int targetX, int targetY);// ʹ������������������Թ�·��
void convertToNewArray(char maze[ROWS][COLS], char newArray[ROWS + 2][COLS + 2]); // ���Թ�ת��Ϊ�����飬��ӱ߽�
void getMaze(char maze[ROWS][COLS],char newArray[ROWS + 2][COLS + 2]);



char* bfs(char maze[ROW][COL], int playerX, int playerY);//bfsѰ���Թ�ͨ·
void bfsMark(char* route,int x,int y, int mazeStartX, int mazeStartY);//ͨ��bfs�õ���·�����Ե�·���б�ǡ�routeΪ·����Ϣ��x,yΪ��ǰ���λ����Ϣ
void dfs(int x, int y, int step, int book[31][51], int* min1, int q, char* route, char* result, int k[4][2], char maze[ROW][COL]);//x:ָ��λ�ô��ڵ�x�У�y:ָ��λ�ô��ڵ�y�У�stepָ���Ĳ���
void dfsMark(char maze[ROW][COL], int x, int y, int mazeStartX, int mazeStartY);