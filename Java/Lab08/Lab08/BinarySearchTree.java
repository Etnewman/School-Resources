
public class BinarySearchTree extends BinaryTreeBasis implements SearchTreeInterface
{ 

   private int size;	
	
   public BinarySearchTree()
   {
      super();
   }

   public KeyedItem retrieve(Comparable searchKey) 
   {
      return retrieveItem(getRootNode(), searchKey);
   }  

   public void insert(KeyedItem item) throws TreeException
   {
      setRootNode(insertItem(getRootNode(), item));
	  //adjust size and use assertions (validateBSTProperty() & validateSize())
	  
	  
   }  

   public void delete(Comparable searchKey) throws TreeException 
   {
      setRootNode(deleteItem(getRootNode(), searchKey));
	  //adjust size and use assertions (validateBSTProperty() & validateSize())
	  
	  
   }  

   protected KeyedItem retrieveItem(TreeNode tNode, Comparable searchKey)
   {
      //disallow duplicates so that you always know which object to retrieve (or delete)
      //you could return a list with all duplicate search keys (but delete is still a problem)
      KeyedItem treeItem;

      if (tNode == null) 
      {
         treeItem = null;
      }
      else 
      {
         KeyedItem nodeItem = (KeyedItem) tNode.getItem();
         int comparison = searchKey.compareTo(nodeItem.getKey());

         if (comparison == 0) 
         {
            // item is in the root of some subtree
            treeItem = nodeItem;
         }
         else if (comparison < 0) 
         {
            // search the left subtree
            treeItem = retrieveItem(tNode.getLeft(), searchKey);
         }
         else  
         { 
            // search the right subtree
            treeItem = retrieveItem(tNode.getRight(), searchKey);
         }  
      }  
      return treeItem;
   }  

   protected TreeNode insertItem(TreeNode tNode, KeyedItem item) throws TreeException
   {

      if (tNode == null) 
      {
         // position of insertion found; insert after leaf
         // create a new node
         tNode = new TreeNode(item);
         return tNode;
      }  

      TreeNode subtree;
      KeyedItem nodeItem = (KeyedItem)tNode.getItem();
      int comparison = item.getKey().compareTo(nodeItem.getKey());

      // search for the insertion position
      if (comparison == 0)
      {
         throw new TreeException ("Cannot add duplicate.");
      }
      else if (comparison < 0) 
      {
         // search the left subtree
         subtree = insertItem(tNode.getLeft(), item);
         tNode.setLeft(subtree);
      }
      else 
      { 
         // search the right subtree
         subtree = insertItem(tNode.getRight(), item);
         tNode.setRight(subtree);
      }  

      return tNode;
   }  

   protected TreeNode deleteItem(TreeNode tNode, Comparable searchKey) throws TreeException
   {

      if (tNode == null) 
      {
         throw new TreeException("Item not found");
      }

      TreeNode subtree;
      KeyedItem nodeItem = (KeyedItem)tNode.getItem();
      int comparison = searchKey.compareTo(nodeItem.getKey());

      if (comparison == 0) 
      {
         // item is in the root of some subtree
         tNode = deleteNode(tNode);  // delete the item
      }
      // else search for the item
      else if (comparison < 0) 
      {
		 //decompose these two lines into one deleteLeft(TreeNode tNode, Comparable sk) method call, and assign the value to tNode
         // search the left subtree
         subtree = deleteItem(tNode.getLeft(), searchKey);
         tNode.setLeft(subtree);
      }
      else 
      { 
		 //decompose these two lines into one deleteRight(TreeNode tNode, Comparable sk) method call, and assign the value to tNode
         // search the right subtree
         subtree = deleteItem(tNode.getRight(), searchKey);
         tNode.setRight(subtree);
      } 

      return tNode;
   }  

   protected TreeNode deleteNode(TreeNode tNode) 
   {
      // Algorithm note: There are four cases to consider:
      //   1. The tNode is a leaf.
      //   2. The tNode has no left child.
      //   3. The tNode has no right child.
      //   4. The tNode has two children.
      // Calls: findLeftmost and deleteLeftmost

      // test for a leaf --  this test is taken care of by the next two
      if ((tNode.getLeft() == null) && (tNode.getRight() == null)) 
      {
         return null;
      }  

      // test for no left child
      else if (tNode.getLeft() == null) 
      {
         return tNode.getRight();
      } 

      // test for no right child
      else if (tNode.getRight() == null) 
      {
         return tNode.getLeft();
      } 

      // there are two children:
      // retrieve and delete the inorder successor
      else 
      {
		 //decompose these lines into one method call deleteInorderSuccessor(TreeNode tNode)
         KeyedItem replacementItem = findLeftmost(tNode.getRight());
         tNode.setItem(replacementItem);
         TreeNode subtree = deleteLeftmost(tNode.getRight());
         tNode.setRight(subtree);
         return tNode;
      } 
   }  

   protected KeyedItem findLeftmost(TreeNode tNode)  
   {
      if (tNode.getLeft() == null) 
      {
         return (KeyedItem)tNode.getItem();
      }
      else 
      {
         return findLeftmost(tNode.getLeft());
      }  
   } 

   protected TreeNode deleteLeftmost(TreeNode tNode) 
   {
      if (tNode.getLeft() == null) 
      {
         return tNode.getRight();
      }
      else 
      {
		  //decompose into one method call, returning tNode
         TreeNode subtree = deleteLeftmost(tNode.getLeft());
         tNode.setLeft(subtree);
         return tNode;
      }  
   } 

   protected TreeNode rotateLeft(TreeNode tNode)
   {
      TreeNode right = tNode.getRight();
      TreeNode rightleft = right.getLeft();

      tNode.setRight(rightleft);
      right.setLeft(tNode);

      return right;
   }

   protected TreeNode rotateRight(TreeNode tNode)
   {
      TreeNode left = tNode.getLeft();
      TreeNode leftright = left.getRight();

      tNode.setLeft(leftright);
      left.setRight(tNode);

      return left;
   }
   
   public int size()
   {
      return size;
   }   
   
   public int height()
   {
      return getHeight(getRootNode());
   }

   protected int getHeight(TreeNode tNode)
   {
      if (tNode == null)
      {
         return 0;
      }

      int height = 0;
      int leftHeight = getHeight(tNode.getLeft());
      int rightHeight = getHeight(tNode.getRight());
      if (leftHeight >= rightHeight)
      {
         height = leftHeight + 1;
      }
      else
      {
         height = rightHeight + 1;
      }

      return height;
   }   
   
   public int computeSize()
   {
	  //manually step through the tree with an iterator (use setInorder)
	  //and calculate the size (some counter that you will increment) 
      int num = 0;
      TreeIterator iter = iterator();
	  
	  iter.setInorder();
	  
	  while(iter.hasNext())
	  {
		iter.next();
		  num++;
	  }
	  
	  return num;
	  
   }  
   
   public boolean validateSize()
   {
      //return true if size() is the same as computeSize()
	  if (size() == computeSize())
		  return true;
	  else
		  return false;
	  
	  
   }

   //the idea of this method is to look at our BST inorder and then make sure each previous item is not greater than the subsequent item
   public boolean validateBSTProperty()
   {
	  //manually step through the tree with an iterator (use setInorder) 
	   
      TreeIterator iter = iterator();
	  
	  
	  
      boolean valid = true;

      //an empty tree satisfies the BST property by definition
      if (!iter.hasNext()) return true;


	  //grab an item (iter.next()) and convert it to a KeyedItem (casting)
      KeyedItem item1 = (KeyedItem)(iter.next());
	  //convert the KeyedItem to type Comparable (getKey method)
      Comparable key1 = item1.getKey();
	  
      while (iter.hasNext())
      {
		 //grab the next item and convert it to a KeyedItem
         KeyedItem item2 = (KeyedItem)(iter.next());
		 //convert the KeyedItem to type Comparable
         Comparable key2 = item2.getKey();
		
		
		 //Compare key1 to key2 (compareTo method). 
		 //If the result is greater than 0 (i.e. key1 > key2), set valid to false and break
         if (key1.compareTo(key2) > 0)
         {
			valid = false;
			break;
	        
         }

		 //now update the new previous item/key to the old next item/key
         item1 = item2;
         key1 = key2;
      }

      return valid;
   }
   
   //convenience method
   public boolean isBalanced()
   {
	  //calls the recursive isBalanced method, passing in the root node
	return isBalanced(getRootNode());
   }

   protected boolean isBalanced(TreeNode tNode)
   {
	  //if nothing is in our tree, it is considered balanced
      if (tNode == null)
      {
         return true;
      }

	  //recursive call passing in tNode's left child
      boolean balanced = isBalanced(tNode.getLeft());
      if (!balanced) return balanced;
	  //recursive call passing in tNode's right child
      balanced = isBalanced(tNode.getRight());
      if (!balanced) return balanced;

      int leftHeight = getHeight(tNode.getLeft());
      int rightHeight = getHeight(tNode.getRight());
	  //if the absolute value of our leftHeight - rightHeight is greater than 1, the tree is not balanced
	  //can use Math.abs() to take an absolute value
      if (Math.abs(leftHeight - rightHeight) > 1)
      {
         balanced = false;
      }

      return balanced;
   }

} 