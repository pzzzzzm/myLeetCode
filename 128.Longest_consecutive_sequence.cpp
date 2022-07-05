// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto n: nums) pq.push(n); 
        // sort(nums.begin(), nums.end());
        int res = 1;
        int cur = 1;
        int prev = pq.top();
        pq.pop();
        while (!pq.empty()) {
            if (pq.top()-prev == 1) {
                cur ++;
            }
            else if (pq.top()-prev > 1){
                res = max(res, cur);
                cur = 1;
            }
            prev = pq.top();
            pq.pop();
        }
        res = max(res, cur);
        return res;


    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 2, 0};
    cout << sol.longestConsecutive(nums);
    return 0;
}

// can use hashset to reduce the time complexity to O(n).
// hash all the elements -> O(n*1)
// for all elements:
    // 1. check if is a head
    // 2. find the longest sequence if it is 
    // overall time complexity -> O(n)


    