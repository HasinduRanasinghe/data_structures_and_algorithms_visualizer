#include "../../include/visualization/visualizer.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <queue>

Visualizer::Visualizer()
{
    // Initialize visualizer
}

Visualizer::~Visualizer()
{
    // Cleanup
}

void Visualizer::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Visualizer::delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Visualizer::printBoxedValue(int value, bool highlight)
{
    std::string color = highlight ? GREEN : RESET;
    std::cout << color << "┌───┐" << RESET << std::endl;
    std::cout << color << "│ " << std::setw(1) << value << " │" << RESET << std::endl;
    std::cout << color << "└───┘" << RESET << std::endl;
}

void Visualizer::printTreeNode(int value, bool highlight)
{
    std::string color = highlight ? GREEN : RESET;
    std::cout << color << "(" << value << ")" << RESET;
}

void Visualizer::printArrow()
{
    std::cout << " --> ";
}

void Visualizer::printHorizontalLine(int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void Visualizer::visualizeLinkedList(const LinkedList &list, int highlightValue)
{
    clearScreen();
    std::cout << "\n=== LINKED LIST VISUALIZATION ===\n\n";

    if (list.isEmpty())
    {
        std::cout << "Empty List\n";
        return;
    }

    Node *current = list.getHead();
    std::cout << "HEAD";
    while (current != nullptr)
    {
        printArrow();
        bool highlight = (current->data == highlightValue);
        std::cout << (highlight ? GREEN : RESET) << "[" << current->data << "]" << RESET;
        current = current->next;
    }
    std::cout << " --> NULL\n\n";

    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Visualizer::visualizeBST(const BinarySearchTree &tree, int highlightValue)
{
    clearScreen();
    std::cout << "\n=== BINARY SEARCH TREE VISUALIZATION ===\n\n";

    if (tree.isEmpty())
    {
        std::cout << "Empty Tree\n";
        return;
    }

    // Simplified visualization - in a real app, you'd want a more graphical representation
    // Level-order traversal for a basic tree display
    std::queue<TreeNode *> queue;
    queue.push(tree.getRoot());

    int level = 0;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;

    std::cout << "Level " << level << ": ";

    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();

        if (current)
        {
            bool highlight = (current->data == highlightValue);
            std::cout << (highlight ? GREEN : RESET) << current->data << RESET << " ";

            queue.push(current->left);
            queue.push(current->right);
            nodesInNextLevel += 2;
        }
        else
        {
            std::cout << "- ";
            queue.push(nullptr);
            queue.push(nullptr);
            nodesInNextLevel += 2;
        }

        nodesInCurrentLevel--;

        if (nodesInCurrentLevel == 0)
        {
            std::cout << std::endl;
            level++;

            // Stop after a reasonable number of levels to avoid excessive outputs
            if (level > 5)
            {
                std::cout << "... (more levels not shown)\n";
                break;
            }

            nodesInCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;

            if (nodesInCurrentLevel > 0)
            {
                std::cout << "Level " << level << ": ";
            }
        }
    }

    std::cout << "\n\nIn-order traversal: ";
    tree.inOrderTraversal();
    std::cout << std::endl;

    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Visualizer::visualizeHashTable(const HashTable &table, int highlightKey)
{
    clearScreen();
    std::cout << "\n=== HASH TABLE VISUALIZATION ===\n\n";

    if (table.isEmpty())
    {
        std::cout << "Empty Hash Table\n";
        return;
    }

    const auto &buckets = table.getBuckets();
    const int size = table.getSize();

    std::cout << "Table Size: " << size << std::endl;
    std::cout << "Load Factor: " << table.getLoadFactor() << std::endl
              << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << "Bucket[" << i << "]: ";

        if (buckets[i].empty())
        {
            std::cout << "Empty\n";
            continue;
        }

        for (const auto &entry : buckets[i])
        {
            bool highlight = (entry.first == highlightKey);
            std::cout << (highlight ? GREEN : RESET) << "[" << entry.first << ":" << entry.second << "]" << RESET;
            std::cout << " -> ";
        }
        std::cout << "NULL\n";
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Visualizer::visualizeArray(const std::vector<int> &array, const std::string &title)
{
    clearScreen();
    std::cout << "\n=== " << title << " ===\n\n";

    if (array.empty())
    {
        std::cout << "Empty Array\n";
        return;
    }

    std::cout << "[ ";
    for (const auto &value : array)
    {
        std::cout << value << " ";
    }
    std::cout << "]\n\n";

    std::cout << "Array Size: " << array.size() << std::endl;

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Visualizer::visualizeSorting(SortingAlgorithms &sorter, SortAlgorithm algorithm)
{
    if (sorter.getArray().empty())
    {
        std::cout << "Array is empty. Generate an array first.\n";
        return;
    }

    std::string algorithmName;

    switch (algorithm)
    {
    case SortAlgorithm::BUBBLE:
        algorithmName = "Bubble Sort";
        break;
    case SortAlgorithm::SELECTION:
        algorithmName = "Selection Sort";
        break;
    case SortAlgorithm::INSERTION:
        algorithmName = "Insertion Sort";
        break;
    case SortAlgorithm::MERGE:
        algorithmName = "Merge Sort";
        break;
    case SortAlgorithm::QUICK:
        algorithmName = "Quick Sort";
        break;
    }

    // Create a copy of the array for visualization
    std::vector<int> arrayCopy = sorter.getArray();

    clearScreen();
    std::cout << "\n=== " << algorithmName << " VISUALIZATION ===\n\n";

    std::cout << "Original Array: [ ";
    for (const auto &value : arrayCopy)
    {
        std::cout << value << " ";
    }
    std::cout << "]\n\n";

    // Set up the visualization callback
    auto visualCallback = [&](const std::vector<int> &arr, int i, int j)
    {
        std::cout << "[ ";
        for (size_t k = 0; k < arr.size(); k++)
        {
            if (k == static_cast<size_t>(i))
            {
                std::cout << RED << arr[k] << RESET << " ";
            }
            else if (k == static_cast<size_t>(j))
            {
                std::cout << BLUE << arr[k] << RESET << " ";
            }
            else
            {
                std::cout << arr[k] << " ";
            }
        }
        std::cout << "]\r";
        std::cout.flush();
        delay(200); // Adjust speed here
    };

    // Perform sorting with visualization
    switch (algorithm)
    {
    case SortAlgorithm::BUBBLE:
        sorter.bubbleSort(visualCallback);
        break;
    case SortAlgorithm::SELECTION:
        sorter.selectionSort(visualCallback);
        break;
    case SortAlgorithm::INSERTION:
        sorter.insertionSort(visualCallback);
        break;
    case SortAlgorithm::MERGE:
        sorter.mergeSort(visualCallback);
        break;
    case SortAlgorithm::QUICK:
        sorter.quickSort(visualCallback);
        break;
    }

    std::cout << "\n\nSorted Array: [ ";
    for (const auto &value : sorter.getArray())
    {
        std::cout << value << " ";
    }
    std::cout << "]\n\n";

    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Visualizer::visualizeSearching(SearchingAlgorithms &searcher, SearchAlgorithm algorithm, int target)
{
    if (searcher.getArray().empty())
    {
        std::cout << "Array is empty. Generate an array first.\n";
        return;
    }

    std::string algorithmName;
    bool found = false;
    int foundIndex = -1;

    switch (algorithm)
    {
    case SearchAlgorithm::LINEAR:
        algorithmName = "Linear Search";
        break;
    case SearchAlgorithm::BINARY:
        algorithmName = "Binary Search";
        break;
    }

    clearScreen();
    std::cout << "\n=== " << algorithmName << " VISUALIZATION ===\n\n";

    std::cout << "Array: [ ";
    for (const auto &value : searcher.getArray())
    {
        std::cout << value << " ";
    }
    std::cout << "]\n\n";

    std::cout << "Searching for: " << target << "\n\n";

    // Set up the visualization callback
    auto visualCallback = [&](const std::vector<int> &arr, int index, bool isFound)
    {
        std::cout << "[ ";
        for (size_t k = 0; k < arr.size(); k++)
        {
            if (k == static_cast<size_t>(index))
            {
                std::cout << (isFound ? GREEN : YELLOW) << arr[k] << RESET << " ";
            }
            else
            {
                std::cout << arr[k] << " ";
            }
        }
        std::cout << "]\r";
        std::cout.flush();
        delay(300); // Adjust speed here
        found = isFound;
        if (isFound)
        {
            foundIndex = index;
        }
    };

    // Perform searching with visualization
    switch (algorithm)
    {
    case SearchAlgorithm::LINEAR:
        searcher.linearSearch(target, visualCallback);
        break;
    case SearchAlgorithm::BINARY:
        searcher.binarySearch(target, visualCallback);
        break;
    }

    std::cout << "\n\n";
    if (found)
    {
        std::cout << GREEN << "Target " << target << " found at index " << foundIndex << "!" << RESET << "\n";
    }
    else
    {
        std::cout << RED << "Target " << target << " not found in the array." << RESET << "\n";
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}