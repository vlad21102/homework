#include "../header/List.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

List::Node::Node(int nodeValue)
{
	value = nodeValue;
	next = nullptr;
}

List::List()
{
	head = nullptr;
	size = 0;
}

List::List(std::initializer_list<int> values)
{
	head = nullptr;
	size = 0;

	for (int value : values)
	{
		PushBack(value);
	}
}

List::List(const List& other)
{
	head = nullptr;
	size = 0;

	Copy(other);
}

List::List(List&& other) noexcept
{
	head = other.head;
	size = other.size;

	other.head = nullptr;
	other.size = 0;
}

List::~List()
{
	Clear();
}

List& List::operator = (const List& other)
{
	if (this != &other)
	{
		Clear();
		Copy(other);
	}

	return *this;
}

List& List::operator = (List&& other) noexcept
{
	if (this != &other)
	{
		Clear();

		head = other.head;
		size = other.size;

		other.head = nullptr;
		other.size = 0;
	}

	return *this;
}

List& List::operator << (int value)
{
	PushBack(value);

	return *this;
}

List& List::operator >> (int& value)
{
	value = PopFront();

	return *this;
}

void List::Copy(const List& other)
{
	Node* current = other.head;

	while (current != nullptr)
	{
		PushBack(current->value);
		current = current->next;
	}
}

void List::PushFront(int value)
{
	Node* node = new Node(value);

	node->next = head;
	head = node;
	++size;
}

void List::PushBack(int value)
{
	Node* node = new Node(value);

	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		Node* current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = node;
	}

	++size;
}

void List::Insert(size_t index, int value)
{
	if (index > size)
	{
		std::cerr << "Индекс выходит за границы списка" << std::endl;
		exit(1);
	}

	if (index == 0)
	{
		PushFront(value);
		return;
	}

	if (index == size)
	{
		PushBack(value);
		return;
	}

	Node* current = head;

	for (size_t i = 0; i < index - 1; ++i)
	{
		current = current->next;
	}

	Node* node = new Node(value);

	node->next = current->next;
	current->next = node;
	++size;
}

bool List::Remove(int value)
{
	if (head == nullptr)
	{
		return false;
	}

	if (head->value == value)
	{
		Node* deletedNode = head;

		head = head->next;
		delete deletedNode;
		--size;

		return true;
	}

	Node* current = head;

	while (current->next != nullptr && current->next->value != value)
	{
		current = current->next;
	}

	if (current->next == nullptr)
	{
		return false;
	}

	Node* deletedNode = current->next;

	current->next = deletedNode->next;
	delete deletedNode;
	--size;

	return true;
}

int List::PopFront()
{
	if (head == nullptr)
	{
		std::cerr << "Список пуст" << std::endl;
		exit(1);
	}

	Node* deletedNode = head;
	int value = deletedNode->value;

	head = head->next;
	delete deletedNode;
	--size;

	return value;
}

bool List::Contains(int value) const
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->value == value)
		{
			return true;
		}

		current = current->next;
	}

	return false;
}

bool List::Change(int oldValue, int newValue)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->value == oldValue)
		{
			current->value = newValue;
			return true;
		}

		current = current->next;
	}

	return false;
}

int List::GetValue(size_t index) const
{
	if (index >= size)
	{
		std::cerr << "Индекс выходит за границы списка" << std::endl;
		exit(1);
	}

	Node* current = head;

	for (size_t i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->value;
}

size_t List::GetSize() const
{
	return size;
}

bool List::IsEmpty() const
{
	return size == 0;
}

void List::Clear()
{
	while (head != nullptr)
	{
		Node* deletedNode = head;

		head = head->next;
		delete deletedNode;
	}

	size = 0;
}

std::string List::ToString() const
{
	std::ostringstream stream;

	stream << "{";

	Node* current = head;

	while (current != nullptr)
	{
		stream << current->value;

		if (current->next != nullptr)
		{
			stream << ", ";
		}

		current = current->next;
	}

	stream << "}";

	return stream.str();
}

std::ostream& operator << (std::ostream& out, const List& list)
{
	out << list.ToString();

	return out;
}
