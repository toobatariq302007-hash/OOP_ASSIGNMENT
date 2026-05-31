#ifndef SEARCH_UTILITY_H
#define SEARCH_UTILITY_H

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Template function for generic searching - works on any type
// Uses a predicate (condition function) to find matching items
template <typename T>
vector<T> searchItems(const vector<T>& items, function<bool(const T&)> condition) {
    vector<T> results;
    // Using STL algorithm: copy_if
    copy_if(items.begin(), items.end(), back_inserter(results), condition);
    return results;
}

// Template function: find a single item by condition
template <typename T>
T* findItem(vector<T>& items, function<bool(const T&)> condition) {
    // Using STL algorithm: find_if
    auto it = find_if(items.begin(), items.end(), condition);
    if (it != items.end()) {
        return &(*it);
    }
    return nullptr;
}

#endif
