//前缀和，更改数组l-r区间的值为k，判断数组总和是否为奇数
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> num(n + 1);
        vector<ll> sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            sums[i] = sums[i - 1] + num[i];
        }
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            ll sum = sums[n] - (sums[r] - sums[l - 1]);
            sum = sum + (k * (r - l + 1));
            if (sum & 1) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
