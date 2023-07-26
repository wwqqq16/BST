#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "dsexceptions.h"
#include "StackLi.h"
#include <iostream>
#include <fstream>

using namespace std;

  // Binary node and forward declaration because g++ does
  // not understand nested classes.
template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
      : element( theElement ), left( lt ), right( rt ) { }
    friend class BinarySearchTree<Comparable>;
};


// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// void printRange(x,y)   --> Prints all values from x to y, inclusive
template <class Comparable>
class BinarySearchTree
{
 public:

	// explicit BinarySearchTree(const Comparable & notFound) :
	// 	root(NULL), ITEM_NOT_FOUND(notFound)
	// {
	// }

	// BinarySearchTree(const BinarySearchTree<Comparable> & rhs) :
	// 	 root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND)
	// {
	// 	*this = rhs;
	// }

	// ~BinarySearchTree()
	// {
	// 	makeEmpty();
	// }


	// void insert(const Comparable & x)
	// {
	// 	insert(x, root);
	// }
	
	// void remove(const Comparable & x)
	// {
	// 	remove(x, root);
	// }

	// const Comparable & findMin() const
	// {
	// 	return elementAt(findMin(root));
	// }

	// const Comparable & findMax() const
	// {
	// 	return elementAt(findMax(root));
	// }

	// const Comparable & find(const Comparable & x) const
	// {
	// 	return elementAt(find(x, root));
	// }

	// bool isEmpty() const
	// {
	// 	return root == NULL;
	// }

	// const BinarySearchTree<Comparable>& operator=(const BinarySearchTree<Comparable> & rhs)
	// {
	// 	if (this != &rhs)
	// 	{
	// 		makeEmpty();
	// 		root = clone(rhs.root);
	// 	}
	// 	return *this;
	// }

	// void makeEmpty()
	// {
	// 	makeEmpty(root);
	// }

	// void printTree() const
	// {
	// 	if (isEmpty())
	// 		cout << "Empty tree" << endl;
	// 	else
	// 		printTree(root);
	// }

	// void printRange(const Comparable &x, const Comparable &y) const
	// {
	// 	// Students must write this.
	// 	if (root == NULL)
	// 	{
	// 		return;
	// 	}

	// 	int upper = y > x ? y : x;
	// 	int lower = x <= y ? x : y;
		 
	// 	StackLi<BinaryNode<Comparable>*> stack;
	// 	stack.push(root);
	// 	while (!stack.isEmpty())
	// 	{
	// 		BinaryNode<Comparable>* crt_node = stack.top();
	// 		stack.pop();

	// 		if (crt_node->element < lower)
	// 		{
	// 			if (crt_node->right != NULL)
	// 			{
	// 				stack.push(crt_node->right);
	// 			}
	// 		}
	// 		else if (crt_node->element > upper)
	// 		{
	// 			if (crt_node->left != NULL)
	// 			{
	// 				stack.push(crt_node->left);
	// 			}
	// 		}
	// 		else
	// 		{
	// 			cout << crt_node->element << " ";
	// 			if ((crt_node->element == upper) && (crt_node->element > lower))
	// 			{
	// 				if (crt_node->left != NULL)
	// 				{
	// 					stack.push(crt_node->left);
	// 				}
	// 			}
	// 			else if ((crt_node->element == lower) && (crt_node->element < upper))
	// 			{
	// 				if (crt_node->right != NULL)
	// 				{
	// 						 stack.push(crt_node->right);
	// 				}
	// 			}
				 
	// 			else if ((crt_node->element > lower) && (crt_node->element < upper))
	// 			{
	// 				if (crt_node->right != NULL)
	// 				{
	// 					stack.push(crt_node->right);
	// 				}
	// 				if (crt_node->left != NULL)
	// 				{
	// 					stack.push(crt_node->left);
	// 				}
	// 			}
				 
	// 		}
	// 	}

	// 	cout << endl;
	// }



    explicit BinarySearchTree( const Comparable & notFound );
    BinarySearchTree( const BinarySearchTree & rhs );
    ~BinarySearchTree( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    void printRange(const Comparable &x, const Comparable &y) const;

    const BinarySearchTree & operator=( const BinarySearchTree & rhs );

 private:
    BinaryNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

	// const Comparable& elementAt(BinaryNode<Comparable>* t) const
	// {
	// 	return t == NULL ? ITEM_NOT_FOUND : t->element;
	// }

	// void insert(const Comparable & x, BinaryNode<Comparable> * & t) const
	// {
	// 	if (t == NULL)
	// 		t = new BinaryNode<Comparable>(x, NULL, NULL);
	// 	else if (x <= t->element)
	// 		insert(x, t->left);
	// 	else if (t->element < x)
	// 		insert(x, t->right);
	// }

	// void remove(const Comparable & x, BinaryNode<Comparable> * & t) const
	// {
	// 	if (t == NULL)
	// 		return;  // Item not found; do nothing
	// 	if (x < t->element)
	// 		remove(x, t->left);
	// 	else if (t->element < x)
	// 		remove(x, t->right);
	// 	else if (t->left != NULL && t->right != NULL) // Two children
	// 	{
	// 		t->element = findMin(t->right)->element;
	// 		remove(t->element, t->right);
	// 	}
	// 	else
	// 	{
	// 		BinaryNode<Comparable> *oldNode = t;
	// 		t = (t->left != NULL) ? t->left : t->right;
	// 		delete oldNode;
	// 	}
	// }

	// BinaryNode<Comparable>* findMin(BinaryNode<Comparable> *t) const
	// {
	// 	if (t == NULL)
	// 		return NULL;
	// 	if (t->left == NULL)
	// 		return t;
	// 	return findMin(t->left);
	// }

	// BinaryNode<Comparable>* findMax(BinaryNode<Comparable> *t) const
	// {
	// 	if (t != NULL)
	// 		while (t->right != NULL)
	// 			t = t->right;
	// 	return t;
	// }

	// BinaryNode<Comparable>* find(const Comparable & x, BinaryNode<Comparable> *t) const
	// {
	// 	if (t == NULL)
	// 		return NULL;
	// 	else if (x < t->element)
	// 		return find(x, t->left);
	// 	else if (t->element < x)
	// 		return find(x, t->right);
	// 	else
	// 		return t;  // Match
	// }

	// void makeEmpty(BinaryNode<Comparable> * & t) const
	// {
	// 	if (t != NULL)
	// 	{
	// 		makeEmpty(t->left);
	// 		makeEmpty(t->right);
	// 		delete t;
	// 	}
	// 	t = NULL;
	// }

	// void printTree(BinaryNode<Comparable> *t) const
	// {
	// 	if (t != NULL)
	// 	{
	// 		printTree(t->left);
	// 		cout << t->element << endl;
	// 		printTree(t->right);
	// 	}
	// }
	// BinaryNode<Comparable>* clone(BinaryNode<Comparable> * t) const
	// {
	// 	if (t == NULL)
	// 		return NULL;
	// 	else
	// 		return new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right));
	// }


    const Comparable & elementAt( BinaryNode<Comparable> *t ) const;

    void insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
    void makeEmpty( BinaryNode<Comparable> * & t ) const;
    void printTree( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;
};

#endif

