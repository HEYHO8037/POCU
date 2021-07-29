#include <assert.h>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

int main()
{
	BinarySearchTree<int> tree;

	for (int length = 1; length < 31; length++)
	{
		tree.Insert(std::make_unique<int>(length));
	}

	for (int length = 1; length < 31; length++)
	{
		tree.Delete(length);
	}
	
	tree.Insert(std::make_unique<int>(3));
	tree.Insert(std::make_unique<int>(1));
	tree.Insert(std::make_unique<int>(7));
	tree.Insert(std::make_unique<int>(10));

	tree.Delete(5);

}