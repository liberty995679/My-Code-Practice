//不断循环直到输入正确的密码1999，程序才停止
#include <iostream>

using namespace std;

int main() {
    int pwd;
    while (cin >> pwd) {
        if (pwd == 1999) {
            cout << "Correct" << endl;
            break;
        } else {
            cout << "Wrong" << endl;
        }
    }
    return 0;
}