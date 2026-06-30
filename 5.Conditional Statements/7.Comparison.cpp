//判断数学表达式是否正确
#include <iostream>

using namespace std;

int main() {
    int a, b;
    char s;
    cin >> a >> s >> b;
    if (s == '>') {
        if (a > b) cout << "Right" << endl;
        else cout << "Wrong" << endl;
    } else if (s == '<') {
        if (a < b) cout << "Right" << endl;
        else cout << "Wrong" << endl;
    } else {
        if (a == b) cout << "Right" << endl;
        else cout << "Wrong" << endl;
    }
    return 0;
}