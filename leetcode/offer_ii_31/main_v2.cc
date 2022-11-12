#include <queue>
#include <map>
#include <iostream>
#include <list>

using namespace std;

class LRUCache {
private:
    int m_capacity;
    std::map<int, std::pair<int, std::list<int>::iterator>> hash; // std::pair<value, pos>
    std::list<int> lru;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        //std::cout << "get: " << key << std::endl;

        int value = hash[key].first;
        std::list<int>::iterator pos = hash[key].second;
        lru.erase(pos);
        hash[key] = std::make_pair(value, lru.insert(lru.end(), key));

        return value;
    }
    
    void put(int key, int value) {
        //std::cout << "put key:" << key << " value: " << value << std::endl;

        if (hash.find(key) == hash.end()) {
            hash[key] = std::make_pair(value, lru.insert(lru.end(), key));
        } else {
            std::list<int>::iterator pos = hash[key].second;
            lru.erase(pos);
            hash[key] = std::make_pair(value, lru.insert(lru.end(), key));
        }

        if (lru.size() > m_capacity) {
            auto old_key = lru.front();
            lru.pop_front();
            hash.erase(old_key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 */
int main() {
 int capacity = 2;
 LRUCache* obj = new LRUCache(capacity);
 obj->put(1,1);
 obj->put(2,2);
 int param_1 = obj->get(1);
 std::cout << param_1 << std::endl;
 obj->put(3,3);
 int param = obj->get(2);
 std::cout << param << std::endl;
 obj->put(4,4);
 param = obj->get(1);
 std::cout << param << std::endl;
 param = obj->get(3);
 std::cout << param << std::endl;
 param = obj->get(4);
 std::cout << param << std::endl;
 return 0;
}