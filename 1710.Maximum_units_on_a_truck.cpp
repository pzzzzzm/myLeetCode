// You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

// Return the maximum total number of units that can be put on the truck.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> a, const vector<int> b) {
            return a[1] > b[1];
        });

        int res = 0;

        for (auto i : boxTypes) {
            if (truckSize == 0) break;
            int putBox = min(i[0], truckSize);
            res += putBox*i[1];
            truckSize -= putBox;
            }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> bt = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int ts = 10;
    cout << sol.maximumUnits(bt, ts);
    return 0;
}