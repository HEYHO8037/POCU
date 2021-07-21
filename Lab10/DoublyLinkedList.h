#pragma once
#include "Node.h"

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> mNode;
		unsigned int mCount = 0;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{

		std::shared_ptr<Node<T>> saveNode = mNode;
		std::shared_ptr<Node<T>> savePrevious;

		if (mCount == 0)
		{
			mNode = std::make_shared<Node<T>>(std::move(data));
			mCount++;
		}
		else
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				savePrevious = saveNode;
				saveNode = saveNode->Next;
			}

			saveNode = std::make_shared<Node<T>>(std::move(data), savePrevious);
			savePrevious->Next = saveNode;
			mCount++;
		}
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		
		std::shared_ptr<Node<T>> saveNode = mNode;

		if (index >= mCount)
		{
			Insert(std::move(data));
		}
		else
		{
			std::shared_ptr<Node<T>> findNode = std::make_shared<Node<T>>(std::move(data));

			for (unsigned int length = 0; length < (index-1); length++)
			{
				saveNode = saveNode->Next;
			}

			findNode->Next = saveNode->Next;
			saveNode->Next->Previous = findNode;
			saveNode->Next = findNode;
			findNode->Previous = saveNode;

			mCount++;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> saveNode = mNode;
		unsigned int findCount = 0;
		std::shared_ptr<Node<T>> findNode;
		bool bAlive = false;

		while (saveNode != nullptr)
		{
			if (*saveNode->Data == data)
			{
				bAlive = true;
				break;
			}
			else
			{
				saveNode = saveNode->Next;
				findCount++;
			}
		}

		saveNode = mNode;

		if (bAlive == true)
		{
			for (unsigned int length = 0; length < findCount; length++)
			{
				saveNode = saveNode->Next;
			}

			findNode = saveNode->Previous.lock();

			saveNode->Previous.lock()->Next = saveNode->Next;
			saveNode->Next->Previous.lock() = saveNode->Previous.lock();
			saveNode.reset();
			mCount--;

			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		bool bAlive = false;
		std::shared_ptr<Node<T>> findNode = mNode;

		while (findNode != nullptr)
		{
			if (*findNode->Data == data)
			{
				bAlive = true;
				break;
			}
			else
			{
				findNode = findNode->Next;
			}
		}

 		if (bAlive == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		std::shared_ptr<Node<T>> findNode = mNode;

		if (mCount <= index)
		{
			return nullptr;
		}
		else
		{
			for (unsigned int length = 0; length < index; length++)
			{
				findNode = findNode->Next;
			}

			return findNode;
		}
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mCount;;
	}
}