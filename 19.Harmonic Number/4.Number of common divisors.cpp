//计算两个数的共同因子个数
#include <iostream>

using namespace std;

int gcd (int a, int b) {
    while (a % b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return b;
}

void solve(int a) { //就是它们最大公因数的因子个数
    int total = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            total++;
            if (i != a / i) total++;
        }
    }
    cout << total << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r",  stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        solve(gcd(a, b));
    }
}