// There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

// You will start on the 1st day and you cannot take two or more courses simultaneously.

// Return the maximum number of courses that you can take.


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b){return a[1]<b[1];});
        priority_queue<int, vector<int>> timeQueue;
        int timeTotal = 0;

        for (int i = 0; i < courses.size(); i ++) {
            timeQueue.push(courses[i][0]);
            timeTotal += courses[i][0];
            if (timeTotal > courses[i][1]) {
                timeTotal -= timeQueue.top();
                timeQueue.pop();
            }
        }

        return timeQueue.size();

    }
};

int main() {
    Solution sol;
    vector<vector<int>> courses = {{5, 5}, {4, 6}, {2, 6}};
    cout << sol.scheduleCourse(courses);
    return 0;
}