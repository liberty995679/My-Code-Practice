//判断n和m相等

#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}