//计算数组内的子序列非递减的
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

void convert(vector<int> &a) {
    int n = a.size();
    int len = 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) len++; //统计连续数组的长度
        else {
            ans += len * (len + 1) / 2;  //n * (n + 1) / 2 是数量计算
            len = 1;
        }
    }
    ans += len * (len + 1) / 2;
    cout << ans << '\n';
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        convert(arr);
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