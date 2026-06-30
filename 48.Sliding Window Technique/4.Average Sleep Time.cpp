//将k个连续的数视为一周总和，周数为n-k+1,求平均数
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
#define int long long

void solve(const vector<int> &a, int k) {
    int n = a.size();
    int l = 0;
    int sum = 0;
    double ans = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (r - l + 1 > k) {
            sum -= a[l];
            l++;
        }
        if (r - l + 1 == k) {
            ans += (double)sum / (n - k + 1);
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}

signed main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    solve(nums, k);
    return 0;
}