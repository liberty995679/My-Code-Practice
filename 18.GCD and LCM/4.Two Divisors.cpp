//给出两个最大因子，求原数字
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (a % b) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }return b;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b) * b);
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
        ll a, b;
        cin >> a >> b;
        if (b % a == 0) {
            ll x = b / a * b;
            cout << x << '\n';
        } else {
            cout << lcm(a, b) << '\n';
        }
    }
    return 0;
}
