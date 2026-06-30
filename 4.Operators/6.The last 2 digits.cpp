//相乘取最后两位数
#include <iostream>
using namespace std;
int main() {
    long long a, b, c, d, mul;
    cin >> a >> b >> c >> d;
    a = a % 100;
    b = b % 100;
    c = c % 100;
    d = d % 100;
    mul = a * b * c * d;
    int num = mul % 100;
    if(num < 10) {
        cout << "0";
    }
    cout << num << endl;
    return 0;
}