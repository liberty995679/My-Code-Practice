//求数组的最大公约数的因子数量
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {    //全部换成ll,因为a<=1e12
    while (a % b) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }return b;
}

int solve (ll n) {
    int count = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    return count;
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
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll maxnum = nums[0];
    for (int i = 1; i < n; ++i) {
        maxnum = gcd(maxnum, nums[i]);
    }
    cout << solve(maxnum) << '\n';
    return 0;
}
