/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.76%)
 * Total Accepted:    505.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> bracketPairs{
			{')', '('},
			{']', '['},
			{'}', '{'}
		};
		stack<char> brackets;
		for (int i = 0, len = s.length(); i < len; ++i) {
			auto it = bracketPairs.find(s[i]);
			if (it == bracketPairs.end()) {
				brackets.push(s[i]);
			}
			else {
				if (brackets.empty() || (brackets.top() != it->second)) {
					return false;
				}
				brackets.pop();
			}
		}
		return brackets.empty();
	}
};
