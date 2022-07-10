// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        int n = dp.size();
        dp[1] = cost[0];
        for (int i = 2; i < n; i ++){
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i-1];
        }
        return min(dp[n-1], dp[n-2]);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10};
    cout << sol.minCostClimbingStairs(cost);

    return 0;
}