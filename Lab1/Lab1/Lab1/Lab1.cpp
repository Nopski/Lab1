// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct info
{
	char name[80];
	int subjects_marks;
	bool whois;
};

void reading_file()
{
	setlocale(LC_ALL, "RUS");
	string s;
	ifstream reading;
	reading.open("students.txt");
	//открытие и чтение файла
	if (reading.is_open())
	{
		cout << "Weiting we try to read it...\n";
		Sleep(1000);
		while (getline(reading, s)) 
		{ // пока не достигнут конец файла класть очередную строку в переменную (s)
			SetConsoleCP(1251); //настройка чтения русских букв 
			SetConsoleOutputCP(1251); //вывод русских букв
			cout << s << endl; // выводим на экран students.txt
		}
	}
	else cout << "Unable to open file"; //выводит на экран проблему с открытием файла
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
	// копирование данных из students.txt в rating.txt
	while (!fin.eof())
	{
		SetConsoleCP(1251); //настройка чтения русских букв 
		SetConsoleOutputCP(1251); //вывод русских букв
		fin.get(ch);
		fout << ch;
	}
	fin.close();
}

void working_file()
{
	ifstream working;
	working.open("rating.txt", ios_base::in);
	string str;
	char temp[100][100]; //временній char'овский массив для обработки данных
	int i, j, k, count = 0, tmp;
	if (working.is_open())
	{
		do
		{
			// пробуем считать число
			if (working >> k)
			{
				// если считали число - выводим
				cout << k << endl;
			}
			else
			{
				// если считали не число, очищаем ошибки
				working.clear();
				// пропускаем символы до следующего пробела
				working.ignore(1, ' ');
			}
		} while (!working.eof());
	}
	else EXIT_FAILURE;

	/*if (working.is_open())
	{
		while (working >> k)
		{
			k = atof(str.c_str());
			cout << k << endl;
		}
		working.getline(temp, 40);
		k = atoi(temp);
		for (i = 0; i < k; i++)
		{

		}
	}
	else cout << "Unable to open file";*/

	working.close();
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

