
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

	//���������� ��� ����������������� ������.
	int userMenuChoice = -1;
	Tree* tree = new Tree();

	//���������� ��� ������ ���������


	// ������� ����-����.
	while (userMenuChoice != 7)
	{
		std::system("cls");
		cout << "������������ ������ #4 ����-03-21 ������� �.�. ������� 15\n\n"
			"������� - �������.\n"
			"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";

		cout << "������� [0], ����� ������� �������������� ������"
			"\n������� [], ����� ��������� ������ ���������."
			"\n��� �����: ";
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
			cout << "��������� � ����� ���������: " << leftSum << '\n';
			cout << "��������� � ������ ���������: " << rightSum << '\n';
			cout << "������ ������: " << tree->root->value << '\n';
			cout << "��������� ������: " << calculateTreeExpression(tree->root) << '\n';
			break;
		}

		case 7:
			cout << "\n�� ��������!\n";
			break;

		default:
			cout << "\n� �� ������� ���.\n";
			cin.clear();
			break;
		}
		std::system("pause");
	}
}