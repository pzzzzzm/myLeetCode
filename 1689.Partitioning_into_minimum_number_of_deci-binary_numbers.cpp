// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

// Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max = '0';
        for (int i = 0; i < n.size(); i ++) {
            if (n[i] == '9') return 9;
            if (n[i] > max) {
                max = n[i];
            }
        }
        return max - '0';
    }
};

int main() {
    Solution sol;
    string input = "27346209830709182346";
    cout << sol.minPartitions(input);
    return 0;
}