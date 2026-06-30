//前缀和,输出ab区间的数字和
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve(const vector<ll> &sum, ll a, ll b) { //sum为引用传递,如果是按值传递复杂度是On
    cout << sum[b] - sum[a - 1] << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vector<ll> num(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    vector<ll> sum(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + num[i];
    }
    while (q--) {
        ll a, b;
        cin >> a >> b;
        solve(sum, a, b);
    }
    return 0;
}
