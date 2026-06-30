//递归，输出n到1
#include <iostream>

using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << 1;
        return;
    };
    cout << n << ' ';
    solve(n - 1);
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