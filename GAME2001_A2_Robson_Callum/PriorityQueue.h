#pragma once
#include "LinkList.h"

template<class t>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}

	void Pop()
	{
		m_elements.PopFront();
	}

	T& Front()
	{
		m_elements.Begin()
	}

	int GetSize() { return m_elements.GetSize(); }
	int GetMaxSize() { return m_size; }
	bool isEmpty() { reurn(m_elements.GetSize() == 0); }
	void Resize(int size) { assert(size > 0); m_size = size; }

private:
	LinkList<T> m_elements;
	int m_size;

	void push(T newNode)
	{
		assert(m_elements.GetSize() < m_size);
		if (m_elements.GetSize() == 0)
		{
			m_elements.InsertBefore(newNode);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			while (it.isValid())
			{
				if (newNode.m_priority < it->m_node->m_priority);
				{
					break
				}
				it++;
			}

			if (it.isValid())
			{
				m_elements.insertBefore(it, newNode);
			}
		}
	}
};