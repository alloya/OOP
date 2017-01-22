#include "stdafx.h"
#include "StringList.h"
#include <cassert>

using namespace std;

size_t CStringList::GetSize() const
{
	return m_size;
}

void CStringList::Append(const string & data)
{
	auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
	Node *newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = move(newNode);
	}
	else // empty list
	{
		m_firstNode = move(newNode);
	}
	m_lastNode = newLastNode;
	++m_size;
}

CStringList::CIterator CStringList::begin()
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator const CStringList::cbegin() const
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator CStringList::end()
{
	return CIterator(m_lastNode->next.get());
}

CStringList::CIterator const CStringList::cend() const
{
	return CIterator(m_lastNode->next.get());
}


CStringList::CIterator CStringList::rbegin()
{
	return CIterator(m_lastNode->next.get());
}

CStringList::CIterator const CStringList::crbegin() const
{
	return CIterator(m_lastNode->next.get());
}

CStringList::CIterator CStringList::rend()
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator const CStringList::crend() const
{
	return CIterator(m_firstNode.get());
}

string & CStringList::GetBackElement()
{
	assert(m_lastNode);
	return m_lastNode->data;
}

string const & CStringList::GetBackElement() const
{
	assert(m_lastNode);
	return m_lastNode->data;
}

CStringList::CIterator::CIterator(Node * node)
	:m_node(node)
{
}

string & CStringList::CIterator::operator*() const
{
	return m_node->data;
}

CStringList::CIterator & CStringList::CIterator::operator++()
{
	m_node = m_node->next.get();
	return *this;
}