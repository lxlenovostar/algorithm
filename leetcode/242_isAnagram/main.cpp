#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram2(string s, string t) {
		std::sort(s.begin(), s.end());
		
		std::sort(t.begin(), t.end());

		return s == t;
	}

    bool isAnagram(string s, string t) {

		if (s.compare(t) == 0)
			return true;

		size_t len = s.size();
		std::map<char, int> s_map;

		for (size_t i = 0; i < len; i++) {
			if (s_map.find(s[i]) == s_map.end()) {
				s_map[s[i]] = 1;
			} else {
				s_map[s[i]] += 1;
			
			}
		}

		len = t.size();
		for (size_t i = 0; i < len; i++) {
			if (s_map.find(t[i]) == s_map.end()) {
				return false;
			} else {
				s_map[t[i]] -= 1;

				if (s_map[t[i]] == 0)
					s_map.erase(t[i]);
			}
		}

		if (s_map.size() == 0)
			return true;
		else 
			return false;
        
    }
};

int main() {
	Solution *ret = new Solution();

	std::cout << ret->isAnagram("abc", "abc") << std::endl;
	std::cout << ret->isAnagram("a", "b") << std::endl;
	std::cout << ret->isAnagram("ab", "ba") << std::endl;
	std::cout << ret->isAnagram("", "") << std::endl;

	std::cout << ret->isAnagram2("abc", "abc") << std::endl;
	std::cout << ret->isAnagram2("a", "b") << std::endl;
	std::cout << ret->isAnagram2("ab", "ba") << std::endl;
	std::cout << ret->isAnagram2("", "") << std::endl;
	return 0;
}
