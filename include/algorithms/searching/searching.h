#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include <functional>
#include <random>
#include <algorithm>

class SearchingAlgorithms
{
public:
    SearchingAlgorithms();
    ~SearchingAlgorithms();

    // Algorithm implementations
    int linearSearch(int target, std::function<void(const std::vector<int> &, int, bool)> visualCallback = nullptr);
    int binarySearch(int target, std::function<void(const std::vector<int> &, int, bool)> visualCallback = nullptr);

    // Utility methods
    void generateSortedArray(int size, int minVal = 1, int maxVal = 100);
    const std::vector<int> &getArray() const;

private:
    std::vector<int> array;
    std::mt19937 rng;

    // Helper methods
    int binarySearchRecursive(const std::vector<int> &arr, int left, int right, int target,
                              std::function<void(const std::vector<int> &, int, bool)> visualCallback);
};

#endif // SEARCHING_H
