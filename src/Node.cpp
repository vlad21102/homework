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

void Node::SetValue(int newValue)
{
	value = newValue;
}

Node* Node::GetNext() const
{
	return next;
}

void Node::SetNext(Node* nextNode)
{
	next = nextNode;
}
