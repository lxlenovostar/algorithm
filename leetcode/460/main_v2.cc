#include <unordered_map>
#include <string>
#include <iostream>
#include <list>
#include <set>

using namespace std;

struct Node {
    int key, val, freq, time;
    //Node() {}
    Node(int _key, int _val, int _freq, int _time): key(_key), val(_val), freq(_freq), time(_time){}

    bool operator < (const Node& rhs) const {
        return freq == rhs.freq ? time < rhs.time: freq < rhs.freq;
    }
};

class LFUCache {
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        key_table.clear();
        set_table.clear();
        time = 0;
    }
    
    int get(int key) {
        if (capacity == 0) return -1;

        if (key_table.find(key) == key_table.end()) {
            return -1;
        } else {
             // 这里和 get() 函数类似
            //Node cache = key_table[key];
            auto it = key_table.find(key);
            Node cache = it->second;
            set_table.erase(cache);
            cache.freq += 1;
            cache.time = ++time;
            set_table.insert(cache);
            it->second = cache;
            return cache.val ;
        }

    }
    
    void put(int key, int value) {
        if (capacity == 0) return ;

        if (key_table.find(key) == key_table.end()) {
            if (key_table.size() == capacity) {
                int key = set_table.begin()->key;
                key_table.erase(key);
                set_table.erase(set_table.begin());
            }
            Node cache = Node(key, value, 1, ++time);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(std::make_pair(key, cache));
            set_table.insert(cache);
        } else {
            // 这里和 get() 函数类似
            //Node cache = key_table[key];
            auto it = key_table.find(key);
            Node cache = it->second;
            set_table.erase(cache);
            cache.freq += 1;
            cache.time = ++time;
            cache.val = value;
            set_table.insert(cache);
            it->second = cache;
        }
    }

private:
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> set_table;
};

int main() {
    int capacity = 2;
    LFUCache* obj = new LFUCache(capacity);
    /*
    obj->put(0, 0);
    std::cout << "0: " << obj->get(0) << std::endl;
    */
    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << "1: " << obj->get(1) << std::endl;
    obj->put(3, 3);
    std::cout << "2: " << obj->get(2) << std::endl;
    std::cout << "3: " << obj->get(3) << std::endl;
    obj->put(4, 4);
    std::cout << "1: " << obj->get(1) << std::endl;
    std::cout << "3: " << obj->get(3) << std::endl;
    std::cout << "4: " << obj->get(4) << std::endl;

    return 0;
} 