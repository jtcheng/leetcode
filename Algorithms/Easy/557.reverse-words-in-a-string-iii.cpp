/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (63.92%)
 * Likes:    609
 * Dislikes: 66
 * Total Accepted:    123.2K
 * Total Submissions: 192.7K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */

class Solution {
public:
	string reverseWords(string s) {
		for (int i = 0, j = 0, len = s.length(); i < len; ) {
			j = i;
			while (j != len && s[++j] != ' ') {
				;
			}
			reverse(begin(s) + i, begin(s) + j);
			i = j + 1;
		}
		return s;
	}
};

