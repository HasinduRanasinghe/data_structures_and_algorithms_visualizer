#include "../../include/data_structures/binary_search_tree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

void BinarySearchTree::insert(int value)
{
    root = insertRecursive(root, value);
}

TreeNode *BinarySearchTree::insertRecursive(TreeNode *node, int value)
{
    if (node == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < node->data)
    {
        node->left = insertRecursive(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinarySearchTree::remove(int value)
{
    root = removeRecursive(root, value);
}

TreeNode *BinarySearchTree::removeRecursive(TreeNode *node, int value)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (value < node->data)
    {
        node->left = removeRecursive(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = removeRecursive(node->right, value);
    }
    else
    {
        // Node with only one child or no child
        if (node->left == nullptr)
        {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children
        TreeNode *temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeRecursive(node->right, temp->data);
    }

    return node;
}

TreeNode *BinarySearchTree::findMin(TreeNode *node) const
{
    TreeNode *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

bool BinarySearchTree::search(int value) const
{
    return searchRecursive(root, value);
}

bool BinarySearchTree::searchRecursive(TreeNode *node, int value) const
{
    if (node == nullptr)
    {
        return false;
    }

    if (value == node->data)
    {
        return true;
    }

    if (value < node->data)
    {
        return searchRecursive(node->left, value);
    }
    else
    {
        return searchRecursive(node->right, value);
    }
}

bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

void BinarySearchTree::clear()
{
    clearRecursive(root);
    root = nullptr;
}

void BinarySearchTree::clearRecursive(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    clearRecursive(node->left);
    clearRecursive(node->right);
    delete node;
}

void BinarySearchTree::inOrderTraversal() const
{
    inOrderTraversalRecursive(root);
}

void BinarySearchTree::inOrderTraversalRecursive(TreeNode *node) const
{
    if (node == nullptr)
    {
        return;
    }

    inOrderTraversalRecursive(node->left);
    std::cout << node->data << " ";
    inOrderTraversalRecursive(node->right);
}

void BinarySearchTree::preOrderTraversal() const
{
    preOrderTraversalRecursive(root);
}

void BinarySearchTree::preOrderTraversalRecursive(TreeNode *node) const
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->data << " ";
    preOrderTraversalRecursive(node->left);
    preOrderTraversalRecursive(node->right);
}

void BinarySearchTree::postOrderTraversal() const
{
    postOrderTraversalRecursive(root);
}

void BinarySearchTree::postOrderTraversalRecursive(TreeNode *node) const
{
    if (node == nullptr)
    {
        return;
    }

    postOrderTraversalRecursive(node->left);
    postOrderTraversalRecursive(node->right);
    std::cout << node->data << " ";
}

TreeNode *BinarySearchTree::getRoot() const
{
    return root;
}