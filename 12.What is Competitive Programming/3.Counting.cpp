//统计a到b之间的数，包含a和b
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a > b) cout << 0 << endl;
    else cout << b - a + 1 << endl;
    return 0;
}