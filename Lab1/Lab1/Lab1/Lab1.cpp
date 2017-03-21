// Lab1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <string>
#include <locale>

using namespace std;


void reading_file()
{
	setlocale(LC_ALL, "RUS");
	string s;
	ifstream reading;
	reading.open("students.txt");
	//�������� � ������ �����
	if (reading.is_open())
	{
		while (getline(reading, s)) 
		{ // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
			SetConsoleCP(1251); //��������� ������ ������� ���� 
			SetConsoleOutputCP(1251); //����� ������� ����
			cout << s << endl; // ������� �� ����� students.txt
		}
	}
	else cout << "Unable to open file"; //������� �� ����� �������� � ��������� �����
	reading.close(); 
}

void copy_file()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin;
	fin.open("students.txt");
	ofstream fout;
	fout.open("rating.txt");
	char ch;
	// ����������� ������ �� students.txt � rating.txt
	while (!fin.eof())
	{
		SetConsoleCP(1251); //��������� ������ ������� ���� 
		SetConsoleOutputCP(1251); //����� ������� ����
		fin.get(ch);
		fout << ch;
	}
	fin.close();
}

void working_file()
{
	ifstream working;
	working.open("rating.txt");
	string str;
	int x, y, z, h, k, count = 0, i = 0, tmp;
	if (working.is_open())
	{
		while (getline(working, str))
		{
			while (str[i] != ' ')
			{
				count++; i++;
			}
			x = chislo(&str[0], count);
			count = 0; ++i;
			while (str[i]) 
			{
				++count; ++i;
			}
			y = chislo(&str[i - count], count);
			count = 0; i = 0;
			cout << x << " " << y << "\n";
		}
	}
	else cout << "Unable to open file";
}

int chislo(char *tmp, int razr) {
	int temp, chislo_ = 0, dec = 10, i = 0;
	temp = pow(dec, razr);
	while (temp != 1) {
		chislo_ = chislo_ + (tmp[i] - '0') * temp;
		temp /= dec; ++i;
	}
	return chislo_ / dec;
}

int main()
{
	setlocale(0, "rus");
	int d[100];
	reading_file();
	copy_file();
	working_file();
	system("pause");
    return 0;
}

