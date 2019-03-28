/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.06%)
 * Total Accepted:    60.4K
 * Total Submissions: 134.1K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> ret;
		static vector<vector<string>> h{ {"0:"},
										 {"1:", "2:", "4:", "8:"},
										 {"3:", "5:", "9:", "6:", "10:"},
										 {"7:", "11:"} };
		static vector<vector<string>> m{ {"00"},
										 {"01", "02", "04", "08", "16", "32"},
										 {"03", "05", "09", "17", "33", "06", "10", "18", "34", "12", "20", "36", "24", "40", "48"},
										 {"07", "11", "19", "35", "13", "21", "37", "25", "41", "49", "14", "22", "38", "26", "42", "50", "28", "44", "52", "56"},
										 {"15", "23", "39", "27", "43", "51", "29", "45", "53", "57", "30", "46", "54", "58"},
										 {"31", "47", "55", "59"} };
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (i + j == num) {
					for (string hs : h[i]) {
						for (string ms : m[j]) {
							ret.push_back(hs + ms);
						}
					}
				}
			}
		}
		return ret;
	}
};
