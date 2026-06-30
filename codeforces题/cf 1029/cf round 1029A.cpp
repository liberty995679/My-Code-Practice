//t个用例 n 数组长度 
//x为可以让所有关闭的门开启x秒(至多一次)
//输入字符串包含01 0 代表开门 1代表关门
//计算主角是否能通过这些门
//输出YES 或者 NO
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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0; int r = n - 1;
    int res = 0;
    while (l < r) {
        if (arr[l] == 0) l++;
        if (arr[r] == 0) r--;
        if (arr[l] == 1 && arr[r] == 1) {
            break;
        }
    }
    res = r - l + 1;
    if (x >= res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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