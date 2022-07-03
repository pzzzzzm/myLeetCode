// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

// horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long hMax = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++) {
            if (horizontalCuts[i] - horizontalCuts[i-1] > hMax) {
                hMax = horizontalCuts[i] - horizontalCuts[i-1];
            }
        }
        if (h-*(horizontalCuts.end()-1) > hMax) {
            hMax = h-*(horizontalCuts.end()-1);
        }

        long long wMax = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); i++) {
            if (verticalCuts[i] - verticalCuts[i-1] > wMax) {
                wMax = verticalCuts[i] - verticalCuts[i-1];
            }
        }
        if (w-*(verticalCuts.end()-1) > wMax) {
            wMax = w-*(verticalCuts.end()-1);
        }

        return (hMax * wMax) % 1000000007;
    }
};

int main() {
    Solution sol;
    vector<int> hc = {3, 1};
    vector<int> vc = {1};
   
    cout << sol.maxArea(5, 4, hc, vc); 
    return 0;
}