//序列a默认包含一个0
//输入长度n 和字符串s
//对于i 从1到n 当s[i] == L 则i要放在i - 1的左边 ,即1在0的左边
//反之亦然
//计算结果，输出数组
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
    int n;
    string s;
    cin >> n >> s;
    list<int> deq;
    deq.push_back(0);
    auto pos = deq.begin();
    int cur = 1;
    for (char c: s) {
        if (c == 'L') {
            pos = deq.insert(pos, cur);
           // deq.insert(deq.begin() + last, cur); 这个deque是O(n) 太慢用list
        } else {
            deq.insert(next(pos), cur); //获取迭代器的下一个元素
            pos = next(pos);
        }
        cur++;
    }
    for (auto i: deq) {
        cout << i << ' ';
    }cout << enl;
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