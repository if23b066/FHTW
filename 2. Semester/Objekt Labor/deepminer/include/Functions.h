#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

template <typename T>
bool isSorted(std::vector<T> values)
{
    return std::is_sorted(values.begin(), values.end());
}

template <typename T>
void sort(std::vector<T> &values, bool ascending)
{
    if (ascending)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else
    {
        std::sort(values.begin(), values.end(), std::greater<T>());
    }
}

template <typename T>
void removeAtIndex(std::vector<T> &values, int index)
{
    values.erase(values.begin() + index);
}

template <typename T>
void shuffle(std::vector<T> &values)
{
    std::shuffle(values.begin(), values.end(), std::mt19937(std::random_device()()));
}

template <typename T>
void otherSort(std::vector<T> &values)
{
    std::sort(values.begin(), values.end(), [](T a, T b)
              { return a == 0 && b != 0; });
}

#endif // FUNCTIONS_H
