//判断浮点数与整数是否相等
#include <iostream>
using namespace std;
const double eps = 1e-6;
int main() {
    double num;
    cin >> num;
    int intnum = (int)num;
    if (num - intnum < eps) cout << "int " << intnum << endl;
    else cout << "float " << intnum << " " << num - intnum << endl;
    return 0;
}