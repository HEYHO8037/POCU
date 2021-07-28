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
		unsigned int mCount;
	};

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
		if (treeNode == nullptr)
		{
			return nullptr;
		}

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

		for (unsigned int length = 0; length < mCount; length++)
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

		if (mCount == 1 && saveTreeNode == mTreeNode)
		{
			mTreeNode.reset();
			mCount = 0;
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
				saveLeftRightNode->Parent = saveTreeNode;
				mTreeNode = saveLeftRightNode;
			}
		}
		else if(saveTreeNode->Left != nullptr && saveTreeNode->Right != nullptr)
		{
			saveLeftRightNode = SearchMinNode(saveTreeNode->Right);
			saveTreeNode->Data = std::move(saveLeftRightNode->Data);
			NonSearchDelete(saveLeftRightNode);
		}

		mCount--;
		return true;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode = startNode;
		std::shared_ptr<TreeNode<T>> saveRightTreeNode;
		std::vector<T> saveVector;

		if (startNode == nullptr)
		{
			return saveVector;
		}

		while (saveTreeNode->Right != nullptr)
		{
			saveTreeNode = saveTreeNode->Right;
		}

		saveRightTreeNode = saveTreeNode;

		saveTreeNode = startNode;

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
				if (saveTreeNode->Parent.lock()->Right == saveTreeNode)
				{
					saveTreeNode = saveTreeNode->Parent.lock();
				}

				if (saveTreeNode->Parent.lock() != nullptr)
				{
					saveTreeNode = saveTreeNode->Parent.lock();
				}
			}
		}

		saveVector.push_back(*saveTreeNode->Data);

		if (saveTreeNode->Right != nullptr)
		{
			saveTreeNode = saveTreeNode->Right;

			while (saveTreeNode->Left != nullptr)
			{
				saveTreeNode = saveTreeNode->Left;
			}

			while (true)
			{
				saveVector.push_back(*saveTreeNode->Data);

				if (saveRightTreeNode == saveTreeNode)
				{
					break;
				}
				else
				{
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
			}
		}

		return saveVector;
	}

}