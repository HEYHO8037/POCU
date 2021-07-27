#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

int main()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(3));
	tree.Insert(std::make_unique<int>(1));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(6));

	tree.Delete(3);
	tree.Delete(0);
	tree.Delete(1);
	tree.Delete(1);
	tree.Delete(0);
}