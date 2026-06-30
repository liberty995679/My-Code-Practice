//给数组中的数每次加一，使整个数组升序，求最少操作次数
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
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    ll cnt = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            ll x = nums[i - 1] - nums[i];
            cnt += x;
            nums[i] += x;
        }
    }
    cout << cnt << endl;
    return 0;
}