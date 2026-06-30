//t个用例 n个元素的数组a
//数组已经排好序了，对数组内的元素进行分组
//相邻元素之间的差值大于1 即可各自分为一组
//计算可分的组最大数量
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
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int last = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        int x = arr[i] - last;
        if (x > 1) {
            last = arr[i];
            cnt++;
        }
    }
    cout << cnt << endl;
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