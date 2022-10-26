#pragma once

#include "Tree.h"

using namespace std;

int calculateValue(Tree::Node* node);

//Посчитать значение в левом поддереве
int calculateLeftValue(Tree::Node* node)
{
	if (node->leftCell != nullptr)
	{
		if (node->leftCell->leftCell == nullptr && node->leftCell->rightCell == nullptr)
		{
			return node->leftCell->value - '0';
		}
		else
		{
			return calculateValue(node->leftCell);
		}
	}
	else
	{
		return 0;
	}
}

//Посчитать значение в правом поддереве
int calculateRightValue(Tree::Node* node)
{
	if (node->rightCell != nullptr)
	{
		if (node->rightCell->leftCell == nullptr && node->rightCell->rightCell == nullptr)
		{
			return node->rightCell->value - '0';
		}
		else
		{
			return calculateValue(node->rightCell);
		}
	}
	else
	{
		return 0;
	}
}


int calculateValue(Tree::Node* node)
{
	int leftValue = calculateLeftValue(node);
	int rightValue = calculateRightValue(node);

	switch (node->value)
	{
	case '+':
		return leftValue + rightValue;
	case '-':
		return leftValue - rightValue;
	case '*':
		return leftValue * rightValue;
	case '/':
		return leftValue / rightValue;
	}
}


int calculateTreeExpression(Tree::Node* node)
{
	return calculateValue(node);
}