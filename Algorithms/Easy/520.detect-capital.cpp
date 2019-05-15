/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (52.38%)
 * Likes:    305
 * Dislikes: 193
 * Total Accepted:    83.5K
 * Total Submissions: 159.5K
 * Testcase Example:  '"USA"'
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * 
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 * 
 */

class Solution {
public:
	bool detectCapitalUse(string word) {
		int length = word.length();
		if (length < 2) {
			return true;
		}
		bool start = isCapital(word[0]);
		bool always = isCapital(word[1]);
		if (!start && always) {
			return false;
		}
		for (int i = 2; i < length; i++) {
			if (start && always) {
				if (!isCapital(word[i])) {
					return false;
				}
			}
			else {
				if (isCapital(word[i])) {
					return false;
				}
			}
		}
		return true;
	}

private:
	inline bool isCapital(char c) {
		return c >= 'A' && c <= 'Z';
	}
};

