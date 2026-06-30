//高桥有一个由小写英文字母组成的字符串 S。
//从这一字符串开始，他要按照如下步骤生成一个新的字符串。
//该步骤包含 Q 次操作。在第 i 次操作 (1 ≤ i ≤ Q) 中，会给出一个整数 Tᵢ，其含义如下：
//如果 Tᵢ = 1：将字符串 S 反转。
//如果 Tᵢ = 2：还会额外给出一个整数 Fᵢ 和一个小写英文字母 Cᵢ。
//如果 Fᵢ = 1：将 Cᵢ 添加到字符串 S 的开头。
//如果 Fᵢ = 2：将 Cᵢ 添加到字符串 S 的末尾。
//请帮助高桥找出经过所有步骤后最终得到的字符串。
//输入字符串s 查询q 输入t 根据t 输入f c
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    string s;
    int q;
    cin >> s >> q;
    int t, f;
    char c;
    bool flag = true; //判断是否反转
    deque<char> deq(s.begin(), s.end()); //区间构造函数
    while (q--) {
        cin >> t;
        if (t == 1) {
            flag = !flag;
        }
        if (t == 2) {
            cin >> f >> c;
            if (f == 1) {
                if (flag) deq.push_front(c);
                else deq.push_back(c);
            } else {
                if (flag) deq.push_back(c);
                else deq.push_front(c);
            }
        }
    }
    if (flag) {
        for (const auto& it: deq) {
            cout << it;
        }cout << enl;
    } else {
        while (!deq.empty()) {
            cout << deq.back();
            deq.pop_back();
        }cout << enl;
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