#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int s_size = s.size();

        /*
        for (int i = 0; i <= s_size/2 -1; ++i) {
            std::swap(s[i], s[s_size - 1  - i]);
        }
        */
       int left = 0;
       int right = s_size - 1;
       while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
       }

    }
};

int main() {
    vector<char> numbers = {'h', 'e', 'l', 'l', 'o'};
    Solution * test = new Solution();
    test->reverseString(numbers);
    for (const auto &item : numbers){
        std::cout << item << std::endl;
    }
    return 0;
}