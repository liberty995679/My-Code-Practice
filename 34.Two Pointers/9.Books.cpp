//读书，求valera最多能读多少本书,她花时间t去读书，在n本书里从i开始连续读书，花费的时间<=t
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int solve (const vector<ll> &a, int t) {
    int n = a.size();
    int l = 0;
    ll res = 0;
    int cnt = 0;
    for (int r = 0; r < n; r++) {
        res += a[r];
        while (res > t) {
            res -= a[l];
            l++;
        }
        cnt = max(cnt, r - l + 1);
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<ll> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums, t) << '\n';
    return 0;
}