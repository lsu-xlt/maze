
#include <iostream>
#include <vector>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include <time.h>
#include"initMaze.h"
 using namespace std;
#define BORDER 'w'  // �Թ��߽����ַ�'w'��ʾ

 // ��ʼ���Թ���������λ������Ϊǽ
 void initializeMaze(char maze[ROWS][COLS]) {
	 for (int i = 0; i < ROWS; i++) {
		 for (int j = 0; j < COLS; j++) {
			 maze[i][j] = 'w';
		 }
	 }
 }


 // ��������Ƿ�����Ч��Χ��
 bool isValid(int x, int y) {
	 return x >= 0 && x < ROWS && y >= 0 && y < COLS;
 }

 // ʹ������������������Թ�·��
 void generateMaze(char maze[ROWS][COLS], int x, int y, int targetX, int targetY) {
	 // �����ĸ������ϡ��¡�����
	 int dx[] = { -1, 1, 0, 0 };
	 int dy[] = { 0, 0, -1, 1 };

	 // ������ҷ�������
	 for (int i = 0; i < 4; i++) {
		 int r = rand() % 4;
		 int temp = dx[i];
		 dx[i] = dx[r];
		 dx[r] = temp;

		 temp = dy[i];
		 dy[i] = dy[r];
		 dy[r] = temp;
	 }

	 // ����ÿ������
	 for (int i = 0; i < 4; i++) {
		 int nx = x + 2 * dx[i];
		 int ny = y + 2 * dy[i];

		 // �����λ���Ƿ�����Ч��Χ������ǽ
		 if (isValid(nx, ny) && maze[nx][ny] == 'w') {
			 // ���м�λ�ú���λ������Ϊͨ��
			 maze[x + dx[i]][y + dy[i]] = 'p';
			 maze[nx][ny] = 'p';

			 if (nx == targetX && ny == targetY) {
				 // ����ﵽĿ��λ�ã�����������ִ���������
				 // ���磬���·������������
			 }
			 else {
				 generateMaze(maze, nx, ny, targetX, targetY);
			 }
		 }
	 }
 }

 // ���Թ�ת��Ϊ�����飬��ӱ߽�
 void convertToNewArray(char maze[ROWS][COLS], char newArray[ROWS + 2][COLS + 2]) {
	 for (int i = 0; i < ROWS; i++) {
		 for (int j = 0; j < COLS; j++) {
			 newArray[i + 1][j + 1] = maze[i][j];
		 }
	 }

	 // ��ӱ߽�
	 for (int i = 0; i < ROWS + 2; i++) {
		 for (int j = 0; j < COLS + 2; j++) {
			 if (i == 0 || j == 0 || i == ROWS + 1 || j == COLS + 1) {
				 newArray[i][j] = 'w';
			 }
		 }
	 }
	 // ������ʼ���Ŀ���
	 newArray[1][0] = 'p';
	 newArray[19][24] = 'p';
 }

 void getMaze(char maze[ROWS][COLS], char newArray[ROWS + 2][COLS + 2]) {


	 // ��ʼ�������������
	 srand(time(NULL));

	 // ��ʼ���Թ���������λ������Ϊǽ
	 initializeMaze(maze);

	 // ����ʼ������Ϊǽ
	 maze[0][0] = 'w';

	 // ���ѡ����ʼ��
	 int startX = rand() % (ROWS / 2) * 2;
	 int startY = rand() % (COLS / 2) * 2;

	 // ʹ������������������Թ�·��
	 generateMaze(maze, startX, startY, 19, 23);

	 // ���Թ�ת��Ϊ�����飬��ӱ߽�
	 convertToNewArray(maze, newArray);

	 return;
 }

































//bfsѰ���Թ�ͨ·
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
	q[0].dir = 'p';//��ھ��������λ�ã���p��ʾ�������
	tail++;
	while (!(q[head].x == ENDROW && q[head].y == ENDCOL) && head<tail)
	{
		//���£��м�1���в���
		if (q[head].x + 1 < ROW && book[q[head].x + 1][q[head].y] == 0 && (maze[q[head].x + 1][q[head].y] == 'p' || maze[q[head].x + 1][q[head].y]=='c'))
		{
			//���
			q[tail].pre = head;//��ס���׵�λ��
			q[tail].x = q[head].x + 1;
			q[tail].y = q[head].y;
			q[tail].dir = 'D';
			book[q[head].x + 1][q[head].y] = 1;
			tail++;
		}
		//�����в��䣬�м�1
		if (q[head].y - 1 >= 0 && book[q[head].x][q[head].y - 1] == 0 && (maze[q[head].x][q[head].y - 1] == 'p' || maze[q[head].x][q[head].y - 1] == 'c'))
		{
			//���
			q[tail].pre = head;//��ס���׵�λ��
			q[tail].x = q[head].x;
			q[tail].y = q[head].y - 1;
			q[tail].dir = 'L';
			book[q[head].x][q[head].y - 1] = 1;
			tail++;
		}

		//���ң��в��䣬�м�1
		if (q[head].y + 1 < COL && book[q[head].x][q[head].y + 1] == 0 && (maze[q[head].x][q[head].y + 1] == 'p' || maze[q[head].x][q[head].y + 1] == 'c'))
		{
			//���
			q[tail].pre = head;//��ס���׵�λ��
			q[tail].x = q[head].x;
			q[tail].y = q[head].y + 1;
			q[tail].dir = 'R';
			book[q[head].x][q[head].y + 1] = 1;
			tail++;
		}
		//����: �м�1���в���
		if (q[head].x - 1 >= 0 && book[q[head].x - 1][q[head].y] == 0 && (maze[q[head].x - 1][q[head].y] == 'p' || maze[q[head].x - 1][q[head].y]=='c'))
		{
			//���
			q[tail].pre = head;//��ס���׵�λ��
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
	printf("������bfs·���滮��bfs·������Ϊ%d\n", len);
	return route;
}

//ͨ��bfs�õ���·�����Ե�·���б�ǡ�routeΪ·����Ϣ��x,yΪ��ǰ���λ����Ϣ
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
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
		else if (route[i] == 'R')
		{
			y += 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			//mazeStartX��Ӧ��ȣ�������y��ӣ�mazeStartY��Ӧ���ȣ�������x���
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
		else if (route[i] == 'L')
		{
			y -= 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
		else if (route[i] == 'U')
		{
			x -= 1;
			setfillcolor(RGB(255, 255, 192));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			
		}
	}
}


void dfs(int x, int y, int step, int book[31][51], int* min1, int q, char* route, char* result, int k[4][2], char maze[ROW][COL])//x:ָ��λ�ô��ڵ�x�У�y:ָ��λ�ô��ڵ�y�У�stepָ���Ĳ���
{
	int i;
	//�ݹ���ֹ����
	if (x == ENDROW && y ==ENDCOL )
	{
		//��Ϊ�ǰ����������ϵ�˳��������������������ҵ���·����������ǰresult�Ĳ���һ������������ѡ��ǰresult��·��
		//��������û�ж���ȵ���������ʱĬ�ϻ����õ�ǰresult��·��
		//printf("������ֹ����\n");
		//printf("stepΪ%d\n", step);
		if (step < *min1)
		{
			strcpy_s(result, strlen(route)+1, route);//������С������·��
			printf("������dfs·���滮,dfs·������Ϊ%d\n",step);

			*min1 = step;//������С����
			//printf("·��Ϊ%s,����Ϊ%d\n",route,step);
			return;
		}
		else
			return;
	}
	//��������:�����������ϵ�˳���������
	for (i = 0; i < 4; i++)
	{
		int tx = x + k[i][0];
		int ty = y + k[i][1];
		//�����ǰ����δ�����Թ���Χ�����Ҹ�λ��Ҳ���δ�߹������Ҹ�λ��Ҳ�����ϰ����˵�����λ�ÿ����ߣ����еݹ�
		if (tx >= 0 && tx <= ROW && ty >= 0 && ty <= COL && book[tx][ty] == 0 && (maze[tx][ty] == 'p' || maze[tx][ty] == 'c'))
		{
			//printf("�ѵ���%d��%d��\n",tx,ty);
		  //���·����Ϣ
			switch (i)
			{
				//����
			case 0:
				route[q++] = 'D';
				//printf("%s\n", route);
				break;
				//����
			case 1:
				route[q++] = 'L';
				//printf("%s\n", route);
				break;
				//����
			case 2:
				route[q++] = 'R';
				//printf("%s\n", route);
				break;
				//����
			case 3:
				route[q++] = 'U';
				//printf("%s\n", route);
			}
			//���Ӳ���
			step++;
			//������߹�
			book[tx][ty] = 1;
			//�ݹ�
			dfs(tx, ty, step,book, min1, q, route, result, k, maze);
			//����
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
	int book[31][51] = { 0 };//���λ���Ƿ��߹�
	int min1 = 999;//��¼���ҵ���·������С����
	int q = 0;//���route����ĩβ���������·����Ϣ
	char route[2000] = { '\0' };//��¼�ݹ�����е�·��
	char result[2000] = { '\0' };//��¼����·��
	int k[4][2] = {
		{1,0},//����
		{0,-1},//����
		{0,1},//����
		{-1,0}//����
	};
	//printf("dfs֮ǰ\n");
	book[x][y] = 1;
	dfs(x, y, 0,book,&min1,q,route,result,k,maze);
	//printf("resultΪ:%s\n", result);
	//printf("dfs֮��\n");
	for (i = 0; i < strlen(result); i++)
	{
		if (result[i] == 'D')
		{
			x += 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y,mazeStartX,mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
		else if (result[i] == 'R')
		{
			y += 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			//mazeStartX��Ӧ��ȣ�������y��ӣ�mazeStartY��Ӧ���ȣ�������x���
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
		else if (result[i] == 'L')
		{
			y -= 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
		else if (result[i] == 'U')
		{
			x -= 1;
			setfillcolor(RGB(135, 206, 250));
			setlinecolor(WHITE);
			//printf("%d��%d��,mazeStartXΪ:%d,mazeStartYΪ:%d\n", x, y, mazeStartX, mazeStartY);
			fillrectangle(mazeStartX + y * 20, mazeStartY + x * 20, mazeStartX + (y + 1) * 20, mazeStartY + (x + 1) * 20);
			FlushBatchDraw();
		}
	}
}