// You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

// You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

// The first element in s[k] starts with the selection of the element nums[k] of index = k.
// The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
// We stop adding right before a duplicate element occurs in s[k].
// Return the longest length of a set s[k].

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> v(nums.size(), 0);
        int k = 0;
        int res = 0;
        int temp = 0;

        while (true) {
            if (v[k] == 0) {
                v[k] = 1;
                k = nums[k];
                temp ++;
            }
            else {
                res = max(res, temp);
                temp = 0;
                bool checkNewCycle = false;
                for (int i = 0; i < nums.size(); i ++) {
                    if (v[i] == 0) {
                        checkNewCycle = true;
                        k = i;
                        break;
                    }
                }
                if (!checkNewCycle) break; 
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 2, 1};
    cout << sol.arrayNesting(nums);
    return 0;
}