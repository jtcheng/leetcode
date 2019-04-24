/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		static const char *first = "QWERTYUIOPqwertyuiop";
		static const char *second = "ASDFGHJKLasdfghjkl";
		static const char *third = "ZXCVBNMzxcvbnm";
		vector<string>::const_iterator it = words.cbegin();
		while (it != words.cend()) {
			const char* word = it->c_str();
			int len = it->length();
			bool acc = strspn(word, first) == len || strspn(word, second) == len || strspn(word, third) == len;
			if (!acc) {
				it = words.erase(it);
			}
			else {
				++it;
			}
		}
		return words;
	}
};
