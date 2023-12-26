#include<graphics.h>
#include<conio.h>
#include<stdio.H>
#include<Windows.h>
bool Quit(int step)
{
	HWND hwnd = GetHWnd();
	// 使用 sprintf 将整数值格式化为字符串
	TCHAR message[256]; // 假设消息不会超过256个字符
	_stprintf_s(message, _T("您是否要再玩一次，已走了%d步"), step);
	return (MessageBox(hwnd, message, _T("询问"), MB_YESNO) == IDYES);
}
bool Replace()
{
	HWND hwnd = GetHWnd();
	return (MessageBox(hwnd, _T("您确认要更换迷宫吗？"), _T("询问"), MB_YESNO) == IDYES);
}
