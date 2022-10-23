

//Обход дерева - обратный в глубину.
//void reverseBypass(Tree* tree)
//{
//	if (tree->root == nullptr)
//	{
//		return;
//	}
//	std::vector<Tree::TreeCell*> stack;
//	stack.push_back(tree->root);
//	while (stack.size() > 0)
//	{
//		Tree::TreeCell* currentCell = stack.back();
//		stack.pop_back();
//		if (currentCell->leftCell != nullptr)
//		{
//			stack.push_back(currentCell->leftCell);
//		}
//		if (currentCell->rightCell != nullptr)
//		{
//			stack.push_back(currentCell->rightCell);
//		}
//		std::cout << currentCell->value << " ";
//	}
//}
// 
// 
//void reverseBypass(Tree* tree, TreeCell* cell)
//{
//	if (cell->leftCell != nullptr)
//	{
//		reverseBypass(tree, cell->leftCell);
//	}
//
//	if (cell->leftCell == nullptr
//		&& cell->rightCell == nullptr)
//	{
//		std::cout << cell->value << " ";
//		return;
//	}
//
//	std::cout << tree->root->value << " ";
//
//	if (cell->rightCell != nullptr)
//	{
//		reverseBypass(tree, cell->rightCell);
//	}
//}