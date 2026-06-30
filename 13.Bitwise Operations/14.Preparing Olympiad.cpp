//n个数,构造多个集合
//每个集合至少有2个数,其总和在 L 和 R 之间
//且最大值和最小值的差至少为 X
//计算有多少个情况
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> arr(n);
    for (int i= 0; i < n; i++) cin >> arr[i];
    int cnt = (1 << n) ;
    int res = 0;
    for (int t = 0; t < cnt; t++) {
        int mxnum = 0;
        int mnnum = 1e9;
        int sum = 0;
        int diff = 0;
        for (int bit = 0; bit < n; bit++) {
            if (t & (1 << bit)) { 
                mxnum = max(mxnum, arr[bit]);
                mnnum = min(mnnum, arr[bit]);
                sum += arr[bit];
            }
        }
        diff = mxnum - mnnum;
        if (sum <= r && sum >= l && diff >= x) res++;
    }
    cout << res << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}