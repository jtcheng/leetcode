/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.25%)
 * Total Accepted:    214.7K
 * Total Submissions: 759.7K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */

class Solution {
public:
	int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        } else if (n == 3) {
            return 1;
        }
		vector<int> vi(n, 1);
		for (int i = 2; i*i < n; ++i) {
			if (vi[i]) {
				for (int j = i * i; j < n; j += i) {
					vi[j] = 0;
				}
			}
		}
		return accumulate(vi.begin() + 2, vi.end(), 0);
	}
};
