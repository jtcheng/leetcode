/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.87%)
 * Total Accepted:    185.5K
 * Total Submissions: 314.7K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> vs;
		auto multi3 = [](int x) {return x % 3 == 0; };
		auto multi5 = [](int x) {return x % 5 == 0; };
		for (int i = 1; i <= n; ++i) {
			string s;
			if (multi3(i)) {
				s += "Fizz";
			}
			if (multi5(i)) {
				s += "Buzz";
			}
			if (s.empty()) {
				s = to_string(i);
			}
			vs.push_back(move(s));
		}
		return vs;
	}
};
