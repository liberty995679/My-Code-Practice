//递归，输出n次I love Recursion
#include <iostream>

using namespace std;

void solve(int n) {
    if (n == 0) return;
    cout << "I love Recursion" << endl;
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