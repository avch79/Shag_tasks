/*
*********************************************************************************
*  Описать структуру Student(фамилия, группа, успеваемость (массив из 5 int)).  *
*  Создать массив студентов и написать программу, позволяющую:                  *
*  - динамически изменять размер массива;                                       *
*  - выводить список отличников(>75% отл оценок);                               *
*  - выводить список двоечников(>50%  оценок 2 и 3);                            *
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
	cout << "№\t" << "Фамилия\t\t" << "Группа\t\t" << "Успеваемость" << endl;
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
	masstud[0] = { 1, "Иванов", "ГР-1", 5,5,5,5,4 };
	masstud[1] = { 2, "Петров", "ГР-1", 5,3,3,4,3 };
	masstud[2] = { 3, "Сидоров", "ГР-2", 2,3,2,2,4 };

	while (true)
	{
		cout << "1. Показать список студентов" << endl;
		cout << "2. Добавить запись в список" << endl;
		cout << "3. Удалить запись из списка" << endl;
		cout << "4. Вывести список отличников" << endl;
		cout << "5. Вывести список двоечников" << endl;
		cout << "6. Выход" << endl;
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
			cout << "Номер: ";
			cin >> masstud[n].number;
			cout << "Фамилия: ";
			cin.get();
			cin.getline(masstud[n].surname, 50);
			cout << "Группа: ";
			cin.getline(masstud[n].group, 10);
			cout << "Оценки: ";
			for (int i = 0; i < 5; i++)
			{
				cin >> masstud[n].achievement[i];
			}
			n++;
		}
		if (menu == 3)
		{
			cout << "Введите фамилию студента" << endl;
			char surname[50];
			cin.get();
			cin.getline(surname, 50);
			for (int i = 0; i < n; i++)
			{
				if (strcmp(surname, masstud[i].surname) == 0)
				{
					cout << "Будет удалена запись:" << endl;
					showitem(masstud[i]);
					cout << "Вы уверены??? (Y/N)" << endl;
					char y;
					cin >> y;
					if (y == 'Y' || y == 'y')
					{
						swap(masstud[i], masstud[n - 1]);
						n--;
						cout << "Запись успешно удалена!" << endl;
					}
				}
			}
		}
		if (menu == 4)
		{
			cout << "Отличники:" << endl;
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
			cout << "Двоечники:" << endl;
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