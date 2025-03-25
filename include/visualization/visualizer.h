#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>
#include <string>
#include "data_structures/linked_list.h"
#include "data_structures/binary_search_tree.h"
#include "data_structures/hash_table.h"
#include "algorithms/sorting/sorting.h"
#include "algorithms/searching/searching.h"

enum class SortAlgorithm
{
    BUBBLE,
    SELECTION,
    INSERTION,
    MERGE,
    QUICK
};

enum class SearchAlgorithm
{
    LINEAR,
    BINARY
};

class Visualizer
{
public:
    Visualizer();
    ~Visualizer();

    // Data Structure Visualization
    void visualizeLinkedList(const LinkedList &list, int highlightValue = -1);
    void visualizeBST(const BinarySearchTree &tree, int highlightValue = -1);
    void visualizeHashTable(const HashTable &table, int highlightKey = -1);

    // Algorithm Visualization
    void visualizeArray(const std::vector<int> &array, const std::string &title);
    void visualizeSorting(SortingAlgorithms &sorter, SortAlgorithm algorithm);
    void visualizeSearching(SearchingAlgorithms &searcher, SearchAlgorithm algorithm, int target);

private:
    // Utility methods for visualization
    void clearScreen();
    void printBoxedValue(int value, bool highlight = false);
    void printTreeNode(int value, bool highlight = false);
    void printArrow();
    void printHorizontalLine(int length);
    void delay(int milliseconds);

    // Terminal colors
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string BLUE = "\033[34m";
    const std::string YELLOW = "\033[33m";
};

#endif // VISUALIZER_H