#pragma once
#include <string>
#include <regex>
#include <vector>
#include <iostream>

using namespace std;

enum CellChildSide {
	LEFT,
	RIGHT
};


struct Tree
{
	struct TreeCell
	{
		char value;
		TreeCell* leftCell;
		TreeCell* rightCell;
		TreeCell* parentCell;
		CellChildSide childSide;

		TreeCell(char value)
		{
			this->value = value;
			leftCell = nullptr;
			rightCell = nullptr;
			parentCell = nullptr;
			childSide = LEFT;
		}
	};

	TreeCell* root;

	//Конструктор дерева выражения
	Tree(string expression)
	{
		root = createTree(expression);
	}


	//Создание дерева.
	TreeCell* createTree(string expression)
	{
		TreeCell* currentCell = nullptr;
		//Проверка на пустую строку.
		if (expression.length() == 0)
		{
			return currentCell;
		}

		//Поиск оператора.
		int operatorIndex = findOperator(expression);

		//Если оператор не найден, то создаем лист.
		if (operatorIndex == -1)
		{
			currentCell = new TreeCell(expression[0]);
			return currentCell;
		}

		//Создаем корень.
		currentCell = new TreeCell(expression[operatorIndex]);

		//Создаем левое поддерево.
		currentCell->leftCell = createTree(expression.substr(0, operatorIndex));
		currentCell->leftCell->parentCell = currentCell;
		currentCell->leftCell->childSide = LEFT;

		//Создаем правое поддерево.
		currentCell->rightCell = createTree(expression.substr(operatorIndex + 1, expression.length() - operatorIndex - 1));
		currentCell->rightCell->parentCell = currentCell;
		currentCell->rightCell->childSide = RIGHT;

		return currentCell;
	}

	//Поиск оператора.
	int findOperator(string expression)
	{
		int operatorIndex = -1;
		int bracketCounter = 0;
		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] == '(')
			{
				bracketCounter++;
			}
			else if (expression[i] == ')')
			{
				bracketCounter--;
			}
			else if (bracketCounter == 0 && (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'))
			{
				operatorIndex = i;
				break;
			}
		}
		return operatorIndex;
	}

	//Вывод дерева выражения
	void printTree()
	{
		printTree(root);
	}


	//Вывод дерева
	void printTree(TreeCell* cell)
	{
		if (cell == nullptr)
		{
			return;
		}
		if (cell->leftCell != nullptr)
		{
			printTree(cell->leftCell);
		}
		cout << cell->value << " ";
		if (cell->rightCell != nullptr)
		{
			printTree(cell->rightCell);
		}
	}


};



//struct TreeCell
//{
//	TreeCell* leftCell = nullptr;
//	TreeCell* rightCell = nullptr;
//	char value;
//
//	TreeCell(char value)
//	{
//		this->value = value;
//	}
//};


//struct Tree
//{
//	TreeCell* root;
//
//	Tree(std::string expression)
//	{
//		std::string operands = "";
//		std::string operators = "";
//		for (int i = 0; i < expression.length(); i++)
//		{
//			if (expression[i] >= 48 && expression[i] <= 57)
//			{
//				operands += expression[i];
//				continue;
//			}
//			operators += expression[i];
//		}
//		root = new TreeCell(operators[operators.length() - 1]);
//		operators.erase(operators.length() - 1, 1);
//		TreeCell* currentCell;
//		for (auto o : operators)
//		{
//			currentCell = root;
//			while (currentCell->leftCell != nullptr
//				|| currentCell->rightCell != nullptr)
//			{
//				if (currentCell->leftCell != nullptr)
//				{
//					currentCell = currentCell->rightCell;
//					continue;
//				}
//				currentCell = currentCell->leftCell;
//			}
//			if (currentCell->leftCell == nullptr)
//			{
//				addCell(currentCell, LEFT, o);
//			}
//			else
//			{
//				addCell(currentCell, RIGHT, o);
//			}
//		}
//		for (auto o : operands)
//		{
//			currentCell = root;
//			while (currentCell->leftCell != nullptr
//				&& currentCell->rightCell != nullptr)
//			{
//				if (currentCell->leftCell != nullptr)
//				{
//					currentCell = currentCell->rightCell;
//					continue;
//				}
//				currentCell = currentCell->leftCell;
//			}
//			if (currentCell->leftCell == nullptr)
//			{
//				addCell(currentCell, LEFT, o);
//			}
//			else
//			{
//				addCell(currentCell, RIGHT, o);
//			}
//		}
//	}
//
//	void addCell(TreeCell* parent, CellChildSide side, char value)
//	{
//		if (side == LEFT)
//		{
//			parent->leftCell = new TreeCell(value);
//			return;
//		}
//		parent->rightCell = new TreeCell(value);
//	}
//	
//};