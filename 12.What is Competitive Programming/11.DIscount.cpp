//计算折扣力度，输出为百分数
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(10) << endl;
    cout << (a - b) / a * 100 << endl;
    return 0;
}