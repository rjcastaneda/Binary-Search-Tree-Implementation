

#include <iostream>
#include <ostream>
#include "TreeNode.h"


using namespace std;

#ifndef ASSIGNMENT_5_BST_H
#define ASSIGNMENT_5_BST_H

class BST
{
public:

    BST();
    bool empty() const;
    void insertNode(int val);
    bool searchElement(int val);
    void deleteNode(int val);
    void traverseInOrder(ostream & out);
    void traversePreorder(ostream & out);
    void traversePostOrder(ostream & out);

    typedef TreeNode *TreeNodePointer;



private:
    TreeNodePointer root;
    void searchElement2(int val, bool & found, BST::TreeNodePointer & location, BST::TreeNodePointer & parent);
    void inOrderAux(ostream & out, TreeNodePointer subTreePtr);
    void preOrderAux(ostream & out, TreeNodePointer subTreePtr);
    void postOrderAux(ostream & out, TreeNodePointer subTreePtr);
};

#endif //ASSIGNMENT_5_BST_H
