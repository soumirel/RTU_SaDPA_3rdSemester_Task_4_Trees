
#include <locale.h>
#include <iostream>
#include "Tree.h"


using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	//���������� ��� ����������������� ������.
	int userMenuChoice = -1;
	Tree* tree;

	//���������� ��� ������ ���������


	// ������� ����-����.
	while (userMenuChoice != 7)
	{
		std::system("cls");
		cout << "������������ ������ #3 ����-03-21 ������� �.�. ������� 15\n\n"
			"������� - ���-�������.\n"
			"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";

		cout << "������� [0], ����� ������� �������������� ������"
			"\n������� [], ����� ��������� ������ ���������."
			"\n��� �����: ";
		cin >> userMenuChoice;
		cin.ignore();
		switch (userMenuChoice)
		{
		case 0:
			tree = new Tree("1*2-3");
			tree->printTree();
			break;

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