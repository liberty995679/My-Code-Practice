//构造排列
//从中间开始，左右跳
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start = n / 2;
        for (int i = 0; i < n; i++) {
            int dist = (i + 1) / 2;
            int dire = (i % 2 == 0 ? +1 : -1);
            int val = start + dist * dire + 1;
            cout << val << ' ';
        }
        cout << endl;
    }
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