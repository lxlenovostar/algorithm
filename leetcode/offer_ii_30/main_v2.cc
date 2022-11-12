#include <vector>
#include <map>
#include <iostream>

using namespace std;

class RandomizedSet {
private:
    std::map<int, int> hash;
    std::vector<int> index;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
         srand((unsigned) time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) != hash.end())
            return false;

        index.push_back(val);
        hash[val] = index.size()-1; 

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto pos = hash.find(val);
        if (pos == hash.end())
            return false;
        
        int item = pos->second;
        hash[index.back()] = item;
        index[item] = index.back();
        index.pop_back();

        hash.erase(pos);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return index[rand()%index.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 */
int main() {
 RandomizedSet* obj = new RandomizedSet();
 bool param_1 = obj->insert(1);
 std::cout << param_1 << std::endl;
 bool param_2 = obj->remove(2);
 std::cout << param_2 << std::endl;
 int param_3 = obj->getRandom();
 std::cout << param_3 << std::endl;
 
 return 0;
 }