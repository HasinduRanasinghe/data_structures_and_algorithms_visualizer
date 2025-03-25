#include "../../../include/algorithms/sorting/sorting.h"
#include <iostream>
#include <chrono>

SortingAlgorithms::SortingAlgorithms() : rng(std::chrono::steady_clock::now().time_since_epoch().count())
{
    // Initialize with a small sample array
    generateRandomArray(10);
}

SortingAlgorithms::~SortingAlgorithms()
{
    // Cleanup
}

void SortingAlgorithms::generateRandomArray(int size, int minVal, int maxVal)
{
    array.resize(size);
    std::uniform_int_distribution<int> dist(minVal, maxVal);

    for (int i = 0; i < size; i++)
    {
        array[i] = dist(rng);
    }
}

const std::vector<int> &SortingAlgorithms::getArray() const
{
    return array;
}

// Bubble Sort Implementation
void SortingAlgorithms::bubbleSort(std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    std::vector<int> arr = array;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (visualCallback)
            {
                visualCallback(arr, j, j + 1);
            }

            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);

                if (visualCallback)
                {
                    visualCallback(arr, j, j + 1);
                }
            }
        }
    }

    array = arr;
}

// Selection Sort Implementation
void SortingAlgorithms::selectionSort(std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    std::vector<int> arr = array;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (visualCallback)
            {
                visualCallback(arr, min_idx, j);
            }

            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            std::swap(arr[i], arr[min_idx]);

            if (visualCallback)
            {
                visualCallback(arr, i, min_idx);
            }
        }
    }

    array = arr;
}

// Insertion Sort Implementation
void SortingAlgorithms::insertionSort(std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    std::vector<int> arr = array;
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            if (visualCallback)
            {
                visualCallback(arr, j, i);
            }

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        if (visualCallback)
        {
            visualCallback(arr, j + 1, i);
        }
    }

    array = arr;
}

// Merge Sort Implementation
void SortingAlgorithms::mergeSort(std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    std::vector<int> arr = array;
    mergeSortRecursive(arr, 0, arr.size() - 1, visualCallback);
    array = arr;
}

void SortingAlgorithms::mergeSortRecursive(std::vector<int> &arr, int left, int right, std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid, visualCallback);
        mergeSortRecursive(arr, mid + 1, right, visualCallback);

        merge(arr, left, mid, right, visualCallback);
    }
}

void SortingAlgorithms::merge(std::vector<int> &arr, int left, int mid, int right, std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (visualCallback)
        {
            visualCallback(arr, left + i, mid + 1 + j);
        }

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    if (visualCallback)
    {
        visualCallback(arr, left, right);
    }
}

// Quick Sort Implementation
void SortingAlgorithms::quickSort(std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    std::vector<int> arr = array;
    quickSortRecursive(arr, 0, arr.size() - 1, visualCallback);
    array = arr;
}

void SortingAlgorithms::quickSortRecursive(std::vector<int> &arr, int low, int high, std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, visualCallback);

        quickSortRecursive(arr, low, pi - 1, visualCallback);
        quickSortRecursive(arr, pi + 1, high, visualCallback);
    }
}

int SortingAlgorithms::partition(std::vector<int> &arr, int low, int high, std::function<void(const std::vector<int> &, int, int)> visualCallback)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (visualCallback)
        {
            visualCallback(arr, j, high);
        }

        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);

            if (visualCallback)
            {
                visualCallback(arr, i, j);
            }
        }
    }

    std::swap(arr[i + 1], arr[high]);

    if (visualCallback)
    {
        visualCallback(arr, i + 1, high);
    }

    return i + 1;
}