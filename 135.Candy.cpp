// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 1;
        int current = 1;
        int depth = 1;
        int fall = 0;

        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] < ratings[i-1]) {

                if (current > 1) {
                    fall = current;
                    current = 1;
                }

                depth ++;
                res += depth;
            }
            else {

                if (fall > 0) {
                    if (fall <= depth) {
                        res += depth + 1 - fall;
                    }
                    fall = 0;
                }

                if (ratings[i] == ratings[i-1]) {
                    current = 1;
                    depth = 1;
                    res += 1;
                }
                else {
                    depth = 0;
                    current ++;
                    res += current;
                }
            }
        }

        if (fall > 0) {
                    if (fall <= depth) {
                        res += depth + 1 - fall;
                    }
                    fall = 0;
                }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> r = {1, 3, 2, 2, 1};
    cout << sol.candy(r);
    return 0;
}