#pragma once
#include <iostream>
#include <vector>
#define MAXSIZE 100 //定义栈的最大容量
#define TRUE 1
#define FALSE 0
#define WALL 'w' //定义墙的值
#define ROAD 'p' //定义路的值
#define ROW 25 //定义迷宫的行数
#define COL 25 //定义迷宫的列数
#define STARTROW 1//起点行位置
#define STARTCOL 0//起点列位置
#define ENDROW 19//终点行位置
#define ENDCOL 24//终点列位置
#define ROWS 23  // 迷宫的行数为23
#define COLS 23  // 迷宫的列数为23
//定义一个坐标结构体
typedef struct {
	int x; //横坐标
	int y; //纵坐标
} Point;

//定义一个栈结构体
typedef struct {
	Point data[MAXSIZE]; //存储坐标的数组
	int top; //栈顶指针
} Stack;
//模拟队列,用于bfs寻找迷宫通路
struct queue
{
	int pre;//记录上一个位置在队列中的索引
	int x;//行
	int y;//列
	char dir;//direction方向，表示父亲是通过该方向到达这个位置的
};

void initializeMaze(char maze[ROWS][COLS]);// 初始化迷宫，将所有位置设置为墙
bool isValid(int x, int y);// 检查坐标是否在有效范围内
void generateMaze(char maze[ROWS][COLS], int x, int y, int targetX, int targetY);// 使用深度优先搜索生成迷宫路径
void convertToNewArray(char maze[ROWS][COLS], char newArray[ROWS + 2][COLS + 2]); // 将迷宫转换为新数组，添加边界
void getMaze(char maze[ROWS][COLS],char newArray[ROWS + 2][COLS + 2]);



char* bfs(char maze[ROW][COL], int playerX, int playerY);//bfs寻找迷宫通路
void bfsMark(char* route,int x,int y, int mazeStartX, int mazeStartY);//通过bfs得到的路径，对道路进行标记。route为路径信息。x,y为当前玩家位置信息
void dfs(int x, int y, int step, int book[31][51], int* min1, int q, char* route, char* result, int k[4][2], char maze[ROW][COL]);//x:指该位置处于第x行，y:指该位置处于第y列，step指花的步数
void dfsMark(char maze[ROW][COL], int x, int y, int mazeStartX, int mazeStartY);