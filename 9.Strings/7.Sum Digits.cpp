//对输入的字符串的每一个数字进行相加
#include <iostream>
#include <string>

using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int a = s[i] - '0';
        sum += a;
    }
    cout << sum << endl;
    return 0;
}