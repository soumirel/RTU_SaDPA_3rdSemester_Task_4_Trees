
#include <locale.h>
#include <iostream>
#include "Tree.h"


using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	//Переменные для пользовательского выбора.
	int userMenuChoice = -1;
	Tree* tree;

	//Переменные для работы программы


	// Главный меню-цикл.
	while (userMenuChoice != 7)
	{
		std::system("cls");
		cout << "Практическая работа #3 ИКБО-03-21 Мазанов А.Е. Вариант 15\n\n"
			"Задание - Хэш-таблицы.\n"
			"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";

		cout << "Введите [0], чтобы вывести расшифрованное дерево"
			"\nВведите [], чтобы закончить работу программы."
			"\nВаш выбор: ";
		cin >> userMenuChoice;
		cin.ignore();
		switch (userMenuChoice)
		{
		case 0:
			tree = new Tree("1*2-3");
			tree->printTree();
			break;

		case 7:
			cout << "\nДо свидания!\n";
			break;

		default:
			cout << "\nЯ не понимаю вас.\n";
			cin.clear();
			break;
		}
		std::system("pause");
	}
}