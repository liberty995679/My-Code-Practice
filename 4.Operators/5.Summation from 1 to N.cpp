//计算1到n的总和
#include <iostream>
using namespace std;
int main() {
    long long n, sum;
    cin >> n;
    sum = n * (n + 1) / 2;
    cout << sum << endl;
    return 0;
}