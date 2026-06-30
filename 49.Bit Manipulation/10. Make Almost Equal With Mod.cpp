//输出一个k，使得它对数组各个数取模后，刚好有两个不同的余数
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
const ll MAX = 1e18;
void solve(const vector<ll>& a) {
    int n = a.size();
    if (n == 2) {
        cout << MAX << endl;
        return;
    }
    set<ll> s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i] % 2);
    }
    if (s.size() == 2) {  //如果有奇数和偶数
        cout << 2 << endl;
        return;
    } else {  //全奇数或者全偶数,差值全是偶数
        ll maxnum = *max_element(a.begin(), a.end());
        for (ll i = 2; i <= maxnum; i *=2) {
            set<ll> yushunums;
            for (int j = 0; j < n; j++) {
                yushunums.insert(a[j] % i);
            }
            if (yushunums.size() == 2) {
                cout << i << endl;
                return;
            }
        }
    }
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
        int n;
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        solve(nums);
    }
    return 0;
}