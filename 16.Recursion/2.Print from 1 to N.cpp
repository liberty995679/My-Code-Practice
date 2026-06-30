//递归，输出1到n
#include <iostream>

using namespace std;

void solve(int n) {
    if (n == 0) return;
    solve(n - 1);
    cout << n << endl;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n);
    return 0;
}