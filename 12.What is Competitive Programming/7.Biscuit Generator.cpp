//a秒生产b个饼干，输出t加0.5秒生产多少个饼干
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, t;
    cin >> a >> b >> t;
    if (a > t) cout << 0 << endl;
    else {
        int x = (t + 0.5) / a;
        cout << x * b << endl;
    }
    return 0;
}