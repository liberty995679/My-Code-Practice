//打印字符串的长度和拼接
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string c = a + " " + b;
    cout << a.size() << " " << b.size() << endl;
    cout << c << endl;
    return 0;
}