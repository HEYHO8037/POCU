#include <assert.h>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

int main()
{
    bool bDelete = false;
    bool bSearch = false;
    BinarySearchTree<int> tree;
    std::vector<int> traverseResult;

    bDelete = tree.Delete(15);
    bSearch = tree.Search(15);
    traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
    assert(!bDelete);
    assert(!bSearch);
    assert(traverseResult.empty());

    tree.Insert(std::make_unique<int>(15));
    traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
    bDelete = tree.Delete(15);
    assert(bDelete);
    assert(traverseResult.size() == 1);
    assert(traverseResult[0] == 15);

}