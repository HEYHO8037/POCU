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
		static void Inorder(const std::shared_ptr<TreeNode<T>> node);
		std::shared_ptr<TreeNode<T>> mTreeNode = nullptr;
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
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> saveTreeNode = mTreeNode;
		std::shared_ptr<TreeNode<T>> saveLeftRightNode;

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
			else
			{
				saveTreeNode = saveTreeNode->Right;

				if (saveTreeNode == nullptr)
				{
					return false;
				}
			}
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

			if (saveTreeNode->Parent.lock()->Left == saveTreeNode)
			{
				saveTreeNode = saveTreeNode->Parent.lock();
				saveTreeNode->Left = saveLeftRightNode;
			}
			else
			{
				saveTreeNode = saveTreeNode->Parent.lock();
				saveTreeNode->Right = saveLeftRightNode;
			}
		}
		else
		{
			saveLeftRightNode = saveTreeNode;

			if (saveTreeNode->Right != nullptr)
			{
				saveTreeNode = saveTreeNode->Right;
			}

			while (saveTreeNode->Left != nullptr)
			{
				saveTreeNode = saveTreeNode->Left;

				if (saveTreeNode->Left == nullptr)
				{
					break;
				}
			}

			if (saveTreeNode->Parent.lock()->Left == saveTreeNode)
			{
				saveTreeNode->Parent.lock()->Left = nullptr;
			}
			if (saveTreeNode->Parent.lock()->Right == saveTreeNode)
			{
				saveTreeNode->Parent.lock()->Right = nullptr;
			}


			if (saveLeftRightNode->Parent.lock()->Left == saveLeftRightNode)
			{
				saveLeftRightNode->Parent.lock()->Left = saveTreeNode;
			}
			if (saveLeftRightNode->Parent.lock()->Right == saveLeftRightNode)
			{
				saveLeftRightNode->Parent.lock()->Right = saveTreeNode;
			}

			if (saveLeftRightNode->Left->Parent.lock() == saveLeftRightNode)
			{
				saveLeftRightNode->Left->Parent = saveTreeNode;
			}
			if (saveLeftRightNode->Right->Parent.lock() == saveLeftRightNode)
			{
				saveLeftRightNode->Right->Parent = saveTreeNode;
			}

			saveTreeNode->Parent = saveLeftRightNode->Parent;
			saveTreeNode->Left = saveLeftRightNode->Left;
			saveTreeNode->Right = saveLeftRightNode->Right;
			
			if (saveLeftRightNode->Left != nullptr)
			{
				saveLeftRightNode->Left->Parent.lock() = saveTreeNode;
			}
			if (saveLeftRightNode->Right != nullptr)
			{
				saveLeftRightNode->Right->Parent.lock() = saveTreeNode;
			}
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