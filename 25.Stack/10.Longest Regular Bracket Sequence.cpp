#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    stack<int> a;
    a.push(-1);
    int count_max = 0;
    int count_num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            a.push(i);  //进栈i代表坐标
        } else { //右括号
            a.pop();   
            if (a.empty()) { // 说明没有左括号进栈
                a.push(i);  
            } else {     //有左括号
                int len = i - a.top();  //i现在的坐标指向右括号，长度等于左减右
                if (len > count_max) {
                    count_max = len;
                    count_num = 1;
                } else if (len == count_max) {
                    count_num++;
                }
            }
        }
    }
    if (count_max > 0 && count_num > 0) {
        cout << count_max << " " << count_num << "\n";
    } else {
        cout << 0 << " " << 1 << "\n";
    }
    return 0;
}