//最小化数组,只有当他元素全是偶数的时候可以执行操作
//每次操作除以2
//计算最多能进行几次操作
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void change(const vector<int>& a) {
    ll res = LLONG_MAX;
    for (int i: a) {
        ll cnt = 0;
        int x = i;
        while (x % 2 == 0) { 
            x /= 2;
            cnt++;
        }   //由最先变成奇数的那个数决定
        res = min(res, cnt); //取最小
    }
    cout << res << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i =0; i < n; i++ ) cin >> arr[i];
    change(arr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}