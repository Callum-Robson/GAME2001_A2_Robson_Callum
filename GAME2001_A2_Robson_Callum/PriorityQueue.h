#pragma once
#include "LinkList.h"
#include <iostream>

template<class T>
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
	
		LinkNode<T>* Front()
		{
			return m_elements.Begin();
		}
	
		void push(T data, int priority)//LinkNode<T> newNode)
		{
			// If the number of elements in queue is less than the maximum size (m_size)
			assert(m_elements.GetSize() < m_size);
			// If the number of elements in queue is 0
			if (m_elements.GetSize() == 0)
			{
				// Insert new node before iterator's current node
				// Create Iterator
				LinkIterator<T> it;
				m_elements.InsertBefore(it, data, priority);
				// Set iterator to beginning of queue
				it.m_node = m_elements.m_root;
				
			}
			else
			{
				// Create Iterator
				LinkIterator<T> it;
				// Set iterator to beginning of queue
				it = m_elements.Begin();
				// While Iterator exists
				while (it.isValid())
				{
					// If new node's priority # is lower than iterator node's priority
					if (priority < it.m_node->m_priority)
					{
						// jump out of while loop
						break;
					}
					if ((priority > it.m_node->m_priority) && (it.m_node->m_next == NULL))
					{
						m_elements.Insert_After(it, data, priority);
					}
					// Move iterator to next node
					it++;
				}
	
				// If iterator is still valid
				if (it.isValid())
				{
					if (priority < it.m_node->m_priority)
					{
						// Add new node before iterator node
						m_elements.InsertBefore(it, data, priority);
					}
				}
	
			}
		}
	
		int GetSize() { return m_elements.GetSize(); }
		int GetMaxSize() { return m_size; }
		bool isEmpty() { reurn(m_elements.GetSize() == 0); }
		void Resize(int size) { assert(size > 0); m_size = size; }
	
	private:
		LinkList<T> m_elements;
		int m_size;
	
		
};