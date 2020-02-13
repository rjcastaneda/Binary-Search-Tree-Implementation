
#ifndef ASSIGNMENT_5_TREENODE_H
#define ASSIGNMENT_5_TREENODE_H

#include <iostream>


class TreeNode
{
        friend class BST;
        public:
        TreeNode();  //default constructor
        TreeNode(int i,TreeNode* L = 0, TreeNode* R = 0); //explicit value constructor
        int getItem () const; // accessor function


        private:

        int item;
        TreeNode *Lchild;
        TreeNode *Rchild;

};

inline TreeNode::TreeNode()
{
    Lchild = Rchild = NULL;
}

inline TreeNode::TreeNode(int i, TreeNode *L, TreeNode *R) : item(i), Lchild(L), Rchild(R)
{
}

inline int TreeNode::getItem() const
{
    return item;
}



#endif //ASSIGNMENT_5_TREENODE_H
