// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indMap;
        for (int i = 0; i < nums.size(); i ++) {
            int compTarget = target - nums[i];
            if (indMap.find(compTarget) == indMap.end()) {
                indMap[nums[i]] = i;
            }
            else {
                return {indMap[compTarget], i};
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> inputVector = {2, 7, 11, 15};
    int target = 18;
    Solution sol;
    vector<int> res = sol.twoSum(inputVector, target);
    for (int i = 0; i < res.size(); i ++) {
        cout << res[i] << endl;
    }
}