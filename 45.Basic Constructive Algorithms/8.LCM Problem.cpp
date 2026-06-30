//输入l,r,输出x,y,满足l <= x < y <= r, l <= lcm(x,y) <= r,否则输出-1 -1
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void solve(int l, int r) {
    if (2 * l <= r) {      //如果满足条件，说明存在lcm(l, 2l) = 2l <= r
        for (int x = l; x < r; x++) {
            for (int y = 2 * l; y <= r; y++) {
                if (lcm(x, y) >= l && lcm(x, y) <= r) {
                    cout << x << ' ' << y << endl;
                    return;
                }
            }
        }
    } else {
        cout << -1 << ' ' << -1 << endl;
    }
    return;
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
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}