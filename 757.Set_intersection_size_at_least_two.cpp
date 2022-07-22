// An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

// Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has a size of at least two.

#include "_structs.h"

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            else {
                return a[0] < b[0];
            }
        });

        int start = intervals[0][0];
        int end1 = intervals[0][1]-1;
        int end2 = intervals[0][1];

        int res = 2;
        
        int i1;
        int i2;
        for (int i = 1; i < intervals.size();  i ++) {
            if (intervals[i][0] == start) continue;
            i1 = intervals[i][0];
            i2 = intervals[i][1];
            start = i1;

            // check if two ends are in this interval
            if (i1 > end2) {
                end2 = i2;
                res ++;
            }
            if (i1 > end1) {
                end1 = i2;
                res ++;
            }
            if (i2 < end2) end2 = i2;
            if (i2 < end1) end1 = i2;

            // maintian the order of ends
            if (end1 == end2) end1 --;
            if (end1 > end2) {
                i1 = end1;
                end1 = end2;
                end2 = i1;
            }   

        }

        return res;
                    
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> v = build2dVector("[[1,4],[0,3],[1,3],[0,5],[1,3]]");
    int r = sol.intersectionSizeTwo(v);
    cout << r;

    return 0;
    
}