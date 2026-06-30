//数组已经从小到大排好序了
//Alice 选 3 个数染红
//Bob 一定会选一个数染蓝（可以选染红里的，也可以选外面的）
//Alice 想要：不管 Bob 选谁，剩下 2 个红色数的和 ＞ 蓝色数
//求：满足条件的三元组数量
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i: arr) cin >> i;
    int max_val = arr.back();
    ll ans = 0;
    for (int k = 2; k < n; k++) {
        int z = max(max_val - arr[k], arr[k]);
        int l = 0; int r = k - 1;
        ll cnt = 0;
        while (l < r) {
            if (arr[l] + arr[r] > z) {
                cnt += r - l;
                r--;
            } else {
                l++;
            }
        }
        ans += cnt;
    }
    cout << ans << enl;
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