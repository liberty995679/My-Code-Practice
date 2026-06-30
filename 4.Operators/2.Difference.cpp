//给abcd，计算X = (A * B) - (C * D).
#include <iostream>
using namespace std;
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long x = (a * b) - (c * d);
    printf("Difference = %lld\n", x);
    return 0;
}