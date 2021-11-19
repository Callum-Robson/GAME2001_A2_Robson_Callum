#pragma once

template<class T>
class LinkInterator
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

private:
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
			Pop();
		}
	}

	Return first node in list;
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
		assert(M - root != NULL);

		LinkNode<T>* temp = m_root;

		m_root = m_root->m_next;

		if (m_root != NULL)
			m_root->m_previous = NULL;

		delete temp;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	// inserts a node before the node currently pointed to by the iterator passed in, set's the new node's data to what is passed in
	void InsertBefore(LinkIterator<T>& it, T newData)
	{
		assert(it.m_node != NULL);

		// create "new node"
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		// set "new node"'s data to what is passed in
		node->m_data = newData;
		// set "new node"'s next node pointer to the iterator's current node
		node->m_next = it.m_node;
		// set the "new node"'s previous node pointer to the iterator's previous node pointer
		node->m_previous = it.m_node->m_previous;

		// if the previous node that was just set is not null, set that node's next node pointer to the "new node"
		if (node->m_previous != NULL)
			node->m_previous->m_next = node;

		// set the iterator's previous node pointer to the "new node"
		it.m_node->m_previous = node;

		// now all the node pointers are pointing to the right thing

		// if the iterator's current node is the root node, make the "new node" the root node
		if (it.m_node == m_root)
			m_root = node;

		m_sizee++;
	}

private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;
};

template<class T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class LinkList<T>;

	LinkNode() : m_priority(0), m_root(0), m_next(0), m_previous(0);
	{
	}

private:
	T m_data;
	int m_priority;
	LinkNode* m_next;
	LinkNode* m_previous;
};