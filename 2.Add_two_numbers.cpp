

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tempSum = 0;
        bool carry = false;
        ListNode* root = new ListNode();
        ListNode* curr = root;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                tempSum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                tempSum += l2->val;
                l2 = l2 -> next;
            }
            if (carry) {
                tempSum ++;
                carry = false;
            }
            if (tempSum >= 10) {
                tempSum -= 10;
                carry = true;
            }
            curr->next = new ListNode(tempSum);
            curr = curr->next;
            tempSum = 0;
        }
        if (carry) curr->next = new ListNode(1);
        return root->next;
    }
};

ListNode* buildList(vector<int> v) {
    ListNode* root = new ListNode();
    ListNode* curr = root;
    for (int i: v) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    return root->next;
}

int main() {
    Solution sol;
    ListNode* l1 = buildList({9,9,9,9,9,9,9});
    ListNode* l2 = buildList({9,9,9,9});
    ListNode* res = sol.addTwoNumbers(l1, l2);

    return 0;
}