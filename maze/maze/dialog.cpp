#include<graphics.h>
#include<conio.h>
#include<stdio.H>
#include<Windows.h>
bool Quit(int step)
{
	HWND hwnd = GetHWnd();
	// ʹ�� sprintf ������ֵ��ʽ��Ϊ�ַ���
	TCHAR message[256]; // ������Ϣ���ᳬ��256���ַ�
	_stprintf_s(message, _T("���Ƿ�Ҫ����һ�Σ�������%d��"), step);
	return (MessageBox(hwnd, message, _T("ѯ��"), MB_YESNO) == IDYES);
}
bool Replace()
{
	HWND hwnd = GetHWnd();
	return (MessageBox(hwnd, _T("��ȷ��Ҫ�����Թ���"), _T("ѯ��"), MB_YESNO) == IDYES);
}
