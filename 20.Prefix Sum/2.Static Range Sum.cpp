//前缀和，计算s[r] - s[l]
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
    int n, q;
    cin >> n >> q;
    vector<ll> num(n + 1);
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        sum[i] = sum[i - 1] + num[i];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l] << '\n';
    }
    return 0;
}