/*
 * Roswell James Castaneda
 * 820249749
 * 11/24/18
 * Assignment#5
 */

#include "BST.h"
#include "TreeNode.h"
#include <iostream>
#include <ostream>

using namespace std;
BST::BST()
{
root = NULL;
}

bool BST::empty() const //Empty BST
{
   return root == NULL;
}

void BST::insertNode(int val) //Adds a node into the BST
{
   BST::TreeNodePointer location = root, parent = 0;
   bool found = false;

   //Checks to see if value is already in tree
   while (!found && location !=0)
   {
      parent = location;
      if (location->item > val) //Go left down the tree
      {
         location = location->Lchild;
      }
      else if (location->item < val) //Go right down the tree
      {
         location = location->Rchild;
      }
      else
      {
         found = true;
      }
   }

   if (!found)
   {
      location = new TreeNode(val); //construct the node with the value to be added
      if (parent == 0)
      {
         root = location;
      }
      else if (val < parent->item) //insert to the left of the parent node.
      {
         parent -> Lchild = location;
      }
      else //insert node to the right of the parent node.
      {
         parent -> Rchild = location;
      }
   }
   else
   {
      cout << "The value is already inside of the tree\n";
   }
}

bool BST::searchElement(int val) //Searches for given value
{
   BST::TreeNodePointer location = root;
   bool found = false;
   while (!found && location !=0)
   {
      if (val < location->item)
      {
         location = location->Lchild;
      }
      else if (location ->item < val)
      {
         location = location->Rchild;
      }
      else
         found = true;
   }
   return found;

}
void BST::searchElement2(int val, bool & found, BST::TreeNodePointer & location, BST::TreeNodePointer & parent)
{
   location = root;
   parent = 0;
   found = false;
   while(!found && location != 0)
   {
      if (val < location->item) //Go down left of tree
      {
         parent = location;
         location = location->Lchild;
      }
      else if (location ->item < val)
      {
         parent = location;
         location = location -> Rchild;
      }
      else
      {
         found = true;
      }
   }

}

void BST::deleteNode(int val)
{
   bool found;
   BST::TreeNodePointer loc, parent;

   searchElement2(val, found, loc, parent);

   if (!found) //if node does not contain the value to be deleted
   {
      cout << "Item is not in the BST\n";
   }

   if (loc->Lchild != 0 && loc->Rchild != 0)//if node has two children
   {
      //Find's x's inorder succesor and its parent
      BST::TreeNodePointer locSuccessor = loc->Rchild;
      parent = loc;

      while (locSuccessor->Lchild != 0) //Move down left
      {
         parent = locSuccessor;
         locSuccessor = locSuccessor->Lchild;
      }

      //Move contents to loc's succesor and changes loc to point to successor
      loc->item = locSuccessor->item;
      loc = locSuccessor;
   }
   else //If node has only one child.
   {
      BST::TreeNodePointer subT = loc->Lchild;
      if (subT == 0) {
         subT = loc->Rchild;
      }
      if (parent == 0) {
         root = subT;
      } else if (parent->Lchild == loc) {
         parent->Lchild = subT;
      } else {
         parent->Rchild = subT;
      }
      delete loc;
   }
}
void BST::inOrderAux(ostream &out, BST::TreeNodePointer subTreePtr)
{

    if (subTreePtr != 0)
    {
        inOrderAux(out, subTreePtr->Lchild); //L
        out << subTreePtr->item << "  "; //V
        inOrderAux(out, subTreePtr->Rchild); //R
    }
}

void BST::preOrderAux(ostream &out, BST::TreeNodePointer subTreePtr)
{
    if (subTreePtr != 0)
    {
        out << subTreePtr->item << "  "; //V
        preOrderAux(out, subTreePtr->Lchild); //L
        preOrderAux(out, subTreePtr->Rchild); //R
    }
}


void BST::postOrderAux(ostream &out, BST::TreeNodePointer subTreePtr)
{
    if (subTreePtr != 0)
    {
        postOrderAux(out, subTreePtr->Lchild); //L
        postOrderAux(out, subTreePtr->Rchild); //R
        out << subTreePtr->item << "  "; //V
    }
}

void BST::traverseInOrder(ostream & out) //Traverse in  InOrder
{
   inOrderAux(out, root);
}

void BST::traversePreorder(ostream & out) //Traverse in preOrder
{
   preOrderAux(out, root);
}

void BST::traversePostOrder(ostream & out) //Traverse in postOrder
{
   postOrderAux(out, root);
}





