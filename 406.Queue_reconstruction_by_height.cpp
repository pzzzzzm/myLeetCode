// You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

// Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0] != b[0]) {
                return a[0] > b[0];
            }
            else {
                return a[1] < b[1];
            }
            });
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); i++) {
            res.insert(res.begin()+people[i][1], people[i]);
        }

        return res;

    }
};

int main() {
    Solution sol;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    people = sol.reconstructQueue(people);
    for (int i = 0; i < people.size(); i ++) {
        
        cout << people[i][0] << ',';
        cout << people[i][1] << ',';
        cout << '|';
    }
    cout << endl;
    return 0;
}
