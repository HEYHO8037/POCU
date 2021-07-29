#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> SearchMinNode(std::shared_ptr<TreeNode<T>> treeNode);
		void NonSearchDelete(std::shared_ptr<TreeNode<T>> treeNode);

		std::shared_ptr<TreeNode<T>> mTreeNode;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode;
		std::shared_ptr<TreeNode<T>> saveParentNode;

		if (mTreeNode == nullptr)
		{
			mTreeNode = std::make_shared<TreeNode<T>>(move(data));
			return;
		}
		else
		{
			saveTreeNode = mTreeNode;

			while (true)
			{
				if (*saveTreeNode->Data >= *data)
				{
					if (saveTreeNode->Left == nullptr)
					{
						saveParentNode = saveTreeNode;
						saveTreeNode->Left = std::make_shared<TreeNode<T>>(move(data));
						saveTreeNode = saveTreeNode->Left;
						saveTreeNode->Parent = saveParentNode;
						return;
					}
					else
					{
						saveTreeNode = saveTreeNode->Left;
					}
				}
				else
				{
					if (saveTreeNode->Right == nullptr)
					{
						saveParentNode = saveTreeNode;
						saveTreeNode->Right = std::make_shared<TreeNode<T>>(move(data));
						saveTreeNode = saveTreeNode->Right;
						saveTreeNode->Parent = saveParentNode;
						return;
					}
					else
					{
						saveTreeNode = saveTreeNode->Right;
					}
				}
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mTreeNode;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode = mTreeNode;

		while (saveTreeNode != nullptr)
		{
			if (*saveTreeNode->Data == data)
			{
				return true;
			}
			else if (*saveTreeNode->Data > data)
			{
				saveTreeNode = saveTreeNode->Left;

			}
			else
			{
				saveTreeNode = saveTreeNode->Right;
			}
		}

		return false;
	}


	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::SearchMinNode(std::shared_ptr<TreeNode<T>> treeNode)
	{
		if (treeNode->Left == nullptr)
		{
			return treeNode;
		}
		else
		{
			return SearchMinNode(treeNode->Left);
		}
	}

	template<typename T>
	void BinarySearchTree<T>::NonSearchDelete(std::shared_ptr<TreeNode<T>> treeNode)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode = treeNode;
		std::shared_ptr<TreeNode<T>> saveLeftRightNode;

		if (saveTreeNode->Left == nullptr && saveTreeNode->Right == nullptr)
		{
			saveLeftRightNode = saveTreeNode;
			saveTreeNode = saveTreeNode->Parent.lock();

			if (saveTreeNode->Left == saveLeftRightNode)
			{
				saveTreeNode->Left.reset();
			}
			else if (saveTreeNode->Right == saveLeftRightNode)
			{
				saveTreeNode->Right.reset();
			}
		}
		else if (saveTreeNode->Left == nullptr || saveTreeNode->Right == nullptr)
		{
			if (saveTreeNode->Left != nullptr)
			{
				saveLeftRightNode = saveTreeNode->Left;
			}
			else
			{
				saveLeftRightNode = saveTreeNode->Right;
			}

			if (saveTreeNode->Parent.lock()->Left == saveTreeNode)
			{
				saveTreeNode = saveTreeNode->Parent.lock();
				saveTreeNode->Left = saveLeftRightNode;
				saveLeftRightNode->Parent = saveTreeNode;
			}
			else
			{
				saveTreeNode = saveTreeNode->Parent.lock();
				saveTreeNode->Right = saveLeftRightNode;
				saveLeftRightNode->Parent = saveTreeNode;
			}
		}
	}


	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode = mTreeNode;
		std::shared_ptr<TreeNode<T>> saveLeftRightNode;

		if (mTreeNode == nullptr)
		{
			return false;
		}

		while(saveTreeNode != nullptr)
		{
			if (*saveTreeNode->Data == data)
			{
				break;
			}
			else if (*saveTreeNode->Data > data)
			{
				saveTreeNode = saveTreeNode->Left;

				if (saveTreeNode == nullptr)
				{
					return false;
				}
			}
			else if(*saveTreeNode->Data < data)
			{
				saveTreeNode = saveTreeNode->Right;

				if (saveTreeNode == nullptr)
				{
					return false;
				}
			}
		}

		if (saveTreeNode == mTreeNode && saveTreeNode->Left == nullptr && saveTreeNode->Right == nullptr)
		{
			mTreeNode.reset();
			return true;
		}


		if (saveTreeNode->Left == nullptr && saveTreeNode->Right == nullptr)
		{
			saveLeftRightNode = saveTreeNode;
			saveTreeNode = saveTreeNode->Parent.lock();

			if(saveTreeNode->Left == saveLeftRightNode)
			{
				saveTreeNode->Left.reset();
			}
			else if (saveTreeNode->Right == saveLeftRightNode)
			{
				saveTreeNode->Right.reset();
			}
		}
		else if (saveTreeNode->Left == nullptr || saveTreeNode->Right == nullptr)
		{
			if (saveTreeNode->Left != nullptr)
			{
				saveLeftRightNode = saveTreeNode->Left;
			}
			else
			{
				saveLeftRightNode = saveTreeNode->Right;
			}


			if (saveTreeNode->Parent.lock() != nullptr)
			{
				if (saveTreeNode->Parent.lock()->Left == saveTreeNode)
				{
					saveTreeNode = saveTreeNode->Parent.lock();
					saveTreeNode->Left = saveLeftRightNode;
					saveLeftRightNode->Parent = saveTreeNode;
				}
				else
				{
					saveTreeNode = saveTreeNode->Parent.lock();
					saveTreeNode->Right = saveLeftRightNode;
					saveLeftRightNode->Parent = saveTreeNode;
				}
			}
			else
			{
				saveLeftRightNode->Parent = saveTreeNode->Parent;
				mTreeNode = saveLeftRightNode;
			}
		}
		else if(saveTreeNode->Left != nullptr && saveTreeNode->Right != nullptr)
		{
			saveLeftRightNode = SearchMinNode(saveTreeNode->Right);
			saveTreeNode->Data = std::move(saveLeftRightNode->Data);
			NonSearchDelete(saveLeftRightNode);
		}

		return true;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> inorderVector;
		
		if (startNode == nullptr)
		{
			return inorderVector;
		}

		if (TraverseInOrder(startNode->Left).size() != 0)
		{
			inorderVector = TraverseInOrder(startNode->Left);
		}

		inorderVector.push_back(*startNode->Data);

		if (TraverseInOrder(startNode->Right).size() != 0)
		{
			inorderVector = TraverseInOrder(startNode->Right);;
		}


		return inorderVector;
	}

}