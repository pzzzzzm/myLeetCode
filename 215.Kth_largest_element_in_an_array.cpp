// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // vector<int> topVec = {nums[0]};
        // for (int i = 1; i < k; i ++) {
        //     bool isInserted = false;
        //     for (int j = 0; j < topVec.size(); j ++) {
        //         if (nums[i] > topVec[j]) {
        //             topVec.insert(topVec.begin()+j, nums[i]);
        //             isInserted = true;
        //             break;
        //         }
        //     }
        //     if (isInserted == false) {
        //         topVec.push_back(nums[i]);
        //     }
        // }

        // for (int i = k; i < nums.size(); i ++) {
        //     for (int j = 0; j < k; j ++) {
        //         if (nums[i] > topVec[j]) {
        //             topVec.insert(topVec.begin()+j, nums[i]);
        //             topVec.pop_back();
        //             break;
        //         }
        //     }
        // }
        // return topVec[k-1];

        priority_queue<int, vector<int>, greater<int>> topQueue;

        for (int i = 0; i < k; i ++) {
            topQueue.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i ++) {
            if (nums[i] > topQueue.top()) {
                topQueue.pop();
                topQueue.push(nums[i]);
            }
        }

        return topQueue.top();

    }
};


int main() {
    Solution sol;
    vector<int> input = {3,2,3,1,2,4,5,5,6};
    int k = 9;
    int res = sol.findKthLargest(input, k);
    cout << res;
    return 0;
}


// priority_queue.push() sorts the queue automatically, like a heap.
// or sort the vector at first.

