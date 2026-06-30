//给a和b，根据公式(a ^ x) + (b ^ x)，求出它的最小值，x可以是任意的
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr); //其实就是a和b的异或
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (a ^ b) << endl;
    }
    return 0;
}