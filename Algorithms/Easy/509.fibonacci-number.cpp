/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

class Solution {
public:
	int fib(int N) {
		int n1 = 0, n2 = 1;
		return fib(N, n1, n2);
	}

private:
	int fib(int n, int n1, int n2) {
		if (n == 0) {
			return n1;
		}
		return fib(n - 1, n2, n1 + n2);
	}
};
