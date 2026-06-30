//双指针,求数组中的子数组总和等于x的数组个数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int solve(const vector<ll> &a, int x) {
    ll sum = 0;
    int n = a.size();
    int l = 0;
    int cnt = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= x) {
            if (sum == x) cnt++;
            sum -= a[l];
            l++;
        }
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << solve(nums, x) << endl;
    return 0;
}