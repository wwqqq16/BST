#include "BST2.h"
#include <iostream>
using namespace std;

template <class Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const Comparable & notFound) :
		root(NULL), ITEM_NOT_FOUND(notFound)
{
}

template <class Comparable>
BinarySearchTree<Comparable>:BinarySearchTree(const BinarySearchTree<Comparable> & rhs) :
		 root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND)
{
	*this = rhs;
}

template <class Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}

template <class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
	insert(x, root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
	remove(x, root);
}

template <class Comparable>
const BinarySearchTree<Comparable>::Comparable & findMin() const
{
	return elementAt(findMin(root));
}

template <class Comparable>
const BinarySearchTree<Comparable>::Comparable & findMax() const
{
	return elementAt(findMax(root));
}

template <class Comparable>
const BinarySearchTree<Comparable>::Comparable & find(const Comparable & x) const
{
	return elementAt(find(x, root));
}


template <class Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
	return root == NULL;
}

template <class Comparable>
const BinarySearchTree<Comparable>::BinarySearchTree<Comparable>& operator=(const BinarySearchTree<Comparable> & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
	makeEmpty(root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::printRange(const Comparable &x, const Comparable &y) const
{
	// Students must write this.
	if (root == NULL)
	{
		return;
	}
	int upper = y > x ? y : x;
	int lower = x <= y ? x : y;
	 
	StackLi<BinaryNode<Comparable>*> stack;
	stack.push(root);
	while (!stack.isEmpty())
	{
		BinaryNode<Comparable>* crt_node = stack.top();
		stack.pop();
		if (crt_node->element < lower)
		{
			if (crt_node->right != NULL)
			{
				stack.push(crt_node->right);
			}
		}
		else if (crt_node->element > upper)
		{
			if (crt_node->left != NULL)
			{
				stack.push(crt_node->left);
			}
		}
		else
		{
			cout << crt_node->element << " ";
			if ((crt_node->element == upper) && (crt_node->element > lower))
			{
				if (crt_node->left != NULL)
				{
					stack.push(crt_node->left);
				}
			}
			else if ((crt_node->element == lower) && (crt_node->element < upper))
			{
				if (crt_node->right != NULL)
				{
						 stack.push(crt_node->right);
				}
			}
			 
			else if ((crt_node->element > lower) && (crt_node->element < upper))
			{
				if (crt_node->right != NULL)
				{
					stack.push(crt_node->right);
				}
				if (crt_node->left != NULL)
				{
					stack.push(crt_node->left);
				}
			}
			 
		}
	}
	cout << endl;
}

template <class Comparable>
const BinarySearchTree<Comparable>::Comparable& elementAt(BinaryNode<Comparable>* t) const
{
	return t == NULL ? ITEM_NOT_FOUND : t->element;
}

template <class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	if (t == NULL)
		t = new BinaryNode<Comparable>(x, NULL, NULL);
	else if (x <= t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
}

template <class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	if (t == NULL)
		return;  // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode<Comparable> *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
}

template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> *t) const
{
	if (t != NULL)
		while (t->right != NULL)
			t = t->right;
	return t;
}

template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::find(const Comparable & x, BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	else if (x < t->element)
		return find(x, t->left);
	else if (t->element < x)
		return find(x, t->right);
	else
		return t;  // Match
}

template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode<Comparable> * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

template <class Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode<Comparable> *t) const
{
	if (t != NULL)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}

template <class Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::clone(BinaryNode<Comparable> * t) const
{
	if (t == NULL)
		return NULL;
	else
		return new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right));
}