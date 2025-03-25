#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    void remove(int value);
    bool search(int value) const;
    bool isEmpty() const;
    void clear();

    // Traversals
    void inOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;

    // For visualization purposes
    TreeNode *getRoot() const;

private:
    TreeNode *root;

    // Helper methods
    TreeNode *insertRecursive(TreeNode *node, int value);
    TreeNode *removeRecursive(TreeNode *node, int value);
    TreeNode *findMin(TreeNode *node) const;
    bool searchRecursive(TreeNode *node, int value) const;
    void clearRecursive(TreeNode *node);
    void inOrderTraversalRecursive(TreeNode *node) const;
    void preOrderTraversalRecursive(TreeNode *node) const;
    void postOrderTraversalRecursive(TreeNode *node) const;
};

#endif // BINARY_SEARCH_TREE_H