//t个用例 输入长度n 输入数组a
//如果数组存在abs(ai - a(i + 1)) <= 1的情况，称其为美丽数组
//每次操作可以对数组中的ai 和 ai + 1
//选择一个x (min(ai, ai + 1) <= x <= max(ai, ai + 1))
//删除ai 和 ai + 1,替换x
//计算通过这种方式将数组变成美丽数组的最小操作数
//如果没有输出 -1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n == 2) {
        if (abs(arr[0] - arr[1]) <= 1) {
            cout << 0 << enl;
            return;
        } else {
            cout << -1 << enl;
            return;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (abs(arr[i] - arr[i + 1]) <= 1) {
            cout << 0 << enl;
            return;
        }
    }
    for (int i = 2; i < n; i++) {
        int L = min(arr[i - 2], arr[i - 1]);
        int R = max(arr[i - 1], arr[i - 2]);
        if (arr[i] <= R + 1 && arr[i] >= L - 1) {
            cout << 1 << enl;
            return;
        }
    }
    for (int i = n - 3; i >= 0; i--) {
        int L = min(arr[i + 1], arr[i + 2]);
        int R = max(arr[i + 1], arr[i + 2]);
        if (arr[i] <= R + 1 && arr[i] >= L - 1) {
            cout << 1 << enl;
            return;
        }
    }
    cout << -1 << enl;
    return;
}


int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}