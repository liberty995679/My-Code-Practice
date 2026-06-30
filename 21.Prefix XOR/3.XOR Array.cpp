//t个用例 输入n x y
//f(x, y) = ax ^ a(x + 1) ^ ...a(y) = 0;
//构造一个数组满足条件
//只有f(x, y) == 0
//输出这个数组
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <utility>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    arr[y] = arr[x - 1];
    for (int i = 1; i <= n; i++) {
        cout << (arr[i] ^ arr[i - 1]) << ' ';
    } cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r" ,stdin);
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