#include "Libraries.h"

template<typename T>
class Ring
{
private:
	class Node
	{
		friend std::ostream& operator<<(std::ostream& out, const Node& node)
		{
			out << node.data << std::endl;
			return out;
		}
	public:
		T data;
		Node* next;
	};
private:
	Node* _last;
	Node* _head;
	size_t _size;
public:
	class Iterator;
	Ring(T data);
	Ring();
	~Ring();
	Ring(const Ring&);
	inline void Show();
	inline int Size();
	inline void Push(T);
	inline void Remove(const int);
	inline int Find(T);
	inline void Remove_by_data(const T);
	inline bool empty();
	Iterator begin() { return _head; }
	Iterator end() { return _last; } 
public:
	class Iterator
	{
	private:
		friend class Ring<T>;
		Node* _currentNode;
	public:
		Iterator():_currentNode(nullptr)
		{
		}

		Iterator(Node* node)
		{
			_currentNode = node;
		}

		Iterator& operator++(int n) {
			this->_currentNode = this->_currentNode->next;
			return *this;
		}

		Iterator& operator-- (int n) {
			Node* temp = new Node;
			temp = this->_currentNode;
			while(this->_currentNode->next != temp)
			{
				this->_currentNode = this->_currentNode->next;
			}
			return *this;
		}

		Iterator& operator = (const Iterator &it) {
			this->_currentNode = it._currentNode;
			return *this;
		}

		Iterator& operator+(int n) {
			for (int i = 0; i < n; i++)
				this->_currentNode = this->_currentNode->next;
			return *this;
		}

		bool operator ==(const Iterator& it) {
			return (this->_currentNode == it._currentNode);
		}

		bool operator !=(const Iterator& it) { 
			return (this->_currentNode != it._currentNode);
		}

		Node& operator* () { 
			return *_currentNode; 
		}
	};
};

template<typename T>
inline Ring<T>::Ring(T data)
{
	this->Push(data);
}

template<typename T>
inline Ring<T>::Ring()
{
	this->_last = this->_head = nullptr;
	_size = 0;
}

template<typename T>
inline Ring<T>::~Ring()
{
	Node* temp, *cur;
	if (this->_head != nullptr)
	{
		cur = _head->next;
		while (cur != _head)
		{
			temp = cur;
			cur = cur->next;
			delete temp;
		}
	}
}

template<typename T>
inline Ring<T>::Ring(const Ring& ring)
{
	Node* cur = ring._head;
	do
	{
		this->Push(cur->data);
		cur = cur->next;
	} while (cur != ring._head);
}

template<typename T>
inline void Ring<T>::Show()
{
	if (empty())
	{
		std::cout << "Кольцо пусто" << std::endl;
		return;
	}
	Node* cur = _head;
	do
	{
		std::cout << cur->data;
		cur = cur->next;
		std::cout << std::endl;
	} while (cur != _head);
	return;
}

template<typename T>
inline int Ring<T>::Size()
{
	return this->_size;
}

template<typename T>
inline void Ring<T>::Push(T data)
{
	if (this->_head == nullptr)
	{
		this->_head = this->_last = new Node;
		this->_last->data = this->_head->data = data;
		this->_head->next = this->_last;
		this->_last->next = this->_head;
		_size++;
	}
	else
	{
		Node* newNode = new Node;
		Node* oldLast = _last;
		newNode->data = data;
		newNode->next = this->_head;
		_last = newNode;
		oldLast->next = newNode;
		_size++;
	}
}

template<typename T>
inline void Ring<T>::Remove(const int position)
{
	if (empty())
	{
		std::cout << "Кольцо пусто" << std::endl;
		return;
	}
	if (this->_head == nullptr || position < 0)
	{
		return;
	}
	Node* currentNode = this->_head;
	for (int i = 0; i < position; i++, currentNode = currentNode->next);
	if (currentNode->next == _head)
	{
		_head = this->_head->next;
	}
	Node* temp = currentNode->next;
	*currentNode = *(currentNode->next);
	_size--;
	delete temp;
}

template<typename T>
inline int Ring<T>::Find(T pattern)
{
	int position = 0;
	if (empty())
	{
		std::cout << "Кольцо пусто" << std::endl;
		return -1;
	}
	Node* cur = _head;
	do
	{
		if (cur->data == pattern)
		{
			return position;
		}
		cur = cur->next;
		position++;
	} while (cur != _head);
	std::cout << "Not found" << std::endl;
}

template<typename T>
inline void Ring<T>::Remove_by_data(const T value)
{
	if (empty())
	{
		std::cout << "Кольцо пусто" << std::endl;
		return;
	}
	Remove(Find(value));
}

template<typename T>
inline bool Ring<T>::empty()
{
	if(_head == nullptr)
		return true;
	return false;
}


