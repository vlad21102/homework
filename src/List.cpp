#include "../header/List.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

List::List()
{
	head = nullptr;
	size = 0;
}

List::List(const std::initializer_list<int> values)
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
		PushBack(current->GetValue());
		current = current->GetNext();
	}
}

void List::PushFront(const int value)
{
	Node* node = new Node(value);

	node->SetNext(head);
	head = node;
	++size;
}

void List::PushBack(const int value)
{
	Node* node = new Node(value);

	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		Node* current = head;

		while (current->GetNext() != nullptr)
		{
			current = current->GetNext();
		}

		current->SetNext(node);
	}

	++size;
}

void List::Insert(const size_t index,const int value)
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
		current = current->GetNext();
	}

	Node* node = new Node(value);

	node->SetNext(current->GetNext());
	current->SetNext(node);
	++size;
}

bool List::Remove(const int value)
{
	if (head == nullptr)
	{
		return false;
	}

	if (head->GetValue() == value)
	{
		Node* deletedNode = head;

		head = head->GetNext();
		delete deletedNode;
		--size;

		return true;
	}

	Node* current = head;

	while (current->GetNext() != nullptr && current->GetNext()->GetValue() != value)
	{
		current = current->GetNext();
	}

	if (current->GetNext() == nullptr)
	{
		return false;
	}

	Node* deletedNode = current->GetNext();

	current->SetNext(deletedNode->GetNext());
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
	int value = deletedNode->GetValue();

	head = head->GetNext();
	delete deletedNode;
	--size;

	return value;
}

bool List::Contains(const int value) const
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->GetValue() == value)
		{
			return true;
		}

		current = current->GetNext();
	}

	return false;
}

bool List::Change(const int oldValue, const int newValue)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->GetValue() == oldValue)
		{
			current->SetValue(newValue);
			return true;
		}

		current = current->GetNext();
	}

	return false;
}

int List::GetValue(const size_t index) const
{
	if (index >= size)
	{
		std::cerr << "Индекс выходит за границы списка" << std::endl;
		exit(1);
	}

	Node* current = head;

	for (size_t i = 0; i < index; ++i)
	{
		current = current->GetNext();
	}

	return current->GetValue();
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

		head = head->GetNext();
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
		stream << current->GetValue();

		if (current->GetNext() != nullptr)
		{
			stream << ", ";
		}

		current = current->GetNext();
	}

	stream << "}";

	return stream.str();
}

std::ostream& operator << (std::ostream& out, const List& list)
{
	out << list.ToString();

	return out;
}
