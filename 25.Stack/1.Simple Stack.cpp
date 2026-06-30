//每一行输入命令
//push n — 将数字（值 n 在命令后给出）添加到栈中。打印 ok
//pop — 从栈中移除最后一个元素。打印该元素的值
//back — 打印最后一个元素的值，但不从栈中移除它
//size — 打印栈中元素的数量
//clear — 清空栈并打印 ok
//exit — 打印 bye 并终止
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    string s;
    int n;
    stack<int> st;
    while (cin >> s) {
        if (s == "exit") {
            cout << "bye" << endl;
            break;
        }
        if (s == "push") {
            cin >> n;
            st.push(n);
            cout << "ok" << endl;
        }
        if (s == "pop") {
            int top = st.top();
            st.pop();
            cout << top << endl;
        }
        if (s == "back") {
            int top =  st.top();
            cout << top << endl;
        } 
        if (s == "size") {
            cout << st.size() << endl;
        }
        if (s == "clear") {
            stack<int>().swap(st); //交换空栈，效率极高
            cout << "ok" << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}