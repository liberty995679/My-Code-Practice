//给一个n，如果存在ab满足a ^ b = n，输出a和b，否则输出-1
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x, y;
        bool flag = false;
        for (int a = 1; a <= n; a++) {
            y = n ^ a;
            if (y >= a && y <= n) {
                flag = true;
                x = a;
                break;
            }
        }
        if (!flag) cout << -1 << endl;
        else cout << x << ' ' << y << endl;
    }
    return 0;
}