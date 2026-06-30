//找索引配队，满足ai < i < aj < j,输出数量
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve(const vector<ll> &a) {  //拆解，先找ai < i 然后再找aj < j
    ll cnt = 0;
    ll n = a.size();
    vector<ll> b, res;
    for (ll i = 1; i < n; i++) {   //把满足 a[i] < i 的索引存入了 b
        if (a[i] < i) b.push_back(i);   //当我们在其中选择 j 时，它自动满足 a[j] < j
    }
    for (ll i: b) {    //b存的索引，res存数值，并排序
        res.push_back(a[i]);
    }
    sort(res.begin(), res.end());
    for (ll i : b) {
        auto it = upper_bound(res.begin(), res.end(), i);
        cnt += (ll)(res.end() - it);
    }
    return cnt;
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
        ll n;
        cin >> n;
        vector<ll> nums(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> nums[i];
        }
        cout << solve(nums) << '\n';
    }
    return 0;
}