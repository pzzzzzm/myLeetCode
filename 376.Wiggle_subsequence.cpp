// A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

// Given an integer array nums, return the length of the longest wiggle subsequence of nums.
 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        if (nums.size() == 2 && nums[0] != nums[1]) {
            return true;
        }

        vector<int> nextDown(nums.size(), 0);
        vector<int> nextUp(nums.size(), 0);
        
        nextDown[0] = 1;
        nextUp[0] = 1;
        int res = 1;

        for (int i = 1; i < nums.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[j] > nums[i]) {
                    nextUp[i] = max(nextUp[i], nextDown[j]+1);
                    res = max(res, nextUp[i]);
                }
                if (nums[j] < nums[i]) {
                    nextDown[i] = max(nextDown[i], nextUp[j]+1);
                    res = max(res, nextDown[i]);
                }
            }
        }

        return res;


    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    cout << sol.wiggleMaxLength(nums);
    return 0;
}


// Greedy is more efficent
