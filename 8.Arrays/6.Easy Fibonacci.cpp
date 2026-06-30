//斐波那契数列
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 0 << " ";
            a = 0;
        } else if (i == 2) {
            cout << 1 << " ";
            b = 1;
        } else {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
    return 0;
}