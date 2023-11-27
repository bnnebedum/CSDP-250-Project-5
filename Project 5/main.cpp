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
    TreeNode *root = nullptr;
    int num;

    cout << "\nOriginal List (in order of insertion): ";

    for (int i = 0; i < 40; i++)
    {
        int num = rand() % 100 + 1;
        cout << num << " ";
        root = insert(root, num);
    }

    cout << "\n\nInorder Traversal: ";
    displayInorder(root);

    cout << "\n\nEnter number to delete from tree: ";
    cin >> num;

    while (!(search(root, num)))
    {
        cout << "\nNumber entered is not in tree. Enter again: ";
        cin >> num;
    }

    deleteNode(root, num);

    cout << "\nUpdated Tree (Postorder Traversal): ";
    displayPostorder(root);

    if (isBalanced(root))
        cout << "\n\nThis tree is an AVL Tree.";
    else
        cout << "\n\nThis tree is not an AVL Tree.";

    destroyTree(root);

    cout << endl;

    return 0;
}