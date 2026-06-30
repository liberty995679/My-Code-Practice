//求a ^ b的最后一位数
#include <cstdio>  //要小于700字节，所以用c风格IO
using namespace std;
using ll = long long;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        int x = b % 4;
        int res = 1;
        if (x == 0 && b != 0) x = 4;
        else if (b == 0) x = 0;
        for (int i = 0; i < x; i++) {
            res = (res * (a % 10)) % 10;  //处理溢出
        }
        printf("%d\n", res);
    }
    return 0;
}