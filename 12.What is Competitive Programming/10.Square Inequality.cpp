//判断a平方与b平方的和是否小于c平方
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    if (a * a + b * b < c * c) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}