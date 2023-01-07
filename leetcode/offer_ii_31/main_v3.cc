#include <map>
#include <list>
#include <iostream>

using namespace std;

class LRUCache {    
private:
struct element {
        int key;
        int value;
    };

private:
    std::map<int, std::list<struct element>::iterator> lru_key;
    std::list<struct element> lru_value;
    int m_lru_limit;

public:
    LRUCache(int limit): m_lru_limit(limit) {

    }

    void put(int key, int value) {
        if (lru_key.find(key) != lru_key.end()) {
            lru_value.erase(lru_key.at(key));
        }

        struct element item{key, value};
        lru_key[key] = lru_value.insert(lru_value.end(), item);

        while (lru_value.size() > m_lru_limit) {
            auto& item = lru_value.front();
            int key = item.key;
            lru_value.pop_front();
            lru_key.erase(key);
        }

    }

    int get(int key) {
        if (lru_key.find(key) == lru_key.end())
            return -1;
        
        auto& item = lru_key.at(key);
        int value = item->value;

        lru_value.erase(item);

        struct element update_item{key, value};
        lru_key[key] = lru_value.insert(lru_value.end(), update_item);

        return value;
    }

};

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