//差分,在ab之间添加数字k，输出数组的最大值
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> diff(n + 2);
    vector<ll> a(n + 2);
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;
        diff[a] += k;
        diff[b + 1] -= k;
    }
    ll maxnum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + diff[i];
        maxnum = max(maxnum, a[i]);
    }
    cout << maxnum << endl;
    return 0;
}