// You are given a 0-indexed integer array nums and an integer k.

// You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

// You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

// Return the maximum score you can get.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        int tempMaxInd = 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < dp.size(); i ++) {
            if (i - tempMaxInd > k) {
                tempMaxInd = i-k;
                for (int j = i-k; j < i; j ++){
                    if (dp[j]>=dp[tempMaxInd]) tempMaxInd = j;
                }
            }
            
            dp[i] = dp[tempMaxInd] + nums[i];

            if (nums[i] >= 0) {
                tempMaxInd = i;
            }
        }

        return dp[dp.size()-1];

    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, -1, -2, 4, -7, 3};
    int k = 2;
    cout << sol.maxResult(nums, k);

    return 0;
}