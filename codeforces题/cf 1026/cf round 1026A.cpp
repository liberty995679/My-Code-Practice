//t个用例 n个元素的数组a
//如果min(a) + max(a) 能被2整除则是目标数组
//每次操作可以删除数组a中的一个元素
//计算操作最少数
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int idx = -1;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = arr[i] + arr[j];
            if (x % 2 == 0) {
                idx = n - abs(i - j + 1);
                mn = min(idx, mn);
            }
        }
    }
    cout << mn << '\n';
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