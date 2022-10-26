#pragma once

#include <string>
#include <vector>

using namespace std;

struct Tree
{
	struct Node
	{
		Node* leftCell = nullptr;
		Node* rightCell = nullptr;
		char value;

		Node(char value)
		{
			this->value = value;
		}
	};

	Node* root;

	Tree() 
	{
		root = nullptr;
	}

	Tree(std::string expression)
	{
		vector<int> operatorIndexes = findOperatorIndexes(expression);

		int centerOperatorIndex = operatorIndexes.size() / 2;

		root = new Node(expression[operatorIndexes[centerOperatorIndex]]);

		//Создание левого поддерева
		string leftExpression = expression.substr(0, operatorIndexes[centerOperatorIndex]);
		root->leftCell = createTree(leftExpression);

		//Создание правого поддерева
		string rightExpression = expression.substr(operatorIndexes[centerOperatorIndex] + 1);
		root->rightCell = createTree(rightExpression);
	}

	Node* createTree(string expression)
	{
		vector<int> operatorIndexes = findOperatorIndexes(expression);

		int centerOperatorIndex = operatorIndexes.size() / 2;

		Node* node = nullptr;

		if (operatorIndexes.size() != 0)
		{
			node = new Node(expression[operatorIndexes[centerOperatorIndex]]);

			string leftExpression = expression.substr(0, operatorIndexes[centerOperatorIndex]);
			node->leftCell = createTree(leftExpression);

			string rightExpression = expression.substr(operatorIndexes[centerOperatorIndex] + 1);
			node->rightCell = createTree(rightExpression);
		}
		else
		{
			node = new Node(expression[centerOperatorIndex]);
		}
		
		return node;
	}


	vector<int> findOperatorIndexes(string expression)
	{
		vector<int> operatorIndexes;
		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			{
				operatorIndexes.push_back(i);
			}
		}
		return operatorIndexes;
	}
};