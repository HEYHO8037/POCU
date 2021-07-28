#include <assert.h>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

int main()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(0));
	tree.Insert(std::make_unique<int>(1));
	tree.Insert(std::make_unique<int>(0));
	tree.Insert(std::make_unique<int>(0));
	tree.Insert(std::make_unique<int>(1));

	tree.Delete(0);
	tree.Delete(0);
	tree.Delete(1);
	tree.Delete(1);
	tree.Delete(0);
}