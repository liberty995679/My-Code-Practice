//指针，输出a + b，|a - b|
#include <iostream>
#include <algorithm>

using namespace std;

void solve(int *a, int *b) {
    cout << *a + *b << endl;
    cout << abs(*a - *b) << endl;
    return;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    solve(&a, &b);
    return 0;
}
