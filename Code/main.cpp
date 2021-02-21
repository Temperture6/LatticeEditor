#include <iostream>
#include <conio.h>
#include <vector>
#include "BetterPrint.h"
#include "function.h"
using namespace std;

int x = 1, y = 1;
int lattice[8][8];

void operate(int key);
void change();

int main()
{
	system("title 8*8����ͼ�α༭��");
	GetLatticeName();
	//��ӡ����ͼ��
	SetFontColor(8);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			MoveCursor(j * 2, i);
			printf("��");
		}
	}
	SetFontColor(15);
	MoveCursor(2, 1);
	while (true)
	{
		operate(_getch());
	}
}

void operate(int key)
{
	switch (key)
	{
	case 72:
		//��
		if (y <= 1)
			y = 8;
		else
			y--;
		MoveCursor(x * 2, y);
		break;
	case 80:
		//��
		if (y >= 8)
			y = 1;
		else
			y++;
		MoveCursor(x * 2, y);
		break;
	case 75:
		//��
		if (x <= 1)
			x = 8;
		else
			x--;
		MoveCursor(x * 2, y);
		break;
	case 77:
		//��
		if (x >= 8)
			x = 1;
		else
			x++;
		MoveCursor(x * 2, y);
		break;
	case 13:
		//�س�����״̬
		change();
		break;
	case 99:
	case 67:
	{
		//����
		vector <int> lattrange = { 0, 0 };
		lattrange = getrange();
		//savefile(lattrange[0], lattrange[1]); //��ʽ1����������浽һ���ļ���
		Copy(lattrange[0], lattrange[1]); //��ʽ2����������Ƶ�������
		break;
	}
	default:
		break;
	}
}

void change()
{

	if (lattice[y - 1][x - 1] == 0) //��Ϊ��ɫ
	{
		SetFontColor(12); //����ɫ
		MoveCursor(x * 2, y);
		cout << "��";
		MoveCursor(x * 2, y);
		lattice[y - 1][x - 1] = 1;
	}
	else if (lattice[y - 1][x - 1] == 1 ) //��Ϊ��ɫ
	{
		SetFontColor(8); //��ɫ
		MoveCursor(x * 2, y);
		cout << "��";
		MoveCursor(x * 2, y);
		lattice[y - 1][x - 1] = 0;
	}
}