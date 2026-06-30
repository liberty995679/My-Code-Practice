//输入n m接着输入n个数
//这些数的范围是1 到 m
//判断它们出现的次数
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 1; i <= m; i++) {
        cout << mp[i] << '\n';
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r" ,stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}