#pragma once

template <typename T>
class CMyStack
{
public:
	CMyStack() = default;

	CMyStack(CMyStack<T> const &stack)
	{
		*this = stack;
	}

	CMyStack(CMyStack<T> &&stack)
	{
		*this = std::move(stack);
	}

	~CMyStack()
	{
		Clear();
	}

	bool IsEmpty()
	{
		return (m_size == 0);
	}

	void Pop()
	{
		if (IsEmpty())
		{
			trow std::underflow_error("Stack is empty.");
		}
		m_last = m_last->prevNode;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	void Push(const T &element)
	{
		auto newElement = std::make_shared<Node>();
		newElement->data = element;
		if (m_last != nullptr)
		{
			newElement->prevNode = m_last;
		}
		m_last = newElement;
		++m_size;
	}

	T GetLastElement()const
	{
		if (IsEmpty())
		{
			trow std::underflow_error("Stack is empty.");
		}
		return m_last->data;
	}

private:
	struct Node
	{
		T data = T();
		std::shared_ptr<Node> prevNode = nullptr;
	};

	size_t m_size;
	std::shared_ptr<Node> m_last = nullptr;
};