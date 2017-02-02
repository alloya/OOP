template <typename T>
class CMyStack
{
public:
	CMyStack() = default;

	CMyStack(const CMyStack<T> & stack)
	{
		if (std::addressof(stack) != this)
		{
			std::shared_ptr<Node> tmp = stack.m_last;
			std::shared_ptr<Node> currentElement = std::make_shared<Node>(tmp->data);
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
	}

	CMyStack(CMyStack<T> && stack)
	{
		if (std::addressof(stack) != this)
		{
			m_last = stack.m_last;
			m_size = stack.m_size;
			stack.m_last = nullptr;
			stack.m_size = 0;
		}
	}

	~CMyStack()
	{
		Clear();
	}

	bool IsEmpty() const
	{
		return m_size == 0;
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	void Push(const T & data)
	{
		m_last = std::make_shared<Node>(data, m_last);
		++m_size;
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

	T GetTop() const
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

	CMyStack & operator=(const CMyStack<T> &stack)
	{
		if (std::addressof(stack) != this)
		{
			Clear();
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
			Clear();
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
			: data(data)
			, next(next)
		{
		}

		T data;
		std::shared_ptr<Node> next = nullptr;
	};

	std::shared_ptr<Node> m_last = nullptr;
	size_t m_size = 0;
};