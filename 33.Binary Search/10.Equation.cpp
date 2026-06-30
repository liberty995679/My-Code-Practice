//已知x的平方加根号x等于c,输入c，求x ,(1.0 <= c <= 1e10)
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

double solve (double n) {
    double l = 0; double r = sqrt(n);
    while (r - l > 1e-6) {
        double x = l + (r - l) / 2;
        if (x * x + sqrt(x) >= n) r = x;
        else l = x;  //浮点二分不能加一
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double c;
    cin >> c;
    cout << fixed << setprecision(6);  //控制精度输出
    cout << solve(c) << endl;
}