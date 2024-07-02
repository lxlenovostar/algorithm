/*
int gcd(int a, int b) {
		int s = a < b ? a : b;
		int l = a > b ? a : b;
		int tmp = -1;
		while (s) {
			tmp = s;
			s = l%s;
			l = tmp;
		}
		return l;
	}
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        size_t len1 = str1.size();
        size_t len2 = str2.size();

        //string l = len1 > len2 ? str1: str2;
        //string s = len2 > len1 ? str2: str1;

        string l = "abc";
        string s = "a";
        //while (s.size() > 0) {
        //string tmp = 
        cout << "value: " << l.find_last_not_of(s) << std::endl;           
        //}

        return l;
    }
};

int main () {
    string str1 = "ABABAB";
    string str2 = "ABAB";

    Solution *test = new Solution();
    std::cout << "ret: " << test->gcdOfStrings(str1, str2) << std::endl;
}

