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
		std::shared_ptr<TreeNode<T>> mTreeNode = nullptr;
		static unsigned int mCount;
	};

	template<typename T>
	unsigned int BinarySearchTree<T>::mCount = mC;

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode;
		std::shared_ptr<TreeNode<T>> saveParentNode;

		if (mTreeNode == nullptr)
		{
			mTreeNode = std::make_shared<TreeNode<T>>(move(data));
			mCount++;
			return;
		}
		else
		{
			saveTreeNode = mTreeNode;

			for (unsigned int length = 0; length < mCount; length++)
			{
				if (*saveTreeNode->Data >= *data)
				{
					if (saveTreeNode->Left == nullptr)
					{
						saveParentNode = saveTreeNode;
						saveTreeNode->Left = std::make_shared<TreeNode<T>>(move(data));
						saveTreeNode = saveTreeNode->Left;
						saveTreeNode->Parent = saveParentNode;
						mCount++;
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
						mCount++;
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

		for (unsigned int length = 0; length < mCount; length++)
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
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode = startNode;
		std::vector<T> saveVector;

		while (saveTreeNode->Left != nullptr)
		{
			saveTreeNode = saveTreeNode->Left;
		}

		while(saveTreeNode->Parent.lock() != startNode->Parent.lock())
		{
			saveVector.push_back(*saveTreeNode->Data);

			if (saveTreeNode->Right != nullptr)
			{
				saveTreeNode = saveTreeNode->Right;

				if (saveTreeNode->Left != nullptr)
				{
					while (saveTreeNode->Left != nullptr)
					{
						saveTreeNode = saveTreeNode->Left;
					}
				}
			}
			else
			{
				if (saveTreeNode->Parent.lock() != nullptr)
				{
					saveTreeNode = saveTreeNode->Parent.lock();
				}
			}
		}

		saveVector.push_back(*saveTreeNode->Data);
		saveTreeNode = saveTreeNode->Right;

		while (saveTreeNode->Left != nullptr)
		{
			saveTreeNode = saveTreeNode->Left;
		}

		while (mCount != saveVector.size())
		{
			saveVector.push_back(*saveTreeNode->Data);

			if (saveTreeNode->Right != nullptr)
			{
				saveTreeNode = saveTreeNode->Right;

				if (saveTreeNode->Left != nullptr)
				{
					while (saveTreeNode->Left != nullptr)
					{
						saveTreeNode = saveTreeNode->Left;
					}
				}
			}
			else
			{
				if (saveTreeNode->Parent.lock() != nullptr)
				{
					saveTreeNode = saveTreeNode->Parent.lock();
				}
			}
		}

		return saveVector;
	}

}