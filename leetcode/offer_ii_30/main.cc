#include <vector>
#include <list>

using namespace std;

const int NUM = 200;
const int LIST_NUM = 10;
class RandomizedSet {
private:
    std::vector<std::list<int>> hash;
    int hash_vector_num;
    int element_nums;

    std::list<int>::iterator find(int val) {
        int size = hash.size();
        int index = val % size;

        for (auto it = hash[index].begin() ; it != hash[index].end(); ++it) {
            if (*it == val)
                return it;
        }

        return hash[index].end();
    }

    void reconstruct() {
        if (element_nums/hash.size() > LIST_NUM) {
            std::vector<int> tmp_item;

            for (auto &tmp_list: hash) {
                for (const auto& item: tmp_list) {
                    tmp_item.push_back(item);
                }
                tmp_list.clear();
            }

            hash.resize(2*hash.size());

            for (const auto& item: tmp_item) {
                hash.insert(item);
            }
        }
    }

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        hash.resize(NUM);
        hash_vector_num = NUM;
        element_nums = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (find(val) != hash[val % hash.size()].end()) {
            hash[val % hash.size()].push_back(val);
            element_nums++;
            reconstruct();
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto pos = find(val);
        if (pos == hash[val%hash.size()].end())
            return false;

        hash[val % hash.size()].erase(pos);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */