// #include "test_code.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <list>

using namespace std;

class LRUCache{
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        current_capacity = 0;
        keys.resize(capacity);
    }

    int get(int key) {
        got = cache.find(key);
        if (got != cache.end()) {
            //move key to front
            move2Front(got);
            //return value
            return got->second.first;
        }
        return -1;
    }

    void set(int key, int value) {
        got = cache.find(key);
        if (got != cache.end()) {
            //move key to frond
            move2Front(got);
            //set value
            got->second.first = value;
        } else {
            if (current_capacity == capacity) {
                cache.erase(keys.back());
                keys.pop_back();
                capacity--;
            }
            //add key to list
            keys.push_front(key);
            //add to cache
            cache.insert({key,{value, keys.begin()}});
            capacity++;
        }
    }

    void move2Front(unordered_map<int, pair<int, list<int>::iterator>>::iterator got) {
        keys.erase(got->second.second);
        keys.insert(keys.begin(), got->first);
        got->second.second = keys.begin();
    }
private:
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int capacity;
    int current_capacity;
    unordered_map<int, pair<int, list<int>::iterator>>::iterator got;
};