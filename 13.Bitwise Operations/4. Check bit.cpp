//输入n,i,判断n的第i位是否存在
#include <iostream>

using namespace std;

void check (int n, int i) {
    if (n & 1 << i) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int n, i;
    cin >> n >> i;
    check(n, i);
    return 0;
}