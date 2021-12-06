#pragma once
#include <iostream>

using namespace std;
size_t get_size;
int per = 0;
int firstgo = 0;
int sizeofstack = 0;

class Queue
{
private:
	class Node
	{
	public:
		int element;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	int size_queue;
	Queue()
	{
		Node* current = new Node;
		head = current;
		current->next = NULL;
		tail = head = current;
		size_queue = 0;
	}
	~Queue()
	{
		while (head != tail)
			remove();
	}
	int getfirst()
	{
		if (size_queue != 0)
		{
			return head->element;
		}
		else
		{
			throw out_of_range("Empty list");
		}
	}
	void remove() // delete an element
	{
		head = head->next;
		size_queue--;
	}
	void insert(int element)
	{
		if (size_queue == 0)
		{
			head = new Node;
			head->element = element;
			tail = head;
		}
		else
		{
			tail->next = new Node;
			tail = tail->next;
			tail->element = element;
			tail->next = NULL;
		}
		size_queue++;
	}
};

class Stack
{
private:
	class Node
	{
	public:
		int element;
		Node* previous;
	};


public:
	Node* current;
	int size_stack;

	Stack()
	{
		Node* buffer = new Node;
		buffer->element = NULL;
		buffer->previous = NULL;
		size_stack = 0;
	}
	~Stack()
	{
		Node* buffer;
		while (current)
		{
			buffer = current->previous;
			delete(current);
			current = buffer;
		}
	}

	void add(int element)
	{
		if (size_stack == 0)
		{
			Node* buffer = new Node;
			buffer->element = element;
			buffer->previous = nullptr;
			current = buffer;
		}
		else
		{
			Node* buffer = current;
			current = new Node;
			current->element = element;
			current->previous = buffer;
		}
		size_stack++;
	}
	void remove()
	{
		Node* buffer = current;
		current = current->previous;
		delete(buffer);
		size_stack--;
	}
	int getlast()
	{
		return current->element;
	}
	int size()
	{
		if (sizeofstack == 0)
			return size_stack;
		else
			return 0;
	}

};



class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};

class Tree
{
private:
	class Node
	{
	public:
		Node* left = NULL;
		Node* right = NULL;
		int element = NULL;
		int forstack = 0;
	};
	Node* parent;

public:


	Iterator* create_BFT_iterator()
	{
		return new ListIteratorBFT(parent);
	}
	Iterator* create_DFT_iterator()
	{
		return new ListIteratorDFT(parent);
	}

	void push_back(int element)
	{
		Node* buffer = new Node;
		buffer->element = element;
		if (parent->element == NULL)
		{
			parent = buffer;
			parent->left = NULL;
			parent->right == NULL;
		}
		else
		{
			Node* root = parent;
			while (1)
			{
				if (root->element >= buffer->element)
				{
					if (root->left == NULL)
						root->left = new Node;
					root = root->left;
				}
				else {
					if (root->right == NULL)
						root->right = new Node;
					root = root->right;
				}
				if (root->element == NULL)
				{
					root->element = (int)buffer->element;
					break;
				}
			}
		}
		get_size++;
	}
	Tree() // default constructor
	{
		Node* buffer = new Node;
		buffer->left = buffer->right = NULL;
		buffer->element = NULL;
		parent = buffer;
	}



	class ListIteratorBFT : public Iterator
	{
	public:

		ListIteratorBFT(Node* buffer)
		{
			current = buffer;
			check = current;
			queue.insert(buffer->element);
		};
		bool has_next() override;
		int next() override;

	private:
		Queue queue;
		Node* current;
		Node* check;

	};

	class ListIteratorDFT : public Iterator
	{
	public:

		ListIteratorDFT(Node* buffer)
		{
			current = buffer;
			checkstack = current;
			stack.add(buffer->element);
		};
		bool has_next() override;
		int next() override;

	private:
		Stack stack;
		Node* current;
		Node* checkstack;

	};


	bool Contains(int value)
	{
		Node* buffer;
		Node* root = parent;
		bool answer = false;
		if (root->element == value)
		{
			answer = true;
		}
		while (answer == false && (root->left != nullptr || root->right != nullptr))
		{

			if (value <= root->element)
			{
				root = root->left;
			}
			else
			{
				root = root->right;
			}
			if (root->element == value)
			{
				answer = true;
				break;
			}
		}
		return answer;
	}
	void insert(int value)
	{
		Node* buffer = parent;
		bool answer = false;
		Node* root = parent;
		if (root->element >= value)
		{
			root = root->left;
		}
		else root = root->right;
		while (1)
		{
			if (root != NULL)
			{
				if (root->left == NULL && root->right == NULL)
				{
					break;
				}
			}
			else
			{
				if (value <= buffer->element)
				{
					buffer->left = new Node;
					buffer->left->element = value;
				}
				else
				{
					buffer->right = new Node;
					buffer->right->element = value;
				}
				answer = true;

				break;
			}
			buffer = root;
			if (root->element >= value)
			{
				root = root->left;
			}
			else root = root->right;
		}
		if (answer == false)
			if (root->element >= value)
			{
				root->left = new Node;
				root->left->element = value;
			}
			else
			{
				root->right = new Node;
				root->right->element = value;
			}
	}
	void remove(int value)
	{
		Node* root = parent;
		Node* buffer = parent;
		Node* help = parent;
		while (root->element != value)
		{
			if (root->element >= value)
			{
				buffer = root;
				root = root->left;
			}
			else
			{
				buffer = root;
				root = root->right;
			}
		}
		if (root->left == nullptr && root->right == nullptr)
		{
			if (buffer->left == root)
			{
				buffer->left = nullptr;
			}
			else
				buffer->right = nullptr;
			delete(root);
		}
		else
		{
			if (root->left == nullptr)
			{
				root->element = root->right->element;
				root = root->right;
				buffer->right = nullptr;
				delete(root);
			}
			else
				if (root->right == nullptr)
				{
					root->element = root->left->element;
					root = root->left;
					buffer->left = nullptr;
					delete (root);
				}
			if (root->left != nullptr && root->right != nullptr)
			{
				buffer = root;
				buffer = buffer->right;
				while (buffer->left != nullptr)
				{
					help = buffer;
					buffer = buffer->left;
				}
				root->element = buffer->element;
				if (help != parent)
					help->left = nullptr;
				delete(buffer);
			}
		}
	}
};

int Tree::ListIteratorBFT::next()
{
	int temp = queue.getfirst();

	if (queue.getfirst() == current->element && per == 0)
	{
		check = current;
		per = 1;
	}
	else
	{
		if (check != nullptr)
			current = check;
	}
	queue.remove();
	while (current->element != temp)
	{
		if (current->element > temp)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	if (current->left != nullptr)
	{
		queue.insert(current->left->element);
	}

	if (current->right != nullptr)
	{
		queue.insert(current->right->element);
	}
	return temp;

}

bool Tree::ListIteratorBFT::has_next()
{
	if (queue.size_queue == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Tree::ListIteratorDFT::next()
{
	int per = 0;
	int temp = 0;

	if (current->element == stack.current->element && firstgo == 0)
	{
		firstgo = 1;
		temp = current->element;
		return temp;
	}
	else
	{
		current = checkstack;
		while (1)
		{
			if (current == checkstack)
				while (stack.getlast() != current->element)
				{
					if (current->element > stack.getlast())
					{
						current = current->left;
					}
					else
					{
						current = current->right;
					}
				}
			if (current->left != nullptr && current->left->forstack == 0)
			{
				current = current->left;
				stack.add(current->element);
				temp = current->element;
				break;
			}
			else

				if (current->right != nullptr && current->right->forstack == 0)
				{
					current = current->right;
					stack.add(current->element);
					temp = current->element;
					if (current->left == nullptr && current->right == nullptr)
					{
						stack.remove();
						current->forstack = 1;
					}
					break;
				}
				else
				{
					stack.remove();
					current->forstack = 1;
					current = checkstack;
				}
		}
	}
	if (checkstack->left->forstack == 1 && checkstack->left->forstack == 1)
	{
		sizeofstack = 1;
		return temp;
	}
	else
		return temp;
}

bool Tree::ListIteratorDFT::has_next()
{
	if (stack.size() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}