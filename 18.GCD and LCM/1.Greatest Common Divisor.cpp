//找a b的最大因子
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

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}