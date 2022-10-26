#pragma once

#include <iostream>
#include <Windows.h>
#include "Tree.h"

using namespace std;

class TreePrinter
{
private:

	Tree* tree;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	enum Side
	{
		LEFT,
		RIGHT,
		FROM_ROOT
	};

public:

	TreePrinter(Tree* tree)
	{
		this->tree = tree;
		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
		saved_attributes = consoleInfo.wAttributes;
	}

	//Рекурсивный вывод повёрнутого дерева
	void printTree()
	{
		printNode(tree->root, 0);
		cout << '\n';
	}

	void printNode(Tree::Node* node, size_t level, Side cameFrom = FROM_ROOT, size_t changeSidesAmount = 0)
	{
		if (node != nullptr)
		{
			if (cameFrom == LEFT)
			{
				printNode(node->rightCell, level + 1, RIGHT, changeSidesAmount + 1);
			}
			else
			{
				printNode(node->rightCell, level + 1, RIGHT, changeSidesAmount);
			}
			
			cout << '\n';

			for (int i = 0; i < level - 1 - changeSidesAmount && node != tree->root; i++)
			{
				cout << "    ";
			}

			for (int i = 0; i < changeSidesAmount && node != tree->root; i++)
			{
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
				cout << " ";
				SetConsoleTextAttribute(hConsole, saved_attributes);
				cout << "   ";
			}
			if (node != tree->root)
			{
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
				cout << "    ";
			}

			SetConsoleTextAttribute(hConsole, saved_attributes);
			cout << node->value;

			if (cameFrom == RIGHT)
			{
				printNode(node->leftCell, level + 1, LEFT, changeSidesAmount + 1);
			}
			else
			{
				printNode(node->leftCell, level + 1, LEFT, changeSidesAmount);
			}
			
		}
	}

	//Вывод выражения
	void printExpression()
	{
		printExpression(tree->root);
		cout << '\n';
	}

	//Вывод выражения из дерева прямым обходом
	void printExpression(Tree::Node* node)
	{
		if (node->leftCell != nullptr)
		{
			printExpression(node->leftCell);
		}

		if (node->leftCell == nullptr
			&& node->rightCell == nullptr)
		{
			cout << node->value << " ";
			return;
		}

		cout << node->value << " ";

		if (node->rightCell != nullptr)
		{
			printExpression(node->rightCell);
		}
	}
};
