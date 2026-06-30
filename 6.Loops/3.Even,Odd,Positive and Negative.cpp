//给输入的数字进行奇偶数计数和正负数计数
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int even = 0;int odd = 0; int positive = 0; int negative = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 0) even++;
        else odd++;
        if (num > 0) positive++;
        else if (num < 0) negative++;
    }
    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
    cout << "Positive: " << positive << endl;
    cout << "Negative: " << negative << endl;
    return 0;
}