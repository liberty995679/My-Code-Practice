//t个例子 输入n 个数字组成的数组
//计算最大可能的与运算值
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

void convert(const vector<int> &a) {
    if (a.size() == 1) {
        cout << a[0] << '\n';
        return;
    }
    int n = a.size();
    ll res = 0;
    vector<int> cur = a;
    for (int bit = 31; bit >= 0; bit--) {
        vector<int> next;
        for (int x: cur) {
            if (x & (1 << bit)) {
                next.push_back(x);
            }
        }
        if (!next.empty()) cur.swap(next); //不拷贝数据，内容“直接交换”
    }
    cout << cur[0] << '\n';
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n; 
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        convert(arr);
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