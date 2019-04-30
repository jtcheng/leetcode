/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
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
	int maxDepth(Node* root) {
		if (root == NULL) {
			return 0;
		}
		vector<Node*> nodes;
		nodes.push_back(root);
		int currLevel = 0;
		while (!nodes.empty()) {
			++currLevel;
			vector<Node*> tnodes;
			for (Node* node : nodes) {
				for (Node* c : node->children) {
					tnodes.push_back(c);
				}
			}
			nodes = move(tnodes);
		}
		return currLevel;
	}
};
