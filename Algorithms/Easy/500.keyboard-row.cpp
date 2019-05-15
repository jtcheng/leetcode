/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (62.11%)
 * Likes:    390
 * Dislikes: 487
 * Total Accepted:    87.5K
 * Total Submissions: 140.9K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
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

