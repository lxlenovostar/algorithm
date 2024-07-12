#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

struct DoubleList {
    int key;
    int val;
    struct DoubleList *next;
    struct DoubleList *prev;
    DoubleList(int _key, int _val, struct DoubleList *_next, struct DoubleList *_prev) : key(_key), val(_val), next(_next), prev(_prev) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_head = new DoubleList(0, 0, nullptr, nullptr);
        m_tail = new DoubleList(0, 0, nullptr, nullptr);
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }
    
    int get(int key) {
        if (m_hash.find(key)  == m_hash.end()) {
            return -1;
        } else {
            auto value_iter = m_hash[key];
            move_to_head(value_iter);
            return value_iter->val;
        }
    }
    
    void put(int key, int value) {
        if (m_hash.find(key) == m_hash.end() && m_hash.size() + 1 > m_capacity) {
            del_tail();
        }

        auto iter = m_hash.find(key);
        if (iter == m_hash.end()) {
            struct DoubleList *tmp = new DoubleList(key, value, nullptr, nullptr);
            m_hash[key] = tmp;
            add_to_head(tmp);
        } else {
            auto value_ptr = m_hash[key];
            value_ptr->val = value;
            move_to_head(value_ptr);
        }
    }

private:
    struct DoubleList* del_node(struct DoubleList* node) {
        struct DoubleList* node_prev = node->prev;
        struct DoubleList* node_next = node->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;
        return node;
    }

    void move_to_head(struct DoubleList *node) {
        del_node(node);
        add_to_head(node);
    }
 
    void add_to_head(struct DoubleList *node) {
        if (node == nullptr) return;

        struct DoubleList* head_next = m_head->next;

        node->next = head_next;
        head_next->prev = node;

        m_head->next = node;
        node->prev = m_head;
    }


    void del_tail() {
        struct DoubleList* pre = m_tail->prev;
        struct DoubleList* ret = del_node(pre);

        delete ret;
        ret = nullptr;
    }

private:
    size_t m_capacity;
    unordered_map<int , struct DoubleList*> m_hash;
    struct DoubleList* m_head;
    struct DoubleList* m_tail;
};

int main() {
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    std::cout << "2: " << obj->get(2) << std::endl;
    obj->put(2, 6);
    std::cout << "1: " << obj->get(1) << std::endl;
    obj->put(1, 5);
    obj->put(1, 2);
    std::cout << "1: " << obj->get(1) << std::endl;
    std::cout << "2: " << obj->get(2) << std::endl;

    return 0;
} 