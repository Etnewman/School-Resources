#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;


class BinaryTree
{
	private:
		struct TreeNode
		{
			string name;
			int krabbyPatty;
			TreeNode* left;
			TreeNode* right;
		};
		
		TreeNode* root;
		
		// Private member functions
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		//void deleteNode(string n, TreeNode *&);
		//void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void display(TreeNode *ptr, int level);
		void getTotal(TreeNode *nodePtr, int &total);
		void getMost(TreeNode *nodePtr, string& n, int& mostPatties);
		void getLeast(TreeNode *nodePtr, string& n, int& leastPatties);
		int height(TreeNode *temp)
		{
			int h = 0;
			if (temp != NULL)
			{
				int l_height = height(temp->left);
				int r_height = height(temp->right);
				int max_height = max(l_height, r_height);
				h = max_height + 1;
			}
			return h;
		
		}
		int diff(TreeNode *temp)
		{
			int l_height = height(temp->left);
			int r_height = height(temp->right);
			int b_factor= l_height - r_height;
			return b_factor;
		}


		
		TreeNode *l_rotation(TreeNode *parent)
		{
			TreeNode *temp;
			temp = parent->right;
	
			parent->right = temp->left;
			temp->left = parent;
	
			return temp;
		}
		
		TreeNode *r_rotation(TreeNode *parent)
		{
			TreeNode* temp;
			temp = parent->left;
			
			parent->left = temp->right;
			temp->right = parent;
			
			return temp;
		}
		
		TreeNode *lr_rotation(TreeNode *parent)
		{
			TreeNode *temp;
			temp = parent->left;
			
			parent->left = l_rotation(temp);
			return r_rotation(parent);
		}
		
		TreeNode *rl_rotation(TreeNode *parent)
		{
			TreeNode *temp;
			temp = parent->right;
			
			parent->right = r_rotation(temp);
			return l_rotation(parent);
		}
		
		TreeNode *balance(TreeNode *temp)
		{
			int bal_factor = diff(temp);
			
			if (bal_factor > 1)
			{
				if (diff(temp->left) > 0)
				{
					temp = r_rotation(temp);
				}
				else	
				{
					temp = lr_rotation(temp);
				}
			}
			else if (bal_factor < -1)
			{
				if (diff(temp->right) > 0)
				{
					temp = rl_rotation(temp);
				}
				else
				{
					temp = l_rotation(temp);
				}
			}
			return temp;
		}

	public:
		// Constructor
		BinaryTree()
		{ 
			root = NULL; 
		}

		// Destructor
		~BinaryTree()
		{ 
			destroySubTree(root); 
		}

		// Binary tree operations
		void insertNode(string, int);
		int searchNode(string);
		//void remove(string);

		void displayInOrder() const
		{  
			displayInOrder(root); 
		}
		
		void getLeastNumPatties(string&, int&);
		void getMostNumPatties(string&, int&);
		int getTotalNumPatties();
		void displayTree();
		
		

};


#endif