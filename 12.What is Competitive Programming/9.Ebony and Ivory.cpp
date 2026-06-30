//分配a和b，使其能够等于c
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
    for (int i = 0; i <= c / a; i++) {
        for (int j = 0; j <= c / b; j++) {
            int result = a * i + b * j;
            if (result == c) {
                flag = true;
                break;
            }
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}