//递归，斐波那契数列
#include <iostream>

using namespace std;
using ll = long long;

ll fbnq(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fbnq(n - 1) + fbnq(n - 2);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << fbnq(n) << endl;
    return 0;
}