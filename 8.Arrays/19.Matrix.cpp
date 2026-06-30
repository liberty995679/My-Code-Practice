//输入一个n * n的二维数组
//计算两条对角线的总和的绝对值
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
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }
    int i = 0; int j = 0;
    ll sum = 0;
    while (i < n && j < n) {
        sum += arr[i][j];
        i++;
        j++;
    }
    i = 0; j = n - 1;
    ll cnt = 0;
    while (i < n && j >= 0) {
        cnt += arr[i][j];
        i++;
        j--;
    }
    sum = abs(sum - cnt);
    cout << sum << endl;
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