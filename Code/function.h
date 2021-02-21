#pragma once
#pragma warning(disable : 4996)
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

extern int lattice[8][8];
char filename[20];

BOOL ClipBoard(char* srcString)
{
	BOOL bResult = FALSE;
	DWORD dwLength = strlen(srcString);
	HANDLE hGlobalMemory = GlobalAlloc(GHND, dwLength + 1); // �����ڴ�
	LPBYTE lpGlobalMemory = (LPBYTE)GlobalLock(hGlobalMemory); // �����ڴ�
	if (NULL != lpGlobalMemory)
	{
		strcpy((char*)lpGlobalMemory, srcString);
		::GlobalUnlock(hGlobalMemory); // �����ڴ�����
		::OpenClipboard(NULL); // �򿪼�����
		::EmptyClipboard(); // ��ռ�����
		::SetClipboardData(CF_TEXT, hGlobalMemory); // ���ڴ��е����ݷ��õ�������
		::CloseClipboard();

		bResult = TRUE;
	}
	return bResult;
}

void GetLatticeName()
{
	char name[20];
	char emptyname[20];

	fstream namefile;
	namefile.open("name.txt", ios::in);
	if (!namefile)
		strcat_s(filename, "lattice"); //���ļ������ڣ�ʹ��Ĭ������
	else
	{
		namefile >> name;
		if (strcmp(name, emptyname) > 0)
			strcpy_s(filename, name);
		else
			strcpy_s(filename, "lattice");
	}
}

vector <int> getrange()
{
	int rx = -1, ry = -1;
	vector <int> result = { 0, 0 };
	
	//ȷ��y�᷶Χ
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (lattice[i][j] == 1)
			{
				ry = i;
				break;
			}
		}
		if (ry != -1)
			break;
	}

	//ȷ��x�᷶Χ
	for (int k = 7; k >= 0; k--)
	{
		for (int l = 0; l <= 7; l++)
		{
			if (lattice[l][k] == 1)
			{
				rx = k;
				break;
			}
		}
		if (rx != -1)
			break;
	}
	result[0] = rx;
	result[1] = ry;
	return result;
}

void savefile(int rx, int ry)
{
	system("title ���ڱ���...");
	ofstream file;
	file.open(filename);

	file << "char lattice[]={" << char(rx + 49) << "," << char(ry + 49) << ",B";

	for (int x = 0; x <= rx; x++)
	{
		for (int y = ry; y >= 0; y--)
		{
			file << char(lattice[y][x] + 48);
		}
		if (x == rx)
			break;
		file << ",B";
	}
	file << "};";

	file.close();
	system("title �������");
	Sleep(500);
	system("title 8*8����ͼ�α༭��");
}

void Copy(int rx, int ry)
{
	system("title ���ڴ���...");
	char lattstr[110] = "char ";// = "char lattice[]={";
	strcat_s(lattstr, filename);
	strcat_s(lattstr, "[]={");
	vector <char> remainvec;
	remainvec.push_back(char(rx + 49));
	remainvec.push_back(',');
	remainvec.push_back(char(ry + 49));
	remainvec.push_back(',');
	remainvec.push_back('B');

	for (int x = 0; x <= rx; x++)
	{
		for (int y = ry; y >= 0; y--)
		{
			remainvec.push_back(char(lattice[y][x] + 48));
		}
		if (x == rx)
			break;
		remainvec.push_back(',');
		remainvec.push_back('B');
	}

	remainvec.push_back('}');
	remainvec.push_back(';');
	remainvec.push_back('\0');

	char remain[100];
	for (unsigned int n = 0; n < remainvec.size(); n++)
		remain[n] = remainvec[n];
	strcat_s(lattstr, remain);

	if (ClipBoard(lattstr))
		system("title �Ѹ��Ƶ�������");
	else
		system("title ����ʧ��");

	Sleep(500);
	system("title 8*8����ͼ�α༭��");
}
