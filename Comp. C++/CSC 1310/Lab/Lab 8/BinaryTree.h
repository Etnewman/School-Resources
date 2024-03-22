#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

using namespace std;

template <class T>
class BinaryTree
{
	private:
		struct TreeNode
		{
			T value;
			TreeNode *left;
			TreeNode *right;
		};
		
		TreeNode *root;
		
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(T, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;
		
	public:
		BinaryTree()
			{ root = NULL; }
			
		~BinaryTree()
			{ destroySubTree(root); }
			
		void insertNode(T);
		bool searchNode(T);
		void remove(T);
   
		void displayInOrder() const
			{  displayInOrder(root); }
      
		void displayPreOrder() const
			{  displayPreOrder(root); }
      
		void displayPostOrder() const
			{  displayPostOrder(root); }
};

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     
   else 
      insert(nodePtr->right, newNode);    
}

template <class T>
void BinaryTree<T>::insertNode(T item)
{
	TreeNode *newNode = NULL;
   
	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = NULL;	
	
	insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		
		delete nodePtr;
   }
}

template <class T>
bool BinaryTree<T>::searchNode(T item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}	

template <class T>
void BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr = NULL;

   
   
	if (nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
   }
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);     
		displayPreOrder(nodePtr->right);
	}
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);    
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

#endif