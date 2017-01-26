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
			throw std::underflow_error("Stack is empty.");
		}
		m_last = m_last->next;
		--m_size;
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
			newElement->next = m_last;
		}

		m_last = newElement;

		++m_size;
	}

	T GetTop()const
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Stack is empty.");
		}
		return m_last->data;
	}

	size_t GetSize()
	{
		return m_size;
	}

	CMyStack & operator=(CMyStack<T> &stack)
	{
		if (std::addressof(stack) != this)
		{
			auto tmp = stack.m_last;
			auto currentElement = std::make_shared<Node>(tmp->data);

			m_last = currentElement;
			tmp = tmp->next;

			while (tmp != nullptr)
			{
				currentElement->next = std::make_shared<Node>(tmp->data);
				currentElement = currentElement->next;

				tmp = tmp->next;
			}

			m_size = stack.m_size;
		}

		return *this;
	}

	CMyStack & operator=(CMyStack<T> &&stack)
	{
		if (std::addressof(stack) != this)
		{
			m_last = stack.m_last;
			m_size = stack.m_size;
			stack.m_last = nullptr;
			stack.m_size = 0;
		}

		return *this;
	}

private:
	struct Node
	{
		Node(const T &data, const std::shared_ptr<Node> &next = nullptr)
			:data(data)
			,next(next)
		{
		}
		T data;
		std::shared_ptr<Node> next = nullptr;
	};

	size_t m_size = 0;
	std::shared_ptr<Node> m_last = nullptr;
};