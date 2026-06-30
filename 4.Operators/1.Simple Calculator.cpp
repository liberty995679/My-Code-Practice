//分别计算xy的加减乘法
#include <iostream>
using namespace std;
int main() {
    long long x, y;
    cin >> x >> y ;
    printf("%lld + %lld = %lld\n", x, y, x + y);
    printf("%lld * %lld = %lld\n", x, y, x * y);
    printf("%lld - %lld = %lld\n", x, y, x - y);
    return 0;
}