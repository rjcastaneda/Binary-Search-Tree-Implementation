

#include <iostream>
#include <ostream>
#include "BST.h"


using namespace std;


int main()
{
    //Create Tree
    BST Tree1;

    //Inserting Values
    cout << "Adding values 3, 7, 16, 25, 45, 53, 16" << endl;
    cout << endl;
    Tree1.insertNode(3);
    Tree1.insertNode(7);
    Tree1.insertNode(16);
    Tree1.insertNode(25);
    Tree1.insertNode(45);
    Tree1.insertNode(53);
    Tree1.insertNode(16);
    cout << endl;

    //Traversing
    cout<< "printing out BST in inOrder fashion" << endl;
    Tree1.traverseInOrder(cout);
    cout << endl;
    cout << endl;

    cout<< "printing out BST in PreOrder fashion" << endl;
    Tree1.traversePreorder(cout);
    cout <<endl;
    cout << endl;

    cout<< "printing out BST in PostOrder fashion" <<endl;
    Tree1.traversePostOrder(cout);
    cout << endl;
    cout << endl;

    cout<< "Deleting value 25" <<endl;
    Tree1.deleteNode(25);
    Tree1.traverseInOrder(cout);
    cout << endl;
    cout << endl;

    cout<< "Searching for element 45 and 25" <<endl;
    if (Tree1.searchElement(45) == true)
    {
        cout << "45 is in the element" << endl;
    }
    if (Tree1.searchElement(25) == false)
    {
        cout << "25 is not in the element" <<endl;
    }
    cout << endl;

    return 0;
}
