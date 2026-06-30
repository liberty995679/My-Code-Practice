//有n个从1开始的连续数，只输入n - 1个，求缺少的那个数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve(const vector<int> &a) { //总异或再与少一个的异或可得
    int n = a.size();
    int res = 0;
    for (auto &i: a) {
        res ^= i;
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans ^= i;
    }
    cout << (res ^ ans) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> arr[i];
    solve(arr);
    return 0;
}