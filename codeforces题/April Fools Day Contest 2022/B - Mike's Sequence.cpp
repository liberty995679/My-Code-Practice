//在OEIS找不到这个序列
//MIKE序列
//输入r
//输出一个值
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

//Mike 的序列是 Codeforces 的评级阈值：[1200,1400,1600,1900,2100,2300,2400,2600,3000].
//你的任务只是打印出紧接在所提供的评分阈值之上的阈值 r

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    vector<int> arr = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
    for (int &i : arr) {
        if (i > r) {
            cout << i << enl;
            return 0;
        }
    }
    return 0;
}