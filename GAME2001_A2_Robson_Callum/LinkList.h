#pragma once
#include <cassert>
#include <string>

template<class T>
class LinkList;

template<class T>
class LinkIterator;

template<class T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class LinkList<T>;

public:
	LinkNode(T data, int priority)//, LinkNode* nextNode = NULL, LinkNode* previousNode = NULL)
	{
		m_data = data;
		m_priority = priority;
		m_next = NULL;
		m_previous = NULL;
	}

	T getData()
	{
		return m_data;
	}
	int m_priority;

	T m_data;
	LinkNode* m_next;
	LinkNode* m_previous;
};

template<class T>
class LinkIterator
{
public:
	LinkIterator()
	{
		m_node = NULL;
	}
	~LinkIterator()
	{
	}

	void operator=(LinkNode<T>* node)
	{
		m_node = node;
	}

	T& operator*()
	{
		assert(m_node != NULL);
		return m_node->m_data;
	}

	void operator++()
	{
		assert(m_node != NULL);
		m_node = m_node->m_next;
	}

	void operator++(int)
	{
		assert(m_node != NULL);
		m_node = m_node->m_next;
	}

	bool operator!=(LinkNode<T>* node)
	{
		return(m_node != node);
	}

	bool operator==(LinkNode<T>* node)
	{
		return(m_node == node);
	}

	bool isValid()
	{
		return (m_node != NULL);
	}

	LinkNode<T>* m_node;
};

template<class T>
class LinkList
{
public:
	LinkList() : m_size(0), m_root(0), m_lastNode(0)
	{
	}

	~LinkList()
	{
		while (m_root)
		{
			PopFront();
		}
	}

	//Return first node in list;
	LinkNode<T>* Begin()
	{
		assert(m_root != NULL);
		return m_root;
	}

	LinkNode<T>* End()
	{
		return NULL;
	}

	LinkNode<T>* Last()
	{
		return m_lastNode;
	}

	int GetSize()
	{
		return m_size;
	}

	//Pop first node in list
	void PopFront()
	{
		// Root note exists
		assert(m_root != NULL);

		// Create a temporary Node 
		LinkNode<T>* temp = new LinkNode<T>(0, 0);
		// Set node equal to the root node
		temp = m_root;

		// Set root node equal to it's next node pointer
		m_root = m_root->m_next;

		if (m_root != NULL)
		// Set new root node's previous node pointer to null
			m_root->m_previous = NULL;
		
		// delete temporary node
		delete temp;

		// update m_size
		m_size = (m_size == 0 ? m_size : m_size - 1);
		
		// Now the old root node has been removed, and the root has been set to the next node in the queue
	}

	// inserts a node before the node currently pointed to by the iterator passed in, set's the new node's data to what is passed in
	void InsertBefore(LinkIterator<T>& it, T newData, int newPriority)
	{
		if (it.m_node == NULL)
		{
			it.m_node = new LinkNode<T>(newData, newPriority);
			m_root = it.m_node;
			m_size++;
		}
		else if (it.m_node != NULL)
		{
			// create "new node"
			LinkNode<T>* node = new LinkNode<T>(0, 0);
			assert(node != NULL);

			// set "new node"'s data to what is passed in
			node->m_data = newData;
			// set "new node"'s data to what is passed in
			node->m_priority = newPriority;
			// set "new node"'s next node pointer to the iterator's current node
			node->m_next = it.m_node;
			// set the "new node"'s previous node pointer to the iterator's previous node pointer
			node->m_previous = it.m_node->m_previous;

			// if the previous node that was just set is not null, set that node's next node pointer to the "new node"
			if (node->m_previous != NULL)
				node->m_previous->m_next = node;
			else
				//m_root = node;

			// set the iterator's previous node pointer to the "new node"
			it.m_node->m_previous = node;

			// now all the node pointers are pointing to the right thing

			// if the iterator's current node is the root node, make the "new node" the root node
			if (it.m_node == m_root)
				m_root = node;

			m_size++;
		}
	}

	void Insert_After(LinkIterator<T>& it, T newData, int newPriority)
	{

		assert(it.m_node != NULL);

		LinkNode<T>* node = new LinkNode<T>(0,0);
		assert(node != NULL);

		node->m_data = newData;
		node->m_priority = newPriority;
		node->m_next = it.m_node->m_next;
		node->m_previous = it.m_node;

		if (node->m_next != NULL)
			node->m_next->m_previous = node;

		it.m_node->m_next = node;

		if (it.m_node == m_lastNode)
			m_lastNode = node;

		m_size++;

	}

//private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;
};