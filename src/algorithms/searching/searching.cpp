#include "../../../include/algorithms/searching/searching.h"
#include <iostream>
#include <chrono>

SearchingAlgorithms::SearchingAlgorithms() : rng(std::chrono::steady_clock::now().time_since_epoch().count())
{
    // Initialize with a small sample array
    generateSortedArray(10);
}

SearchingAlgorithms::~SearchingAlgorithms()
{
    // Cleanup
}

void SearchingAlgorithms::generateSortedArray(int size, int minVal, int maxVal)
{
    array.resize(size);
    std::uniform_int_distribution<int> dist(minVal, maxVal);

    for (int i = 0; i < size; i++)
    {
        array[i] = dist(rng);
    }

    std::sort(array.begin(), array.end());
}

const std::vector<int> &SearchingAlgorithms::getArray() const
{
    return array;
}

// Linear Search Implementation
int SearchingAlgorithms::linearSearch(int target, std::function<void(const std::vector<int> &, int, bool)> visualCallback)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        if (visualCallback)
        {
            visualCallback(array, i, array[i] == target);
        }

        if (array[i] == target)
        {
            return i;
        }
    }

    return -1; // Not found
}

// Binary Search Implementation
int SearchingAlgorithms::binarySearch(int target, std::function<void(const std::vector<int> &, int, bool)> visualCallback)
{
    return binarySearchRecursive(array, 0, array.size() - 1, target, visualCallback);
}

int SearchingAlgorithms::binarySearchRecursive(const std::vector<int> &arr, int left, int right, int target,
                                               std::function<void(const std::vector<int> &, int, bool)> visualCallback)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (visualCallback)
        {
            visualCallback(arr, mid, arr[mid] == target);
        }

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            return binarySearchRecursive(arr, left, mid - 1, target, visualCallback);
        }

        return binarySearchRecursive(arr, mid + 1, right, target, visualCallback);
    }

    return -1; // Not found
}