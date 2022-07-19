#include "_structs.h"

using namespace std;


int main() {
    
    // vector
    vector<int> v = {1, 2, 3};
    v.front() = 9;
    v.push_back(5);
    v.push_back(6);
    v.pop_back();

    // for (auto i: v) {
    //     cout << i;
    // }


    // queue
    queue<int> q;


    // priority_queue
    priority_queue<int, vector<int>, greater<int>> pq;


    // map
    map<int, char> m;
    m[2] = 'b';
    m.insert(pair<int, char> (3, 'c'));
    m.insert(make_pair(4, 'd'));

    // for (auto mi: m) {
    //     cout << mi.first;
    //     cout << mi.second;
    // }

    // unordered_map
    unordered_map<int, char> um;
    

    // 


    // 2d vector sort
    vector<vector<int>> c = {{5, 5}, {4, 6}, {2, 6}};
    sort(c.begin(), c.end(), [](const vector<int> &a, const vector<int> &b){return a[1]<b[1];});
    
}