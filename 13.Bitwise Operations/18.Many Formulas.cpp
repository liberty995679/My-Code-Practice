//输入字符串包含1到9
//每个字符之间可以相加
//计算这种总和多少，例如123 = 1 + 23 + 12 + 3 + 123
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <unordered_map>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll total = 0;
    for (int i = 0; i < (1 << n - 1); i++) { //一共有2 ^ n - 1种情况
        ll sum = 0;
        ll cur = 0;
        for (int bit = 0; bit < n; bit++) {
            cur = cur * 10 + (s[bit] - '0');
            if (bit == n - 1 || (i >> bit) & 1) {
                sum += cur;
                cur = 0;
            }
        }total += sum;
    }
    cout << total << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}