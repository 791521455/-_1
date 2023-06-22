#include <iostream>
#include <stdlib.h>
#include<windows.h>
#include <ctime>
 
using namespace std;

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

bool SetSize(int width, int height)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ������
	SMALL_RECT wrt = { 0, 0, width - 1, height - 1 }; //���ÿ��
	bool ret = SetConsoleWindowInfo(hOutput, TRUE, &wrt); // ���ô���ߴ�
	if (!ret) return false;
	COORD coord = { width, height };
	ret = SetConsoleScreenBufferSize(hOutput, coord); // ���û���ߴ�
	return ret;
}

void cmd_ctrl() {
	HWND hWnd = GetConsoleWindow(); //��ȡ���ھ��
	LONG_PTR sty = GetWindowLongPtrA(hWnd, GWL_STYLE); //��ȡ������ʽ
	sty = sty & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX; //ȥ���ɱ仯��С,���,��С����ť,~��ȡ��,&����,����λ������ص�֪ʶ��
	SetWindowLongPtrA(hWnd, GWL_STYLE, sty); //���ô��岻�ɸ��Ĵ�С,�������
}
 
 void SetFont(int size = 30) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //���������С
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //�����ϸ FW_BOLD
	//wcscpy_s(cfi.FaceName, L"����");  //�������壬�����ǿ���̨���е�
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//��õ�ǰ����
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFO consoleCurrentFont;
	//GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}
 
void time_1()
{
   // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);
   
   // �� now ת��Ϊ�ַ�����ʽ
   char* dt = ctime(&now);
 
   cout <</* "�������ں�ʱ�䣺" <<*/ dt << endl;
 
   // �� now ת��Ϊ tm �ṹ
  // tm *gmtm = gmtime(&now);
   //dt = asctime(gmtm);
  // cout << "UTC ���ں�ʱ�䣺"<< dt << endl;
}

int main(){
	SetConsoleTitleA("ʱ��鿴��");
	SetSize(25, 3);
	HideCursor();
	cmd_ctrl();
	SetFont(50);
	while(1){
		system("cls");
		time_1();
		Sleep(1000);
	}
	return 0;
}




