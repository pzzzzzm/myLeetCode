// Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

// A subtree of a node node is node plus every node that is a descendant of node.


#include "_structs.h"

using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root->left != nullptr) root->left = pruneTree(root->left);
        if (root->right != nullptr) root->right = pruneTree(root->right);
        if (root->left != nullptr || root->right != nullptr || root->val != 0) return root;
        return nullptr;
    }
};

int main() {
    Solution sol = Solution();
    int null = -1001;
    TreeNode* t = buildTree({1,0,1,0,0,0,1});
    TreeNode* nt = sol.pruneTree(t);

    return 0;
}