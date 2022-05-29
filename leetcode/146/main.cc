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

        m_head = new DoubleList(-1, -1, nullptr, nullptr);
        m_tail = new DoubleList(-1, -1, nullptr, nullptr);

        m_head->next = m_tail;
        m_tail->prev = m_head;
    }
    
    int get(int key) {
        if (m_hash.find(key) != m_hash.end()) {
            move_to_head(m_hash[key]);
            return m_hash.at(key)->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
   
        //std::cout << "add new: key: " << key << " value: " << value << " size: " << m_hash.size() << std::endl;
        if (m_hash.find(key) == m_hash.end() && m_hash.size() + 1 > m_capacity) {
            // 需要函数清理最旧的节点
            if (m_tail->prev) {
                //std::cout << "tail: " << m_tail->prev->val << " key: " << key << " value: " << value << std::endl;
                m_hash.erase(m_tail->prev->key);
            }
            del_tail();
        }
          
        if (m_hash.find(key) != m_hash.end()) {
            move_to_head(m_hash[key]);
            m_hash[key]->val = value;
        } else {
            //std::cout << "add new: key: " << key << " value: " << value << std::endl;
            struct DoubleList *new_node = new DoubleList(key, value, nullptr, nullptr); 
            m_hash[key] = new_node;
            add_in_head(new_node);
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
        add_in_head(node);
    }

    void add_in_head(struct DoubleList* node) {
        if (node == nullptr)  return;

        struct DoubleList* tmp_next = m_head->next;
        m_head->next = node;
        node->prev = m_head;

        node->next = tmp_next;
        tmp_next->prev = node;
    }

    void del_tail() {
        struct DoubleList* tmp_node = m_tail->prev;

        struct DoubleList* ret = del_node(tmp_node); 
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