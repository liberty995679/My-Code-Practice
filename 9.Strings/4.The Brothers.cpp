//输入两个人的姓名，判断他们是不是兄弟
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2, f1, f2;
    getline(cin, f1);
    getline(cin, f2);
    int a = f1.find(" ");
    int b = f2.find(" ");
    s1 = f1.substr(a + 1);
    s2 = f2.substr(b + 1);
    int result = s1.compare(s2);
    if (result == 0) {
        cout << "ARE Brothers" << endl;
    } else {
        cout << "NOT" << endl;
    }
    return 0;
}