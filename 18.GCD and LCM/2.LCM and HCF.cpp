//找a b的最小公倍数，最大公约数
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b) { //利用公式求最小公倍数
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b) * b); //a除以最大公约数，再乘以b就是最小公倍数
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
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << " " << gcd(a, b) << '\n';
    }
    return 0;
}