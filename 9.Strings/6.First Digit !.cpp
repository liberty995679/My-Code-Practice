//判断输入的字符串类型的数字第一位是奇数还是偶数
#include <iostream>
#include <string>

using namespace std;


int main() {
    string s;
    cin >> s;
    if (s[0]- '0' & 1) cout << "ODD" << endl;
    else cout << "EVEN" << endl;
    return 0;
}