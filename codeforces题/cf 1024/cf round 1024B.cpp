//t个用例 长度n的数组a
//每次操作可以使ai = -ai
//判断是否可以让数组a的中位数为a[1] 也就是最开头的数
//如果可以输出YES 否则输出NO
#include <iostream>
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
    int ans = abs(arr[0]);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int x = abs(arr[i]);
        if (x < ans) cnt++;
    }
    if (cnt <= n / 2) { //如果绝对值比|a1|小的数 ≤ n/2，那么 a1 就有可能成为 median。
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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