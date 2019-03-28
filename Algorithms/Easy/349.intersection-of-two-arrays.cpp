/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (52.95%)
 * Total Accepted:    199.3K
 * Total Submissions: 375.3K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> vi;
		int same = INT_MAX;
		int i = 0, len1 = nums1.size();
		int j = 0, len2 = nums2.size();
		while (i < len1 && j < len2) {
			if (nums1[i] < nums2[j]) {
				i++;
			}
			else if (nums1[i] > nums2[j]) {
				j++;
			}
			else {
				if (same != nums1[i]) {
					same = nums1[i];
					vi.push_back(same);
				}
				i++;
				j++;
			}
		}
		return vi;
	}
};
