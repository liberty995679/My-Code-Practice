//递归，使用阶乘
#include <iostream>

using namespace std;
using ll = long long;

ll solve(int n) {
    if (n == 1 | n == 0) return 1;
    return n * solve(n - 1);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}