//二分查找，多台机器同时工作，输出生产目标产品数量所需的最短时间
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, t;
    cin >> n >> t;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll left = 1;
    ll right = *min_element(nums.begin(), nums.end()) * t; //效率最高的机器生产全部产品的时间
    ll res = right;
    while (left <= right) {
        ll total = 0;
        ll mid = left + (right - left) / 2;
        for (const auto& a : nums) {
            total += (mid / a);   //计算当前mid秒内所生产的产品
            if (total >= t) break;
        }
        if (total >= t) {
            res = mid;
            right = mid - 1;
        } else left = mid + 1;
    }

    cout << res << endl;
    return 0;
}