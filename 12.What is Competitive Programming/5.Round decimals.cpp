//对一个浮点数进行四舍五入
#include <iostream>
#include <cmath>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double x;
    cin >> x;
    cout << round(x) << endl;
    return 0;
}