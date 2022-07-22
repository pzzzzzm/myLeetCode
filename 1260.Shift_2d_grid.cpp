// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

#include "_structs.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m*n);

        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int mi = 0; mi < m; mi ++) {
            for (int ni = 0; ni < n; ni ++) {
                res[(mi+((ni+k)/n))%m][(ni+k)%n] = grid[mi][ni];
            }
        }

        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> v = build2dVector("[[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]");
    int k = 4;
    vector<vector<int>> r = sol.shiftGrid(v, k);


    return 0;
}