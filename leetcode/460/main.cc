#include <unordered_map>
#include <string>
#include <iostream>
#include <list>

using namespace std;

struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};

class LFUCache {
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        if (key_table.find(key) == key_table.end()) {
            return -1;
        } else {
            auto it = key_table[key];
            int freq = it->freq;
            int value = it->val;
            freq_table[freq].erase(it);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (freq == minfreq) minfreq = minfreq + 1;
            }
            freq_table[freq+1].push_front(Node(key , value, freq+1));
            key_table[key] = freq_table[freq+1].begin();
            return value;
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        // 第一步： key_table 中是否可以查到
        if (key_table.find(key) == key_table.end()) {
            // 清理最旧的元素
            if (capacity == key_table.size()) {
                std::cout << "key: " << key << std::endl;
                auto it = freq_table[minfreq].back();
                std::cout << "del key: " << it.key << std::endl;
                key_table.erase(it.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            auto it = key_table[key];
            int freq = it->freq;
            freq_table[freq].erase(it);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (freq == minfreq) minfreq = minfreq + 1;
            }
            freq_table[freq+1].push_front(Node(key , value, freq+1));
            key_table[key] = freq_table[freq+1].begin();
        }

    }

private:
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
};

int main() {
    int capacity = 0;
    LFUCache* obj = new LFUCache(capacity);
    obj->put(0, 0);
    std::cout << "0: " << obj->get(0) << std::endl;
    /*
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
    */

    return 0;
} 