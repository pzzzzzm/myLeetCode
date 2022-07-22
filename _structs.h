#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* buildTree(std::vector<int> v, int nullRep=-1001) {
    TreeNode* root = new TreeNode(v[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int index = 1;
    while (index < v.size()) {
        int currSize = q.size();
        for (int i = 0; i < currSize; i ++) {
            if (q.front() != nullptr) {
                if (v[index] != nullRep) {
                    TreeNode* leftNode = new TreeNode(v[index]);
                    q.front()->left = leftNode;
                    q.push(leftNode);
                }
                else {
                    q.push(nullptr);
                }
                index ++;

                if (index >= v.size()) break;

                if (v[index] != nullRep) {
                    TreeNode* rightNode = new TreeNode(v[index]);
                    q.front()->right = rightNode;
                    q.push(rightNode);
                }
                else {
                    q.push(nullptr);
                }                
                index ++;
            }
            // else {
            //     index += 2;             
            // }
            q.pop();
            
        }
    }
    return root;
}

ListNode* buildList(std::vector<int> v) {
    ListNode* root = new ListNode();
    ListNode* curr = root;
    for (int i: v) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    return root->next;
}


std::vector<std::vector<int>> build2dVector(std::string s) {
    bool isClosed = true;
    std::vector<std::vector<int>> parent;
    std::vector<int>* curr;
    int temp = 0;

    for (int i = 1; i < s.size(); i ++) {
        switch (s[i]) {
        case '[':
            curr = new std::vector<int>;
            isClosed = false;
            break;
        case ']':
            if (!isClosed) {
                curr->push_back(temp);
                temp = 0;
                parent.push_back(*curr);
                isClosed = true;
            }
            break;
        case ',':
            if (!isClosed) {
                curr->push_back(temp);
                temp = 0;
            } 
            break;             
        case ' ':
            break;
        default:
            temp = temp*10 + s[i] - '0';
            break;
        }
    }
    return parent;
}