#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    void remove(int value);
    bool search(int value) const;
    bool isEmpty() const;
    void clear();

    // For visualization purposes
    Node *getHead() const;

private:
    Node *head;
};

#endif // LINKED_LIST_H
