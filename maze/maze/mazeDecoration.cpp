#include<graphics.h>
#include<conio.h>
#include<stdio.H>
#include<windows.h>
#include <time.h>
#include"mazeDecoration.h"

void show(int mazeStartX, int mazeStartY, int playerI, int playerJ, char map[25][25],int flag)
{
	//printf("1111111\n");
	cleardevice();
	int i, j;
	//绘制玩家图像
	IMAGE img;  // 定义 IMAGE 结构体用于存储图片信息
	for (i = 0; i < 25; i++)

	{

		for (j = 0; j < 25; j++)

		{

			if (map[i][j] == 'w')//墙壁

			{
				//printf("墙壁\n");
				setfillcolor(RGB(136, 87, 57));

				setlinecolor(RGB(136, 87, 57));

				fillrectangle(mazeStartX + j * 20, mazeStartY + i * 20, mazeStartX + (j + 1) * 20, mazeStartY + (i + 1) * 20);

				//这四个坐标决定了矩 形的位置和大小

			}
			

			else if (map[i][j] == 'p')//通路

			{
				//printf("通路\n");
				setfillcolor(RGB(63, 63, 63));

				setlinecolor(RGB(63, 63, 63));

				fillrectangle(mazeStartX + j * 20, mazeStartY + i * 20, mazeStartX + (j + 1) * 20, mazeStartY + (i + 1) * 20);

			}
			else if (map[i][j] == 'c')//穿墙道具方块

			{
				IMAGE imgDoor;
				loadimage(&imgDoor, _T("../resource/images/door1.png"));
				TransparentBlt(GetImageHDC(NULL), mazeStartX + j * 20, mazeStartY + i * 20, 20, 20, GetImageHDC(&imgDoor), 0, 0, 20, 20, BLACK);
				//printf("渲染了穿墙方块\n");
				//setfillcolor(RED);

				//setlinecolor(WHITE);

				//fillrectangle(mazeStartX + j * 20, mazeStartY + i * 20, mazeStartX + (j + 1) * 20, mazeStartY + (i + 1) * 20);

			}

			 if (i==19 && j==24)//终点

			{

				setfillcolor(YELLOW);

				setlinecolor(YELLOW);

				fillrectangle(mazeStartX + j * 20, mazeStartY + i * 20, mazeStartX + (j + 1) * 20, mazeStartY + (i + 1) * 20);

			}
			  if (map[playerI][playerJ] == 'w')
			 {
				 //printf("玩家正在穿墙\n");
				 IMAGE imgDoor;
				 loadimage(&imgDoor, _T("../resource/images/door2.png"));
				 TransparentBlt(GetImageHDC(NULL), mazeStartX + playerJ * 20, mazeStartY + playerI * 20, 20, 20, GetImageHDC(&imgDoor), 0, 0, 20, 20, BLACK);
			 }
			  if (playerI == 19 && playerJ == 24)
			  {
				  setbkmode(TRANSPARENT);//显示透明文字
				  settextcolor(WHITE);//设置字体颜色

				  settextstyle(50, 0, _T("宋体"));//设置字体大小，字体

				  outtextxy(300, 300, _T("游戏胜利"));//输出字体
			}

		}

	}

	// 绘制迷宫外围背景
	setfillcolor(RGB(31, 153, 131)); // 设置绿色色背景
	solidrectangle(0, 0, getwidth(), mazeStartY); // 顶部背景
	solidrectangle(0, mazeStartY + 25 * 20, getwidth(), getheight()); // 底部背景
	solidrectangle(0, mazeStartY, mazeStartX, mazeStartY + 25 * 20); // 左侧背景
	solidrectangle(mazeStartX + 25 * 20, mazeStartY, getwidth(), mazeStartY + 25 * 20); // 右侧背景
	// 加载要显示的图片——终点
	IMAGE img1;
	loadimage(&img1, _T("../resource/images/A5.png"));

	// 获取图片的长宽
	int width1 = img1.getwidth();
	int height1 = img1.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 550, 450, width1, height1, GetImageHDC(&img1), 0, 0, width1, height1, BLACK);

	// 加载要显示的图片——车4
	IMAGE img2;
	loadimage(&img2, _T("../resource/images/7.png"));

	// 获取图片的长宽
	int width2 = img2.getwidth();
	int height2 = img2.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 575, 300, width2, height2, GetImageHDC(&img2), 0, 0, width2, height2, BLACK);

	// 加载要显示的图片——椰树
	IMAGE img3;
	loadimage(&img3, _T("../resource/images/A1.png"));

	// 获取图片的长宽
	int width3 = img3.getwidth();
	int height3 = img3.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）

	TransparentBlt(GetImageHDC(NULL), 190, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 210, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 230, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 250, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 330, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 350, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 390, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 410, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 490, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 510, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 530, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);
	TransparentBlt(GetImageHDC(NULL), 550, 550, width3, height3, GetImageHDC(&img3), 0, 0, width3, height3, BLACK);

	// 加载要显示的图片——椅子
	IMAGE img4;
	loadimage(&img4, _T("../resource/images/A4.png"));

	// 获取图片的长宽
	int width4 = img4.getwidth();
	int height4 = img4.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 300, 570, width4, height4, GetImageHDC(&img4), 0, 0, width4, height4, BLACK);
	TransparentBlt(GetImageHDC(NULL), 440, 570, width4, height4, GetImageHDC(&img4), 0, 0, width4, height4, BLACK);


	// 加载要显示的图片——车1
	IMAGE img5;
	loadimage(&img5, _T("../resource/images/12.png"));

	// 获取图片的长宽
	int width5 = img5.getwidth();
	int height5 = img5.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 575, 260, width5, height5, GetImageHDC(&img5), 0, 0, width5, height5, BLACK);

	// 加载要显示的图片——车2
	IMAGE img6;
	loadimage(&img6, _T("../resource/images/A7.png"));

	// 获取图片的长宽
	int width6 = img6.getwidth();
	int height6 = img6.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 575, 380, width6, height6, GetImageHDC(&img6), 0, 0, width6, height6, BLACK);
	// 加载要显示的图片——车3
	IMAGE img7;
	loadimage(&img7, _T("../resource/images/10.png"));

	// 获取图片的长宽
	int width7 = img7.getwidth();
	int height7 = img7.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 575, 340, width7, height7, GetImageHDC(&img7), 0, 0, width7, height7, BLACK);

	// 加载要显示的图片——垃圾桶
	IMAGE img8;
	loadimage(&img8, _T("../resource/images/A2.png"));

	// 获取图片的长宽
	int width8 = img8.getwidth();
	int height8 = img8.getheight();


	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 380, 590, width8, height8, GetImageHDC(&img8), 0, 0, width8, height8, BLACK);

	// 加载要显示的图片——起点1
	IMAGE img9;
	loadimage(&img9, _T("../resource/images/A15.png"));

	// 获取图片的长宽
	int width9 = img9.getwidth();
	int height9 = img9.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), -50, -5, width9, height9, GetImageHDC(&img9), 0, 0, width9, height9, BLACK);

	// 加载要显示的图片——终点1
	IMAGE img10;
	loadimage(&img10, _T("../resource/images/A12.png"));

	// 获取图片的长宽
	int width10 = img10.getwidth();
	int height10 = img10.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 590, 440, width10, height10, GetImageHDC(&img10), 0, 0, width10, height10, BLACK);

	// 加载要显示的图片——路灯1
	IMAGE img11;
	loadimage(&img11, _T("../resource/images/L1.png"));

	// 获取图片的长宽
	int width11 = img11.getwidth();
	int height11 = img11.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 475, 550, width11, height11, GetImageHDC(&img11), 0, 0, width11, height11, BLACK);

	// 加载要显示的图片——路灯2
	IMAGE img12;
	loadimage(&img12, _T("../resource/images/L2.png"));

	// 获取图片的长宽
	int width12 = img12.getwidth();
	int height12 = img12.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 280, 550, width12, height12, GetImageHDC(&img12), 0, 0, width12, height12, BLACK);


	// 加载要显示的图片——npc1
	IMAGE img13;
	loadimage(&img13, _T("../resource/images/A3.png"));

	// 获取图片的长宽
	int width13 = img13.getwidth();
	int height13 = img13.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 320, 560, width13, height13, GetImageHDC(&img13), 0, 0, width13, height13, BLACK);

	// 加载要显示的图片——npc2
	IMAGE img14;
	loadimage(&img14, _T("../resource/images/A8.png"));

	// 获取图片的长宽
	int width14 = img14.getwidth();
	int height14 = img14.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 460, 560, width14, height14, GetImageHDC(&img14), 0, 0, width14, height14, BLACK);

	// 加载要显示的图片——房子1
	IMAGE img15;
	loadimage(&img15, _T("../resource/images/A16.png"));

	// 获取图片的长宽
	int width15 = img15.getwidth();
	int height15 = img15.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), -10, 480, width15, height15, GetImageHDC(&img15), 0, 0, width15, height15, BLACK);

	// 加载要显示的图片——大量元素
	IMAGE img16;
	loadimage(&img16, _T("../resource/images/A14.png"));

	// 获取图片的长宽
	int width16 = img16.getwidth();
	int height16 = img16.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 70, -64, width16, height16, GetImageHDC(&img16), 0, 0, width16, height16, BLACK);

	// 加载要显示的图片——房子2
	IMAGE img17;
	loadimage(&img17, _T("../resource/images/A17.png"));

	// 获取图片的长宽
	int width17 = img17.getwidth();
	int height17 = img17.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), -30, 400, width17, height17, GetImageHDC(&img17), 0, 0, width17, height17, BLACK);

	// 加载要显示的图片——房子3
	IMAGE img18;
	loadimage(&img18, _T("../resource/images/A18.png"));

	// 获取图片的长宽
	int width18 = img18.getwidth();
	int height18 = img18.getheight();

	// 在指定位置绘制图片（使用TransparentBlt）
	TransparentBlt(GetImageHDC(NULL), 575, 120, width18, height18, GetImageHDC(&img18), 0, 0, width18, height18, BLACK);


	
	// 使用当前时间作为随机数种子
	srand(time(NULL));
	// 生成一个范围在1到6之间的随机数
	int randomNumber = rand() % 6 + 1;
	if (flag == 0) {
		switch (randomNumber)
		{
		case 1:
			loadimage(&img, _T("../resource/images/1.png"));  // 图片路径
			break;
		case 2:
			loadimage(&img, _T("../resource/images/2.png"));  // 图片路径
			break;
		case 3:
			loadimage(&img, _T("../resource/images/3.png"));  // 图片路径
			break;
		case 4:
			loadimage(&img, _T("../resource/images/4.png"));  // 图片路径
			break;
		case 5:
			loadimage(&img, _T("../resource/images/5.png"));  // 图片路径
			break;
		case 6:
			loadimage(&img, _T("../resource/images/6.png"));  // 图片路径
		}
	}
	else
	{
		switch (randomNumber)
		{
		case 1:
			loadimage(&img, _T("../resource/images/1.1.png"));  // 图片路径
			break;
		case 2:
			loadimage(&img, _T("../resource/images/2.1.png"));  // 图片路径
			break;
		case 3:
			loadimage(&img, _T("../resource/images/3.1.png"));  // 图片路径
			break;
		case 4:
			loadimage(&img, _T("../resource/images/4.1.png"));  // 图片路径
			break;
		case 5:
			loadimage(&img, _T("../resource/images/5.1.png"));  // 图片路径
			break;
		case 6:
			loadimage(&img, _T("../resource/images/6.1.png"));  // 图片路径
		}
	}
	i = playerI;
	j = playerJ;
	//Resize(&img, 20, 20);

	// 获取绘图设备的句柄
	HDC hdc = GetImageHDC(NULL);

	// 使用 TransparentBlt 实现透明贴图
	TransparentBlt(hdc, mazeStartX + j * 20, mazeStartY + i * 20, 20, 20, GetImageHDC(&img), 0, 0, 20, 20, BLACK);
	FlushBatchDraw();//用于刷新绘图缓冲区并立即将绘制结果显示到屏幕上
	Sleep(10);
}