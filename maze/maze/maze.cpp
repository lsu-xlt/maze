#include<graphics.h>//123456
#include<conio.h>//第五次修改
#include<stdio.H>
#include<windows.h>
#include <iostream>//修改
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#include <thread>
#include"initMaze.h"
#include"mazeDecoration.h"
#include"dialog.h"
#pragma comment( lib, "MSIMG32.LIB")//使用 TransparentBlt 函数,用于实现透明贴图
; struct Player {
	int i;
	int j;
};
char maze[ROWS][COLS];
char newArray[ROWS + 2][COLS + 2];  // 新数组，包含边界
int mazeStartX;
int mazeStartY;
int step = 0;
Player player;
IMAGE playerMove[6];
int flag = 0;//判断角色朝向
//char** newArray = getMaze();
int crossNum = 5;//穿墙道具个数
int playerCross = 0;//角色穿墙机会的次数
int t;
int b[25][25] = { 0 };
int min1;
int BGM = 0;//背景音乐序列
int Gflag = 0;//标记是否触发了切换背景音乐
void startup()
{
	int i, j;
	initgraph(640, 640);//初始化图形窗口，设置窗口大小为640x640
	// 设置透明背景模式
	setbkmode(WHITE);
	setbkcolor(WHITE);
	BeginBatchDraw();// 开始批量绘制，这是一种优化绘图的方式，减少图形闪烁
	// 获取窗口的尺寸
	int windowWidth = getwidth();
	int windowHeight = getheight();
	// 获取屏幕宽度和高度
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	// 计算窗口左上角坐标，使得窗口在屏幕正中央
	int left = (screenWidth - windowWidth) / 2;
	int top = (screenHeight - windowHeight) / 2;
	// 使用 SetWindowPos 将窗口移动到屏幕中央
	SetWindowPos(GetHWnd(), HWND_TOP, left, top, windowWidth, windowHeight, SWP_SHOWWINDOW);
	//GetHWnd() : 这个函数用于获取当前图形窗口的句柄（handle）。句柄是一个用于标识窗口的唯一标识符，通过它可以对窗口进行操作。
	//HWND_TOP : 这是设置窗口 Z 顺序的参数。在这里，HWND_TOP 表示将窗口置于 Z 顺序的顶部，即将其放在其他窗口的上面。
	//left : 窗口左上角的 X 坐标。
	//top : 窗口左上角的 Y 坐标。
	//windowWidth : 窗口的宽度。
	//windowHeight : 窗口的高度。
	//SWP_SHOWWINDOW : 这是设置窗口位置和大小时的操作标志。在这里，SWP_SHOWWINDOW 表示在设置窗口的位置和大小后显示窗口。如果没有这个标志，窗口可能会被设置为新的位置和大小，但是仍然保持隐藏状态。
	// 计算迷宫的起始位置
	mazeStartX = (windowWidth - 25 * 20) / 2;  // 居中放置迷宫
	mazeStartY = (windowHeight - 25 * 20) / 2;
	for (i = 0; i < 25; i++)
		for (j = 0; j < 25; j++)
			if (newArray[i][j] == 'm')
			{//找到玩家，将坐标赋值给全局变量player
				player.i = i;
				player.j = j;
				newArray[i][j] = 'p';//所有在show()的时候,'m'已经变成了'p'
			}
}
//音效
void bgm1() {
	// 打开音乐
	mciSendString(_T("open ../resource/music/bgm2.mp3 alias mymusic"), NULL, 0, NULL);
	// 播放音乐
	mciSendString(_T("play mymusic"), NULL, 0, NULL);
	Sleep(100);
	// 停止播放并关闭音乐
	mciSendString(_T("stop mymusic"), NULL, 0, NULL);
	mciSendString(_T("close mymusic"), NULL, 0, NULL);
}

void update()
{
	if ((GetAsyncKeyState('A') & 0x8001) == 0x8001 && ((newArray[player.i][player.j - 1] == 'p' || newArray[player.i][player.j - 1] == 'c') || (newArray[player.i][player.j-1] == 'w' && playerCross != 0)))//用于检查按键是否在上一次调用时是弹起状态而在当前调用时是按下状态，以执行相应的操作
	{
		bgm1();
		if (newArray[player.i][player.j - 1] == 'c')
		{
			playerCross++;
		}
		if (newArray[player.i][player.j - 1] == 'w')
		{
			playerCross--;
		}
		printf("向左移动\n");
		player.j--;
		step++;
		flag = 1;
	}
	else if ((GetAsyncKeyState('D') & 0x8001) == 0x8001 && ((newArray[player.i][player.j + 1] == 'p' || newArray[player.i][player.j + 1] == 'c') || (newArray[player.i][player.j+1] == 'w' && playerCross != 0)))
	{
		bgm1();
		if (newArray[player.i][player.j + 1] == 'c')
		{
			playerCross++;
		}
		if (newArray[player.i][player.j + 1] == 'w')
		{
			playerCross--;
		}
		player.j++;
		printf("向右移动\n");
		step++;
		flag = 0;
	}
	else if ((GetAsyncKeyState('W') & 0x8001) == 0x8001 && ((newArray[player.i-1][player.j] == 'p' || newArray[player.i-1][player.j] == 'c') || (newArray[player.i-1][player.j] == 'w' && playerCross != 0)))
	{
		bgm1();
		if (newArray[player.i-1][player.j] == 'c')
		{
			playerCross++;
		}
		if (newArray[player.i-1][player.j] == 'w')
		{
			playerCross--;
		}
		printf("向上移动\n");
		player.i--;
		step++;
	}
	else if ((GetAsyncKeyState('S') & 0x8001) == 0x8001 && ((newArray[player.i+1][player.j] == 'p' || newArray[player.i+1][player.j] == 'c') || (newArray[player.i + 1][player.j] == 'w' && playerCross!=0)))
	{
		bgm1();
		if (newArray[player.i+1][player.j] == 'c')
		{
			playerCross++;
		}
		if (newArray[player.i+1][player.j] == 'w')
		{
			playerCross--;
		}
		printf("向下移动\n");
		player.i++;
		step++;
	}
	if ((GetAsyncKeyState('J') & 0x8001))
	{
		 // 记录开始时间
		clock_t start_time = clock();
		bfsMark(bfs(newArray,player.i,player.j), player.i, player.j, mazeStartX, mazeStartY);
		// 记录结束时间
		clock_t end_time = clock();
		// 计算执行时间（单位：毫秒）
		double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
		// 打印执行时间
		printf("函数执行时间: %.2f 毫秒\n", execution_time);
		FlushBatchDraw();
		
	}
	if ((GetAsyncKeyState('K') & 0x8001))
	{
		//printf("进来了");
		 // 记录开始时间
		clock_t start_time = clock();
		dfsMark(newArray,player.i, player.j, mazeStartX, mazeStartY);
		// 记录结束时间
		clock_t end_time = clock();
		// 计算执行时间（单位：毫秒）
		double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
		// 打印执行时间
		printf("函数执行时间: %.2f 毫秒\n", execution_time);
		FlushBatchDraw();
	}
	if ((GetAsyncKeyState('T') & 0x8001))
	{
		if (Replace())
		{
			int b[25][25] = { 0 };
			int t;
			player.i = 1;
			player.j = 0;
			step = 0;
			getMaze(maze, newArray);
			printf("			迷宫正在加载，请稍后。。。\n");
			t = crossNum;
			while (t != 0)
			{
				// 初始化随机数生成器
				srand(time(NULL));
				int ti = rand() % 24 + 1;
				int tj = rand() % 24 + 1;
				if (newArray[ti][tj] == 'p' && b[ti][tj] == 0)
				{
					b[ti][tj] = 1;
					newArray[ti][tj] = 'c';
					t--;
				}
			}
			printf("	[");
			for (int i = 1; i <= 50; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			printf("			    加载完成!\n");
			Sleep(1000);
		}
	}
	if (newArray[player.i][player.j] == 'c')
	{
		newArray[player.i][player.j] = 'p';
	}
}
void playBackgroundMusic(const wchar_t* musicPath) {
	mciSendStringW(L"close music", NULL, 0, NULL); // 关闭当前正在播放的音乐（如果有）

	wchar_t command[256];
	wsprintfW(command, L"open \"%s\" alias music", musicPath);
	mciSendStringW(command, NULL, 0, NULL); // 打开指定路径的音乐文件
	mciSendStringW(L"play music repeat", NULL, 0, NULL); // 循环播放音乐
}
//背景音乐
void bgm() {
	const wchar_t* musicFilePath = L"../resource/music/bgmx.mp3"; 
	playBackgroundMusic(musicFilePath);

	while (1) {
		if ((GetAsyncKeyState('G') & 0x8001))
		{
			BGM++;
			if (BGM > 1)
				BGM = 0;
			Gflag = 1;
		}
		if (Gflag == 1)
		{
			printf("切换音乐,音乐序号是%d\n", BGM);
			Gflag = 0;
			switch (BGM)
			{
			case 0:
				musicFilePath = L"../resource/music/bgmx.mp3";
				playBackgroundMusic(musicFilePath);
				break;
			case 1:
				musicFilePath = L"../resource/music/bgmy.mp3";
				playBackgroundMusic(musicFilePath);
				break;
			case 2:
				musicFilePath = L"../resource/music/bgm3.mp3";
				playBackgroundMusic(musicFilePath);
				break;
			case 3:
				musicFilePath = L"../resource/music/bgm4.mp3";
				playBackgroundMusic(musicFilePath);
				break;
			case 4:
				musicFilePath = L"../resource/music/bgm5.mp3";
				playBackgroundMusic(musicFilePath);
				break;
			}
		}
		Sleep(1000); // 每秒检查一次条件
	}
}

void gameLoop() {
	while (1)
	{
		show(mazeStartX, mazeStartY, player.i, player.j, newArray, flag);
		update();
		if (player.i == 19 && player.j == 24)

		{
			if (!Quit(step))
			{
				exit(0);
			}
			else
			{
				player.i = 1;
				player.j = 0;
				step = 0;
				getMaze(maze, newArray);
				int i, j;
				printf("			迷宫正在加载，请稍后。。。\n");
				for (i = 0; i < 25; i++)
				{
					for (j = 0; j < 25; j++)
					{
						b[i][j] = 0;
					}
				}
				t = crossNum;
				while (t != 0)
				{
					// 初始化随机数生成器
					srand(time(NULL));
					int ti = rand() % 24 + 1;
					int tj = rand() % 24 + 1;
					if (newArray[ti][tj] == 'p' && b[ti][tj] == 0)
					{
						b[ti][tj] = 1;
						newArray[ti][tj] = 'c';
						t--;
					}
				}
				printf("	[");
				for (int i = 1; i <= 50; i++)
				{
					printf("=");
					Sleep(10);
				}
				printf("]\n");
				printf("			    加载完成!\n");
				Sleep(1000);
			}

		}
	}
}
int main()
{
	getMaze(maze, newArray);
	t = crossNum;
	printf("			迷宫正在加载，请稍后。。。\n");
	
	while (t != 0)
	{
		// 初始化随机数生成器
		srand(time(NULL));
		int ti = rand() % 24+1;
		int tj = rand() % 24+1;
		if (newArray[ti][tj] == 'p' && b[ti][tj] == 0)
		{
			b[ti][tj] = 1;
			newArray[ti][tj] = 'c';
			t--;
		}
	}
	printf("	[");
	for (int i = 1; i <= 50; i++)
	{
		printf("=");
		Sleep(10);
	}
	printf("]\n");
	printf("			    加载完成!\n");
	Sleep(1000);
	player.i = 1;
	player.j = 0;
	startup();
	std::thread musicThread(bgm); // 开启音乐播放的线程
	std::thread gameThread(gameLoop); // 开启游戏逻辑的线程

	musicThread.join(); // 等待音乐播放线程结束
	gameThread.join(); // 等待游戏逻辑线程结束
	return 0;
}
