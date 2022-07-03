#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<vector<int>>& vec) {
    for (const auto& item: vec) {
        for (const auto& number: item) {
            std::cout << number << " "; 
        }
        std::cout << std::endl; 
    }
}

void print_array(vector<int>& vec) {
    for (const auto& item: vec) {
        std::cout << item; 
        std::cout << std::endl; 
    }
}

class Solution {
public:
    friend void print_array(vector<int>& vec); 
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq;
        vector<int> ret;

        freq.resize(1001);

        for (const auto & item: arr1) {
            freq[item] += 1;
        }

        for (const auto & item: arr2) {
            while(freq[item] > 0) {
                ret.push_back(item);
                freq[item]--;
            }
        }

        print_array(freq);

        for (int i = 0; i < 1001; ++i) {
            while(freq[i] > 0) {
                ret.push_back(i);
                freq[i]--;
            }
        }

        return ret;
    }
    
};

int main()
{
    //vector<vector<int>> intervals = {{2, 6}, {1, 3},  {8, 10}, {15, 18}};
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    Solution * test = new Solution();
    vector<int> ret = test->relativeSortArray(arr1, arr2);
    print_array(ret);
    //print(ret);


    return 0;
}