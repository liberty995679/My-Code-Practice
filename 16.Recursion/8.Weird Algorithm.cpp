//递归，如果是偶数，就除以2，如果是奇数就乘3加1
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve (ll n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n & 1) {
        cout << n << " ";
        solve(n * 3 + 1);
    } else {
        cout << n  << " ";
        solve(n / 2);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    solve(t);
    return 0;
}