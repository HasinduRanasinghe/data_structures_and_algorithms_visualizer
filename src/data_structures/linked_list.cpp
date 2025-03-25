#include "../../include/data_structures/linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::insert(int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

void LinkedList::remove(int value)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data != value)
    {
        current = current->next;
    }

    if (current->next != nullptr)
    {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

bool LinkedList::search(int value) const
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

void LinkedList::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *LinkedList::getHead() const
{
    return head;
}