//计算输入的数字总和的绝对值
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int main() {
    int n;
    ll res = 0;
    cin >> n;
    int num[N] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        res += num[i];
    }
    cout << abs(res) << endl;
    return 0;
}