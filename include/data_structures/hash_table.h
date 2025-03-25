#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <list>
#include <utility>

class HashTable
{
public:
    HashTable(int size = 10);
    ~HashTable();

    void insert(int key, int value);
    void remove(int key);
    int search(int key) const;
    bool isEmpty() const;
    void clear();

    // For visualization purposes
    int getSize() const;
    float getLoadFactor() const;
    const std::vector<std::list<std::pair<int, int>>> &getBuckets() const;

private:
    std::vector<std::list<std::pair<int, int>>> buckets;
    int size;
    int count;

    int hash(int key) const;
    void rehash();
};

#endif // HASH_TABLE_H
