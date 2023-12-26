
#include <iostream>
#include <vector>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include <time.h>
#include"initMaze.h"
 using namespace std;
#define BORDER 'w'  // 迷宫边界用字符'w'表示

 // 初始化迷宫，将所有位置设置为墙
 void initializeMaze(char maze[ROWS][COLS]) {
	 for (int i = 0; i < ROWS; i++) {
		 for (int j = 0; j < COLS; j++) {
			 maze[i][j] = 'w';
		 }
	 }
 }


 // 检查坐标是否在有效范围内
 bool isValid(int x, int y) {
	 return x >= 0 && x < ROWS && y >= 0 && y < COLS;
 }

 // 使用深度优先搜索生成迷宫路径
 void generateMaze(char maze[ROWS][COLS], int x, int y, int targetX, int targetY) {
	 // 定义四个方向：上、下、左、右
	 int dx[] = { -1, 1, 0, 0 };
	 int dy[] = { 0, 0, -1, 1 };

	 // 随机打乱方向数组
	 for (int i = 0; i < 4; i++) {
		 int r = rand() % 4;
		 int temp = dx[i];
		 dx[i] = dx[r];
		 dx[r] = temp;

		 temp = dy[i];
		 dy[i] = dy[r];
		 dy[r] = temp;
	 }

	 // 尝试每个方向
	 for (int i = 0; i < 4; i++) {
		 int nx = x + 2 * dx[i];
		 int ny = y + 2 * dy[i];

		 // 检查新位置是否在有效范围内且是墙
		 if (isValid(nx, ny) && maze[nx][ny] == 'w') {
			 // 将中间位置和新位置设置为通道
			 maze[x + dx[i]][y + dy[i]] = 'p';
			 maze[nx][ny] = 'p';

			 if (nx == targetX && ny == targetY) {
				 // 如果达到目标位置，可以在这里执行特殊操作
				 // 例如，标记路径或其他处理
			 }
			 else {
				 generateMaze(maze, nx, ny, targetX, targetY);
			 }
		 }
	 }
 }

 // 将迷宫转换为新数组，添加边界
 void convertToNewArray(char maze[ROWS][COLS], char newArray[ROWS + 2][COLS + 2]) {
	 for (int i = 0; i < ROWS; i++) {
		 for (int j = 0; j < COLS; j++) {
			 newArray[i + 1][j + 1] = maze[i][j];
		 }
	 }

	 // 添加边界
	 for (int i = 0; i < ROWS + 2; i++) {
		 for (int j = 0; j < COLS + 2; j++) {
			 if (i == 0 || j == 0 || i == ROWS + 1 || j == COLS + 1) {
				 newArray[i][j] = 'w';
			 }
		 }
	 }
	 // 设置起始点和目标点
	 newArray[1][0] = 'p';
	 newArray[19][24] = 'p';
 }

 void getMaze(char maze[ROWS][COLS], char newArray[ROWS + 2][COLS + 2]) {


	 // 初始化随机数生成器
	 srand(time(NULL));

	 // 初始化迷宫，将所有位置设置为墙
	 initializeMaze(maze);

	 // 将起始点设置为墙
	 maze[0][0] = 'w';

	 // 随机选择起始点
	 int startX = rand() % (ROWS / 2) * 2;
	 int startY = rand() % (COLS / 2) * 2;

	 // 使用深度优先搜索生成迷宫路径
	 generateMaze(maze, startX, startY, 19, 23);

	 // 将迷宫转换为新数组，添加边界
	 convertToNewArray(maze, newArray);

	 return;
 }

































//bfs寻找迷宫通路
char* bfs(char maze[ROW][COL],int playerX,int playerY)
{
	int len;
	int book[31][51] = { 0 };
	char route[626];
	int i, j;
	int head = 0, tail = 0;
	struct queue q[626];
	q[0].pre = -1;
	q[0].x = playerX;
	q[0].y = playerY;
	q[0].dir = 'p';//入口就是最初的位置，用p表示它是入口
	tail++;
	while (!(q[head].x == ENDROW && q[head].y == ENDCOL) && head<tail)
	{
		//向下：行加1，列不变
		if (q[head].x + 1 < ROW && book[q[head].x + 1][q[head].y] == 0 && (maze[q[head].x + 1][q[head].y] == 'p' || maze[q[head].x + 1][q[head].y]=='c'))
		{
			//入队
			q[tail].pre = head;//记住父亲的位置
			q[tail].x = q[head].x + 1;
			q[tail].y = q[head].y;
			q[tail].dir = 'D';
			book[q[head].x + 1][q[head].y] = 1;
			tail++;
		}
		//向左：行不变，列减1
		if (q[head].y - 1 >= 0 && book[q[head].x][q[head].y - 1] == 0 && (maze[q[head].x][q[head].y - 1] == 'p' || maze[q[head].x][q[head].y - 1] == 'c'))
		{
			//入队
			q[tail].pre = head;//记住父亲的位置
			q[tail].x = q[head].x;
			q[tail].y = q[head].y - 1;
			q[tail].dir = 'L';
			book[q[head].x][q[head].y - 1] = 1;
			tail++;
		}

		//向右：行不变，列加1
		if (q[head].y + 1 < COL && book[q[head].x][q[head].y + 1] == 0 && (maze[q[head].x][q[head].y + 1] == 'p' || maze[q[head].x][q[head].y + 1] == 'c'))
		{
			//入队
			q[tail].pre = head;//记住父亲的位置
			q[tail].x = q[head].x;
			q[tail].y = q[head].y + 1;
			q[tail].dir = 'R';
			book[q[head].x][q[head].y + 1] = 1;
			tail++;
		}
		//向上: 行减1，列不变
		if (q[head].x - 1 >= 0 && book[q[head].x - 1][q[head].y] == 0 && (maze[q[head].x - 1][q[head].y] == 'p' || maze[q[head].x - 1][q[head].y]=='c'))
		{
			//入队
			q[tail].pre = head;//记住父亲的位置
			q[tail].x = q[head].x - 1;
			q[tail].y = q[head].y;
			q[tail].dir = 'U';
			book[q[head].x - 1][q[head].y] = 1;
			tail++;
		}
		head++;
	}
	if (head == tail)
		head--;
	len = 0;
	while (q[head].dir != 'p')
	{
		route[len++] = q[head].dir;
		head = q[head].pre;
	}
	/*for (i = len - 1; i >= 0; i--)
		printf("%c", route[i]);*/
	printf("进行了bfs路径规划，bfs路径长度为%d\n", len);
	return route;
}

//通过bfs得到的路径，对道路进行标记。route为路径信息。x,y为当前玩家位置信息
void bfsMark(char* route,int x,int y,int mazeStartX,int mazeStartY)
{
	int i;
	BeginBatchDraw();
	for (i = strlen(route) - 1; i >= 0; i--)
	{
		if (route[i] == 'D')
		{
			x += 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
		else if (route[i] == 'R')
		{
			y += 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			//mazeStartX对应宽度，所以与y相加，mazeStartY对应长度，所以与x相加
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
		else if (route[i] == 'L')
		{
			y -= 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
		else if (route[i] == 'U')
		{
			x -= 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
	}
}


void dfs(int x, int y, int step, int book[31][51], int* min1, int q, char* route, char* result, int k[4][2], char maze[ROW][COL])//x:指该位置处于第x行，y:指该位置处于第y列，step指花的步数
{
	int i;
	//递归终止条件
	if (x == ENDROW && y ==ENDCOL )
	{
		//因为是按照下左右上的顺序搜索，所以如果后面找到的路径步数跟当前result的步数一样，还是优先选择当前result的路径
		//所以这里没判断相等的情况，相等时默认还是用当前result的路径
		//printf("到达终止条件\n");
		//printf("step为%d\n", step);
		if (step < *min1)
		{
			strcpy_s(result, strlen(route)+1, route);//更新最小步数的路径
			printf("进行了dfs路径规划,dfs路径长度为%d\n",step);

			*min1 = step;//更新最小步数
			//printf("路径为%s,步数为%d\n",route,step);
			return;
		}
		else
			return;
	}
	//搜索过程:按照下左右上的顺序进行搜索
	for (i = 0; i < 4; i++)
	{
		int tx = x + k[i][0];
		int ty = y + k[i][1];
		//如果当前行列未超出迷宫范围，并且该位置也标记未走过，并且该位置也不是障碍物，则说明这个位置可以走，进行递归
		if (tx >= 0 && tx <= ROW && ty >= 0 && ty <= COL && book[tx][ty] == 0 && (maze[tx][ty] == 'p' || maze[tx][ty] == 'c'))
		{
			//printf("已到达%d行%d列\n",tx,ty);
		  //添加路径信息
			switch (i)
			{
				//向下
			case 0:
				route[q++] = 'D';
				//printf("%s\n", route);
				break;
				//向左
			case 1:
				route[q++] = 'L';
				//printf("%s\n", route);
				break;
				//向右
			case 2:
				route[q++] = 'R';
				//printf("%s\n", route);
				break;
				//向上
			case 3:
				route[q++] = 'U';
				//printf("%s\n", route);
			}
			//增加步数
			step++;
			//标记已走过
			book[tx][ty] = 1;
			//递归
			dfs(tx, ty, step,book, min1, q, route, result, k, maze);
			//回溯
			route[q] = '\0';
			q--;
			step--;
			book[tx][ty] = 0;
		}
	}
	return;
}
void dfsMark(char maze[ROW][COL],int x,int y, int mazeStartX, int mazeStartY)
{
	int i;
	int book[31][51] = { 0 };//标记位置是否走过
	int min1 = 999;//记录已找到的路径的最小步数
	int q = 0;//标记route数组末尾，用于添加路径信息
	char route[2000] = { '\0' };//记录递归过程中的路径
	char result[2000] = { '\0' };//记录最终路径
	int k[4][2] = {
		{1,0},//向下
		{0,-1},//向左
		{0,1},//向右
		{-1,0}//向上
	};
	//printf("dfs之前\n");
	book[x][y] = 1;
	dfs(x, y, 0,book,&min1,q,route,result,k,maze);
	//printf("result为:%s\n", result);
	//printf("dfs之后\n");
	for (i = 0; i < strlen(result); i++)
	{
		if (result[i] == 'D')
		{
			x += 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y,mazeStartX,mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
		else if (result[i] == 'R')
		{
			y += 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			//mazeStartX对应宽度，所以与y相加，mazeStartY对应长度，所以与x相加
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
		else if (result[i] == 'L')
		{
			y -= 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
		else if (result[i] == 'U')
		{
			x -= 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d行%d列,mazeStartX为:%d,mazeStartY为:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
	}
}