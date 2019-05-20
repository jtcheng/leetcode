/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 *
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
 *
 * algorithms
 * Easy (47.81%)
 * Likes:    351
 * Dislikes: 143
 * Total Accepted:    56K
 * Total Submissions: 117K
 * Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
 *
 * 
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both
 * have a list of favorite restaurants represented by strings. 
 * 
 * 
 * You need to help them find out their common interest with the least list
 * index sum. If there is a choice tie between answers, output all of them with
 * no order requirement. You could assume there always exists an answer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
 * "Shogun"]
 * Output: ["Shogun"]
 * Explanation: The only restaurant they both like is "Shogun".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["KFC", "Shogun", "Burger King"]
 * Output: ["Shogun"]
 * Explanation: The restaurant they both like and have the least index sum is
 * "Shogun" with index sum 1 (0+1).
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The length of both lists will be in the range of [1, 1000].
 * The length of strings in both lists will be in the range of [1, 30].
 * The index is starting from 0 to the list length minus 1.
 * No duplicates in both lists.
 * 
 * 
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> umap;
        for (int i = 0, len = list1.size(); i < len; ++i) {
            umap[list1[i]] = i;
        }
        vector<string> ans;
        int minsum = INT_MAX;
        int sum = 0;
        for (int i = 0, len = list2.size(); i < len; ++i) {
            if (umap.count(list2[i]) > 0) {
                sum = i + umap[list2[i]];
                if (sum < minsum) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    minsum = sum;
                } else if (sum == minsum) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
