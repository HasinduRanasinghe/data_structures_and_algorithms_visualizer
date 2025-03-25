#include "../../include/data_structures/hash_table.h"

HashTable::HashTable(int size) : size(size), count(0)
{
    buckets.resize(size);
}

HashTable::~HashTable()
{
    clear();
}

int HashTable::hash(int key) const
{
    return key % size;
}

void HashTable::insert(int key, int value)
{
    int index = hash(key);

    // Check if key already exists
    for (auto &pair : buckets[index])
    {
        if (pair.first == key)
        {
            pair.second = value; // Update value
            return;
        }
    }

    // Insert new key-value pair
    buckets[index].push_back(std::make_pair(key, value));
    count++;

    // Check if rehashing is needed
    if (getLoadFactor() > 0.7)
    {
        rehash();
    }
}

void HashTable::remove(int key)
{
    int index = hash(key);

    auto &bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it)
    {
        if (it->first == key)
        {
            bucket.erase(it);
            count--;
            return;
        }
    }
}

int HashTable::search(int key) const
{
    int index = hash(key);

    for (const auto &pair : buckets[index])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }

    return -1; // Key not found
}

bool HashTable::isEmpty() const
{
    return count == 0;
}

void HashTable::clear()
{
    for (auto &bucket : buckets)
    {
        bucket.clear();
    }
    count = 0;
}

int HashTable::getSize() const
{
    return size;
}

float HashTable::getLoadFactor() const
{
    return static_cast<float>(count) / size;
}

const std::vector<std::list<std::pair<int, int>>> &HashTable::getBuckets() const
{
    return buckets;
}

void HashTable::rehash()
{
    std::vector<std::list<std::pair<int, int>>> oldBuckets = buckets;
    int oldSize = size;

    // Resize the hash table
    size = size * 2;
    buckets.clear();
    buckets.resize(size);
    count = 0;

    // Reinsert all elements
    for (int i = 0; i < oldSize; i++)
    {
        for (const auto &pair : oldBuckets[i])
        {
            insert(pair.first, pair.second);
        }
    }
}