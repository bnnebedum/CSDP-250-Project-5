// Bede Nnebedum
// CSDP 250 - Fall 2023
// Project 5
// CPP File

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

TreeNode *createNode(int VALUE)
{
    TreeNode *newNode = new TreeNode;

    newNode -> value = VALUE;

    return newNode;
}

TreeNode *insert(TreeNode *root, int VALUE)
{
    if (!root) root = createNode(VALUE);

    else if (VALUE > root -> value) root -> rightNext = insert(root -> rightNext, VALUE);

    else root -> leftNext = insert(root -> leftNext, VALUE);

    return root;
}

void displayInorder(TreeNode *node)
{
    if (!node) return;

    displayInorder(node -> leftNext);

    cout << node -> value << " ";

    displayInorder(node -> rightNext);
}

void displayPostorder(TreeNode *node)
{
    if (!node) return;

    displayPostorder(node -> leftNext);

    displayPostorder(node -> rightNext);

    cout << node -> value << " ";
}

TreeNode* search(TreeNode* root, int value)
{
    if (root == NULL || root->value == value) return root;
 
    if (root->value < value) return search(root->rightNext, value);
 
    return search(root->leftNext, value);
}

TreeNode *deleteNode(TreeNode *root, int VALUE)
{
    if (root == NULL) return root;
    
    if (root->value > VALUE) 
    {
        root->leftNext = deleteNode(root->leftNext, VALUE);
        return root;
    }
    else if (root->value < VALUE) 
    {
        root->rightNext = deleteNode(root->rightNext, VALUE);
        return root;
    }
    
    if (root->leftNext == NULL) 
    {
        TreeNode* temp = root->rightNext;
        delete root;
        return temp;
    }
    else if (root->rightNext == NULL) {
        TreeNode* temp = root->leftNext;
        delete root;
        return temp;
    }
    
    else {
    
        TreeNode* succParent = root;
    
        TreeNode* succ = root->rightNext;
        while (succ->leftNext != NULL) {
            succParent = succ;
            succ = succ->leftNext;
        }
    
        if (succParent != root) succParent->leftNext = succ->rightNext;
        else succParent->rightNext = succ->rightNext;
    
        root -> value = succ -> value;
    
        delete succ;
        return root;
    }
}

int height(TreeNode* node)
{
    if (node == NULL) return 0;
 
    return 1 + max(height(node->leftNext), height(node->rightNext));
}
 
bool isBalanced(TreeNode* root)
{
    if (root == NULL) return 1;
 
    int leftHeight = height(root->leftNext);
    int rightHeight = height(root->rightNext);
 
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->leftNext) && isBalanced(root->rightNext)) return true;
 
    return false;
}

void destroyTree(TreeNode* node) 
{ 
    if (node == NULL) return; 

    destroyTree(node->leftNext); 
    destroyTree(node->rightNext); 
    
    delete node;
} 