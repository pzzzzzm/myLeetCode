// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


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
    vector<int> rightSideView(TreeNode* root) {

        if (root == nullptr) return {};

        vector<TreeNode*> prev;
        vector<TreeNode*> curr;
        vector<int> res;

        prev.push_back(root);
        res.push_back(root->val);

        while (true){
            for (int i = 0; i < prev.size(); i ++){
                if (prev[i]->right != nullptr) curr.push_back(prev[i]->right);
                if (prev[i]->left != nullptr) curr.push_back(prev[i]->left);
            }

            if (curr.size() > 0) {
                res.push_back(curr[0]->val);
            }
            else {
                break;
            }

            prev = curr;
            vector<TreeNode*> newCurr;
            curr = newCurr;

        }

        return res;
    }
};


int main() {


    Solution sol;
    TreeNode n4 = TreeNode(4);
    TreeNode n5 = TreeNode(5);
    TreeNode n3 = TreeNode(3, nullptr, &n4);
    TreeNode n2 = TreeNode(2, nullptr, &n5);
    TreeNode n1 = TreeNode(1, &n2, &n3);
    vector<int> res = sol.rightSideView(&n1);
    for (int i = 0; i < res.size(); i ++){
        cout << res[i];
    }

    return 0;
}

