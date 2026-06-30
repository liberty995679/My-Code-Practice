//你刚从滑铁卢搬到一个大城市。这里的人说着一种难以理解的外语方言。幸运的是，你有一本词典可以帮助你理解他们。
//输入包含最多 100,000 条词典条目，后面跟一个空行，再后面是一条最多包含 100,000 个单词的消息。
//每条词典条目占一行，包含一个英文单词，后跟一个空格和一个外语单词。词典中没有外语单词会出现超过一次。
//消息是由外语单词组成的序列，每行一个单词。输入中的每个单词都是由至多 10 个小写字母组成的序列。
//输出是将这条消息翻译成英语的结果，每行一个单词。未在词典中找到的外语单词应翻译成 'eh'。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    string str;
    unordered_map<string, string> mp;
    while (true) {
        getline(cin, str);
        if (str.empty()) break;
        istringstream ss(str);
        string y, x;
        ss >> y >> x;
        mp[x] = y;
    }
    string s;
    while (cin >> s) {
        if (mp.find(s) != mp.end()) {
            cout << mp[s] << enl;
        } else {
            cout << "eh" << enl;
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