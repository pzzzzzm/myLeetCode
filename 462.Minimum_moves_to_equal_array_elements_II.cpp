// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

// Test cases are designed so that the answer will fit in a 32-bit integer.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[nums.size()/2];
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            res += abs(m-nums[i]);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> input = {1, 10, 2, 9};
    cout << sol.minMoves2(input);
    return 0;
}