//输入一个字符串
//将逗号转换为空格
//将大小写字母全部转换输出结果
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (char &c: s) {
        if (c == ',') c = ' ';
        else if (c >= 'a' && c <= 'z') c = toupper(c);
        else c = tolower(c);
    }
    cout << s << endl;
    return 0;
}