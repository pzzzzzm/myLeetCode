// You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

// Return true if you can make this square and false otherwise.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> edgeList = {0, 0, 0, 0};

    bool makesquare(vector<int>& matchsticks) {
        
        int n = matchsticks.size();
        int sum = 0;
        for (int i: matchsticks) sum += i;
        if (sum % 4 == 0) {
            sum /= 4;
        }
        else {
            return false;
        }

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return putStickToEdge(0, matchsticks, sum, n);

    }

    bool putStickToEdge(int index, vector<int>& matchsticks, int edgeSum, int n){

        if (index == n){
            for (int i: edgeList){
                if (i != edgeSum) return false;
            }
            return true;
        }

        // try to put stick in every edge, except the first one
        for (int e = 0; e < 4; e ++){
            if (edgeList[e] + matchsticks[index] <= edgeSum) {
                edgeList[e] += matchsticks[index];
                if (putStickToEdge(index+1, matchsticks, edgeSum, n)) return true;
                if (index == 0) return false;
                edgeList[e] -= matchsticks[index];
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> sticks = {120, 60, 30, 30, 20, 20, 20, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18};
    cout << sol.makesquare(sticks);
    return 0;
}