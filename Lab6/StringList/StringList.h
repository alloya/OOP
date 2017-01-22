#pragma once

#include <string>
#include <memory>
using namespace std;

class CStringList
{
	struct Node
	{
		Node(const string & data, Node * prev, unique_ptr<Node> && next)
			: data(data), prev(prev), next(move(next))
		{
		}
		string data;
		Node *prev;
		unique_ptr<Node> next;
	};
public:
	CStringList() = default;
	~CStringList();
	class CIterator
	{
		friend CStringList;
		CIterator(Node *node);
	public:
		CIterator() = default;
		string & operator*()const;
		CIterator & operator++();
	private:
		Node *m_node = nullptr;
	};

	size_t GetSize()const;
	void Append(const string& data);
	bool Empty()const;
	void PushFront(const string &data);
	void Clear();
	CIterator begin();
	CIterator end();
	CIterator const cbegin()const;
	CIterator const cend()const;

	CIterator rbegin();
	CIterator rend();
	CIterator const crbegin()const;
	CIterator const crend()const;

	string & GetBackElement();
	string & GetFrontElement();
	string const& GetBackElement()const;
	string const& GetFrontElement()const;
private:
	size_t m_size = 0;
	unique_ptr<Node> m_firstNode;
	Node * m_lastNode = nullptr;
};