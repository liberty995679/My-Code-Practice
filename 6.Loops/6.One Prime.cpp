//判断一个数是否为素数，例如2,3,5,7,11,13
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    int num = sqrt(n);
    for (int i = 2; i <= num; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (is_prime(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}