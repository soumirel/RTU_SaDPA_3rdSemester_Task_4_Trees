
#include <locale.h>
#include "Tree.h"
#include "TreePrinter.h"
#include "TreeFunctions.h"

using namespace std;

enum MenuState
{
	INIT = 0,
	EXIT = 7
};

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	//Переменные для пользовательского выбора.
	int userMenuChoice = -1;
	Tree* tree = new Tree();

	//Переменные для работы программы


	// Главный меню-цикл.
	while (userMenuChoice != 7)
	{
		std::system("cls");
		cout << "Практическая работа #4 ИКБО-03-21 Мазанов А.Е. Вариант 15\n\n"
			"Задание - Деревья.\n"
			"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";

		cout << "Введите [0], чтобы вывести расшифрованное дерево"
			"\nВведите [], чтобы закончить работу программы."
			"\nВаш выбор: ";
		cin >> userMenuChoice;
		cin.ignore();
		switch (userMenuChoice)
		{
		case 0:
		{
			tree = new Tree("1+2+3+4");
			TreePrinter printer(tree);
			printer.printExpression();
			printer.printTree();
			int leftSum = calculateLeftValue(tree->root);
			int rightSum = calculateRightValue(tree->root);
			cout << "Результат в левом поддереве: " << leftSum << '\n';
			cout << "Результат в правом поддереве: " << rightSum << '\n';
			cout << "Корень дерева: " << tree->root->value << '\n';
			cout << "Результат дерева: " << calculateTreeExpression(tree->root) << '\n';
			break;
		}

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