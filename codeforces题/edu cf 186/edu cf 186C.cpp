//t个用例 n数组长度
//a b c三个数组 表示雪人的头 躯干 腿
//选择i j k 对每个雪人进行连续匹配 
//选择的 i j k 必须是连续的
//只有严格满足 a < b < c的条件，才可以搭雪人
//计算有几种情况
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
#include <map>
#include <set>
using namespace std;
using ll = long long;

bool convert(const vector<int>&a, const vector<int>&b, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[(i + k) % n]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    ll ans = 0;
    ll k1 = 0; ll k2 = 0;  //两边都是独立的
    for (int d = 0; d < n; d++) {
        if (convert(a, b, n, d)) {
            k1++;
        } 
        if (convert(b, c, n, d)) {
            k2++;
        }
    }
    ans = k1 * k2 * n;  //相乘可能溢出用ll
    cout << ans << '\n';
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