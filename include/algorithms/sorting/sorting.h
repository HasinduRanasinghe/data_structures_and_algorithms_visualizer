#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <functional>
#include <random>
#include <algorithm>

class SortingAlgorithms
{
public:
    SortingAlgorithms();
    ~SortingAlgorithms();

    // Algorithm implementations
    void bubbleSort(std::function<void(const std::vector<int> &, int, int)> visualCallback = nullptr);
    void selectionSort(std::function<void(const std::vector<int> &, int, int)> visualCallback = nullptr);
    void insertionSort(std::function<void(const std::vector<int> &, int, int)> visualCallback = nullptr);
    void mergeSort(std::function<void(const std::vector<int> &, int, int)> visualCallback = nullptr);
    void quickSort(std::function<void(const std::vector<int> &, int, int)> visualCallback = nullptr);

    // Utility methods
    void generateRandomArray(int size, int minVal = 1, int maxVal = 100);
    const std::vector<int> &getArray() const;

private:
    std::vector<int> array;
    std::mt19937 rng;

    // Helper methods for recursive sorts
    void mergeSortRecursive(std::vector<int> &arr, int left, int right, std::function<void(const std::vector<int> &, int, int)> visualCallback);
    void merge(std::vector<int> &arr, int left, int mid, int right, std::function<void(const std::vector<int> &, int, int)> visualCallback);

    void quickSortRecursive(std::vector<int> &arr, int low, int high, std::function<void(const std::vector<int> &, int, int)> visualCallback);
    int partition(std::vector<int> &arr, int low, int high, std::function<void(const std::vector<int> &, int, int)> visualCallback);
};

#endif // SORTING_H
