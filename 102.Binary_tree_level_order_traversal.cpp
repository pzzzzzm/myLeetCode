// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr) return {};

        vector<vector<int>> res = {};
        queue<TreeNode*> prev;
        prev.push(root);
        // int num = 1;

        while (true) {
            vector<int> currLevel = {};
            int num = prev.size();
            for (int i = 0; i < num; i ++) {
                currLevel.push_back(prev.front()->val);
                if (prev.front()->left != nullptr) prev.push(prev.front()->left);
                if (prev.front()->right != nullptr) prev.push(prev.front()->right);
                prev.pop();
            }

            if (currLevel.size() != 0) {
                res.push_back(currLevel);
            }
            else {
                return res;
            }
        }

    }
};

int main() {
    Solution sol;

    return 0;
}

