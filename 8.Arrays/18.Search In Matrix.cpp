//判断x是否存在于二维数组
//如果存在输出will not take number
//如果不存在输出will take number
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            mp[x]++;
        }
    }
    int x;
    cin >> x;
    if (mp.find(x) == mp.end()) cout << "will take number\n";
    else cout << "will not take number\n";
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