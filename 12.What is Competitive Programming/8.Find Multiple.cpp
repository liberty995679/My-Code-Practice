//找a和b之间的c的一个倍数，输出一个就行
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
    bool flag = false;
    for (int i = a; i <= b; ++i) {
        if (i % c == 0) {
            flag = true;
            cout << i << endl;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}