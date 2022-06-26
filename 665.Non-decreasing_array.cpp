// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        bool isModified = false;

        if (nums.size() == 1) {
            return true;
        }

        if (nums[1] < nums[0]) {
            isModified = true;
        }

        for (int i = 2; i < nums.size(); i ++) {
            if (nums[i] < nums[i-1]) {
                if (isModified == false) {
                    isModified = true;
                    if (nums[i] < nums[i-2]) {
                        nums[i] = nums[i-1];
                    } 
                }
                else {
                    return false;
                }
            }
        }

        return true;

    }
};

int main() {
    Solution sol;
    vector<int> input = {5, 7, 1, 8};
    bool res = sol.checkPossibility(input);
    cout << res;
    return 0;
}