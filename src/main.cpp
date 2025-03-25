#include <iostream>
#include <string>
#include <memory>
#include "../include/visualization/visualizer.h"
#include "../include/data_structures/linked_list.h"
#include "../include/data_structures/binary_search_tree.h"
#include "../include/data_structures/hash_table.h"
#include "../include/algorithms/sorting/sorting.h"
#include "../include/algorithms/searching/searching.h"

void displayMenu()
{
    std::cout << "\n===== DATA STRUCTURES AND ALGORITHMS VISUALIZER =====\n";
    std::cout << "1. Linked List Visualization\n";
    std::cout << "2. Binary Search Tree Visualization\n";
    std::cout << "3. Hash Table Visualization\n";
    std::cout << "4. Sorting Algorithms Visualization\n";
    std::cout << "5. Searching Algorithms Visualization\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    std::unique_ptr<Visualizer> visualizer = std::make_unique<Visualizer>();
    std::unique_ptr<LinkedList> linkedList = std::make_unique<LinkedList>();
    std::unique_ptr<BinarySearchTree> bst = std::make_unique<BinarySearchTree>();
    std::unique_ptr<HashTable> hashTable = std::make_unique<HashTable>();
    std::unique_ptr<SortingAlgorithms> sortAlgo = std::make_unique<SortingAlgorithms>();
    std::unique_ptr<SearchingAlgorithms> searchAlgo = std::make_unique<SearchingAlgorithms>();

    int choice = -1;

    while (choice != 0)
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int linkedListOption = -1;
            while (linkedListOption != 0)
            {
                std::cout << "\n--- Linked List Operations ---\n";
                std::cout << "1. Insert Node\n";
                std::cout << "2. Delete Node\n";
                std::cout << "3. Search Node\n";
                std::cout << "4. Display List\n";
                std::cout << "0. Back to Main Menu\n";
                std::cout << "Enter your choice: ";
                std::cin >> linkedListOption;

                switch (linkedListOption)
                {
                case 1:
                {
                    int value;
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    linkedList->insert(value);
                    visualizer->visualizeLinkedList(*linkedList);
                    break;
                }
                case 2:
                {
                    int value;
                    std::cout << "Enter value to delete: ";
                    std::cin >> value;
                    linkedList->remove(value);
                    visualizer->visualizeLinkedList(*linkedList);
                    break;
                }
                case 3:
                {
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    bool found = linkedList->search(value);
                    std::cout << "Value " << value << (found ? " found!" : " not found!") << std::endl;
                    visualizer->visualizeLinkedList(*linkedList, found ? value : -1);
                    break;
                }
                case 4:
                    visualizer->visualizeLinkedList(*linkedList);
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Invalid option!\n";
                }
            }
            break;
        }
        case 2:
        {
            int bstOption = -1;
            while (bstOption != 0)
            {
                std::cout << "\n--- Binary Search Tree Operations ---\n";
                std::cout << "1. Insert Node\n";
                std::cout << "2. Delete Node\n";
                std::cout << "3. Search Node\n";
                std::cout << "4. Display Tree\n";
                std::cout << "5. Traversals (In-order, Pre-order, Post-order)\n";
                std::cout << "0. Back to Main Menu\n";
                std::cout << "Enter your choice: ";
                std::cin >> bstOption;

                switch (bstOption)
                {
                case 1:
                {
                    int value;
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    bst->insert(value);
                    visualizer->visualizeBST(*bst);
                    break;
                }
                case 2:
                {
                    int value;
                    std::cout << "Enter value to delete: ";
                    std::cin >> value;
                    bst->remove(value);
                    visualizer->visualizeBST(*bst);
                    break;
                }
                case 3:
                {
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    bool found = bst->search(value);
                    std::cout << "Value " << value << (found ? " found!" : " not found!") << std::endl;
                    visualizer->visualizeBST(*bst, found ? value : -1);
                    break;
                }
                case 4:
                    visualizer->visualizeBST(*bst);
                    break;
                case 5:
                {
                    std::cout << "In-order traversal: ";
                    bst->inOrderTraversal();
                    std::cout << "\nPre-order traversal: ";
                    bst->preOrderTraversal();
                    std::cout << "\nPost-order traversal: ";
                    bst->postOrderTraversal();
                    std::cout << std::endl;
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Invalid option!\n";
                }
            }
            break;
        }
        case 3:
        {
            int hashTableOption = -1;
            while (hashTableOption != 0)
            {
                std::cout << "\n--- Hash Table Operations ---\n";
                std::cout << "1. Insert Key-Value\n";
                std::cout << "2. Delete Key\n";
                std::cout << "3. Search Key\n";
                std::cout << "4. Display Hash Table\n";
                std::cout << "0. Back to Main Menu\n";
                std::cout << "Enter your choice: ";
                std::cin >> hashTableOption;

                switch (hashTableOption)
                {
                case 1:
                {
                    int key, value;
                    std::cout << "Enter key: ";
                    std::cin >> key;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    hashTable->insert(key, value);
                    visualizer->visualizeHashTable(*hashTable);
                    break;
                }
                case 2:
                {
                    int key;
                    std::cout << "Enter key to delete: ";
                    std::cin >> key;
                    hashTable->remove(key);
                    visualizer->visualizeHashTable(*hashTable);
                    break;
                }
                case 3:
                {
                    int key;
                    std::cout << "Enter key to search: ";
                    std::cin >> key;
                    int value = hashTable->search(key);
                    if (value != -1)
                    {
                        std::cout << "Key " << key << " found with value: " << value << std::endl;
                    }
                    else
                    {
                        std::cout << "Key " << key << " not found!" << std::endl;
                    }
                    visualizer->visualizeHashTable(*hashTable, key);
                    break;
                }
                case 4:
                    visualizer->visualizeHashTable(*hashTable);
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Invalid option!\n";
                }
            }
            break;
        }
        case 4:
        {
            int sortOption = -1;
            while (sortOption != 0)
            {
                std::cout << "\n--- Sorting Algorithms ---\n";
                std::cout << "1. Generate Random Array\n";
                std::cout << "2. Bubble Sort\n";
                std::cout << "3. Selection Sort\n";
                std::cout << "4. Insertion Sort\n";
                std::cout << "5. Merge Sort\n";
                std::cout << "6. Quick Sort\n";
                std::cout << "0. Back to Main Menu\n";
                std::cout << "Enter your choice: ";
                std::cin >> sortOption;

                switch (sortOption)
                {
                case 1:
                {
                    int size;
                    std::cout << "Enter array size: ";
                    std::cin >> size;
                    sortAlgo->generateRandomArray(size);
                    visualizer->visualizeArray(sortAlgo->getArray(), "Random Array");
                    break;
                }
                case 2:
                    visualizer->visualizeSorting(*sortAlgo, SortAlgorithm::BUBBLE);
                    break;
                case 3:
                    visualizer->visualizeSorting(*sortAlgo, SortAlgorithm::SELECTION);
                    break;
                case 4:
                    visualizer->visualizeSorting(*sortAlgo, SortAlgorithm::INSERTION);
                    break;
                case 5:
                    visualizer->visualizeSorting(*sortAlgo, SortAlgorithm::MERGE);
                    break;
                case 6:
                    visualizer->visualizeSorting(*sortAlgo, SortAlgorithm::QUICK);
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Invalid option!\n";
                }
            }
            break;
        }
        case 5:
        {
            int searchOption = -1;
            while (searchOption != 0)
            {
                std::cout << "\n--- Searching Algorithms ---\n";
                std::cout << "1. Generate Sorted Array\n";
                std::cout << "2. Linear Search\n";
                std::cout << "3. Binary Search\n";
                std::cout << "0. Back to Main Menu\n";
                std::cout << "Enter your choice: ";
                std::cin >> searchOption;

                switch (searchOption)
                {
                case 1:
                {
                    int size;
                    std::cout << "Enter array size: ";
                    std::cin >> size;
                    searchAlgo->generateSortedArray(size);
                    visualizer->visualizeArray(searchAlgo->getArray(), "Sorted Array");
                    break;
                }
                case 2:
                {
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    visualizer->visualizeSearching(*searchAlgo, SearchAlgorithm::LINEAR, value);
                    break;
                }
                case 3:
                {
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    visualizer->visualizeSearching(*searchAlgo, SearchAlgorithm::BINARY, value);
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Invalid option!\n";
                }
            }
            break;
        }
        case 0:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid option!\n";
        }
    }

    return 0;
}