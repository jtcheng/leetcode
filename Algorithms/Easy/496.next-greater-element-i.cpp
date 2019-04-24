/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> s;
		unordered_map<int, int> m;
		for (int n : nums2) {
			while (!s.empty() && s.top() < n) {
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		for (int i = 0, len = nums1.size(); i < len; ++i) {
			int ni = nums1[i];
			nums1[i] = m.find(ni) == m.end() ? -1 : m[ni];
		}
		return nums1;
	}
};
