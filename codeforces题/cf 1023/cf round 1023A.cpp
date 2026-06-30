//你有n长度的数组a
//把他分为两个数组b 和 c
//两个数组都至少有一个元素
//且gcd(b) != gcd(c)
//如果存在，输出Yes 加上 1 1 2 1这种代表改元素分到了哪个数组
//如果不存在，输出No
#include <iostream>
#include <algorithm>
#include <vector>
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
    int mx = *max_element(arr.begin(), arr.end());   //最大值单独一组
    int mn = *min_element(arr.begin(), arr.end());
    if (mx == mn) {  //最大值都一样，即所有数一样
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << (1 + (arr[i] == mx)) << ' ';
    }cout << '\n';
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