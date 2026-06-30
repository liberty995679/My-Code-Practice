//将数组分成三份,使得sum1=sum3,且sum1尽可能最大
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll solve(const vector<ll> &a) {   //双指针
    ll sum1 = 0;
    ll sum3 = 0;
    ll ans = 0;
    int l = 0;
    int n = a.size();
    int r = n - 1;
    while (l <= r) {
        if (sum1 == sum3) ans = max(ans, sum1);
        if (sum1 <= sum3) {
            sum1 += a[l];
            l++;
        }
        else {
            sum3 += a[r];
            r--;
        }
    }
    if (sum1 == sum3) ans = max(ans, sum1);
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << solve (nums) << endl;
    return 0;
}