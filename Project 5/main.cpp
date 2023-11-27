// Bede Nnebedum
// CSDP 250 - Fall 2023
// Project 5
// Main File

#include <iostream>
#include "BST.cpp"
#include "BST.h"

using namespace std;

int main()
{
    BST tree;
    int num;

    cout << "\nOriginal List (in order of insertion): ";

    for (int i = 0; i < 40; i++)
    {
        num = rand() % 100 + 1;
        cout << num << " ";
        tree.insertNode(num);
    }

    cout << "\n\nInorder Traversal: ";
    tree.inorder();

    cout << "\n\nEnter number to delete from tree: ";
    cin >> num;

    while (!(tree.search(num)))
    {
        cout << "\nNumber entered is not in tree. Enter again: ";
        cin >> num;
    }

    tree.remove(num);

    cout << "\nUpdated Tree (Postorder Traversal): ";
    tree.postorder();

    if (tree.isAVL()) cout << "\n\nThis tree is an AVL Tree.";
    
    else cout << "\n\nThis tree is not an AVL Tree.";

    tree.destroy();

    cout << endl;

    return 0;
}