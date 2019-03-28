/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (58.33%)
 * Total Accepted:    24.9K
 * Total Submissions: 42.5K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> values;
		if (root == NULL) {
			return values;
		}
		vector<vector<Node*>> allNodes;
		vector<Node*> nodes;
		nodes.push_back(root);
		int currLevel = 0;
		while (!nodes.empty()) {
			++currLevel;
			allNodes.push_back(move(nodes));
			for (Node* node : allNodes[currLevel - 1]) {
				for (Node* n : node->children) {
					if (n) {
						nodes.push_back(n);
					}
				}
			}
		}

		values.resize(currLevel);
		for (int i = 0; i < currLevel; ++i) {
			for (Node* node : allNodes[i]) {
				values[i].push_back(node->val);
			}
		}
		return values;
	}
};
