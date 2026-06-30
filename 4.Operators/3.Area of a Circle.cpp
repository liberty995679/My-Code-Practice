//计算圆的面积保留9位小数
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << fixed << setprecision(9);
    const double pi = 3.141592653;
    double r, area;
    cin >> r;
    area = pi * r * r;
    cout << area <<endl;
    return 0;
}