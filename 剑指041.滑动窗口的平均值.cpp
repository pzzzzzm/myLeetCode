// 给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

// 实现 MovingAverage 类：

// MovingAverage(int size) 用窗口大小 size 初始化对象。
// double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/qIsx9U
// 商业转载请联系官方授权，非商业转载请注明出处。著作权归领扣网络所有。

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class MovingAverage {
public:
    
    int wSize;
    queue<int> q;
    int sum = 0;

    MovingAverage(int size) {
        wSize = size;
    }
    
    double next(int val) {
        if (q.size() < wSize) {
            q.push(val);
            sum += val;
            return (double)sum / q.size();
        }
        else {
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
            return (double)sum / wSize;
        }
    }
};

int main() {
    int size = 3;
    MovingAverage* obj = new MovingAverage(size);
    vector<int> valList = {1, 10, 3, 5};
    for (int val: valList) {
        double param_1 = obj->next(val);
        cout << param_1 << endl;
    }
    
    return 0;

}

