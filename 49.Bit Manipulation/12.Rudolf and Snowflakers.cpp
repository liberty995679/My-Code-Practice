//判断一朵雪花是否存在n个顶点
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(int n) {  //实际上是等比数列求和
    bool flag = false;
    for (int k = 2; k * k <= n; k++) {
        ll x = 1; ll sum = 1;
        while (sum < n) {
            x *= k;
            sum += x;
        }if (sum == n) flag = true;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}