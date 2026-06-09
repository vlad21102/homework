#include "../header/Node.h"

Node::Node(int nodeValue)
{
	value = nodeValue;
	next = nullptr;
}

int Node::GetValue() const
{
	return value;
}

void Node::SetValue(const int newValue)
{
	value = newValue;
}

Node* Node::GetNext() const
{
	return next;
}

void Node::SetNext(const Node* nextNode)
{
	next = nextNode;
}
