/*
*********************************************************************************
*  ������� ��������� Student(�������, ������, ������������ (������ �� 5 int)).  *
*  ������� ������ ��������� � �������� ���������, �����������:                  *
*  - ����������� �������� ������ �������;                                       *
*  - �������� ������ ����������(>75% ��� ������);                               *
*  - �������� ������ ����������(>50%  ������ 2 � 3);                            *
*********************************************************************************
*/

#include <iostream>
#include <time.h>

using namespace std;

struct student
{
	int number;
	char surname[100];
	char group[10];
	int achievement[5];
};

void showtitle()
{
	cout << "�\t" << "�������\t\t" << "������\t\t" << "������������" << endl;
	cout << "----------------------------------------------------" << endl;
}

void showitem(student n)
{
	cout << n.number << "\t" << n.surname << "\t\t" << n.group << "\t\t";
	for (int i = 0; i < 5; i++)
		cout << n.achievement[i] << " ";
	cout << endl;
}

void main()
{

	system("chcp 1251");
	system("cls");

	int n = 3;
	student *masstud = new student[3];
	masstud[0] = { 1, "������", "��-1", 5,5,5,5,4 };
	masstud[1] = { 2, "������", "��-1", 5,3,3,4,3 };
	masstud[2] = { 3, "�������", "��-2", 2,3,2,2,4 };

	while (true)
	{
		cout << "1. �������� ������ ���������" << endl;
		cout << "2. �������� ������ � ������" << endl;
		cout << "3. ������� ������ �� ������" << endl;
		cout << "4. ������� ������ ����������" << endl;
		cout << "5. ������� ������ ����������" << endl;
		cout << "6. �����" << endl;
		int menu;
		cin >> menu;
		if (menu == 0 || menu > 6)
			menu = 6;
		if (menu == 1)
		{
			cout << endl;
			showtitle();
			for (int i = 0; i < n; i++)
			{
				showitem(masstud[i]);
			}
			cout << endl;
		}
		if (menu == 2)
		{
			cout << "�����: ";
			cin >> masstud[n].number;
			cout << "�������: ";
			cin.get();
			cin.getline(masstud[n].surname, 50);
			cout << "������: ";
			cin.getline(masstud[n].group, 10);
			cout << "������: ";
			for (int i = 0; i < 5; i++)
			{
				cin >> masstud[n].achievement[i];
			}
			n++;
		}
		if (menu == 3)
		{
			cout << "������� ������� ��������" << endl;
			char surname[50];
			cin.get();
			cin.getline(surname, 50);
			for (int i = 0; i < n; i++)
			{
				if (strcmp(surname, masstud[i].surname) == 0)
				{
					cout << "����� ������� ������:" << endl;
					showitem(masstud[i]);
					cout << "�� �������??? (Y/N)" << endl;
					char y;
					cin >> y;
					if (y == 'Y' || y == 'y')
					{
						swap(masstud[i], masstud[n - 1]);
						n--;
						cout << "������ ������� �������!" << endl;
					}
				}
			}
		}
		if (menu == 4)
		{
			cout << "���������:" << endl;
			for (int i = 0; i < n; i++)
			{
				int c = 0;
				for (int j = 0; j < 5; j++)
				{
					if (masstud[i].achievement[j] == 5)
						c++;
				}
				if (c >= 4)
					showitem(masstud[i]);
			}
		}
		if (menu == 5)
		{
			cout << "���������:" << endl;
			for (int i = 0; i < n; i++)
			{
				int c = 0;
				for (int j = 0; j < 5; j++)
				{
					if (masstud[i].achievement[j] == 2 || masstud[i].achievement[j] == 3)
						c++;
				}
				if (c >= 3)
					showitem(masstud[i]);
			}
		}
		if (menu == 6)
			break;
		system("pause");
		system("cls");
	}
}