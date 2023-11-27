// Bede Nnebedum
// CSDP 250 - Fall 2023
// Project 5
// Header File

#ifndef BST_h
#define BST_h

struct TreeNode
{
    int value;
    TreeNode *rightNext;
    TreeNode *leftNext;
};

class BST
{
private:
    TreeNode *root;

    TreeNode *createNode(int);
    TreeNode *insert(TreeNode *, int);
    TreeNode *deleteNode(TreeNode *, int);
    TreeNode *searchTree(TreeNode *, int);
    void displayInorder(TreeNode *);
    void displayPostorder(TreeNode *);
    int height(TreeNode *);
    bool isBalanced(TreeNode *);
    void destroyTree(TreeNode *);

public:
    BST() { root = nullptr; }
    ~BST() {}

    void insertNode(int value)
    {
        root = insert(root, value);
    }

    void inorder()
    {
        displayInorder(root);
    }

    void postorder()
    {
        displayPostorder(root);
    }

    bool search(int value)
    {
        if (!searchTree(root, value)) return false;

        return true;
    }

    void remove(int value)
    {
        root = deleteNode(root, value);
    }

    bool isAVL()
    {
        return isBalanced(root);
    }

    void destroy()
    {
        destroyTree(root);
    }
};

#endif