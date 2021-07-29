#include <assert.h>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

int main()
{
	BinarySearchTree<int> tree;
	std::vector<int> abc;

	abc = tree.TraverseInOrder(tree.GetRootNode().lock());
	
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(3));
	tree.Insert(std::make_unique<int>(2));

	tree.Delete(5);

	abc = tree.TraverseInOrder(tree.GetRootNode().lock());

}