//在数组中找i和j，使l <= ai + aj <= r，统计配队的i和j的个数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll search(const vector<ll> &a, int n) { 
    int right = a.size() - 1;
    ll res = 0;
    for (int left = 0; left < a.size() - 1; left++) {
        while (left < right && a[left] + a[right] > n) right--;
        res += max(0, right - left); //计数小于n的数的个数
    }
    return res;
}
//通过差分，获得[l, r]的数
ll solve(const vector<ll> &a, int l, int r) {
    return search(a, r) - search(a, l - 1);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        cout << solve(nums, l, r) << '\n';
    }
    return 0;
}