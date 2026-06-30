//n<1e15,奇数位是负数，偶数位是正数，计算总和
#include <iostream>

using namespace std;
using ll = long long;

ll fn(ll a) {
    ll res;
    if (a & 1) return (a - 1) / 2 - a;
    return a / 2;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << fn(n) << endl;
    return 0;
}