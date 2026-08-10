// Kostya 有一段文本 s，由 n 个单词组成，单词只包含拉丁字母。他还有两条纸条，必须把这段文本写上去。第一条纸条最多只能写 m 个字符，第二条纸条长度不限。
// Kostya 需要选择一个数字 x，把原文的前 x 个单词写到第一条纸条上，剩下的单词写到第二条纸条上。为了节省空间，单词之间不写空格，但每个单词必须完整地写在同一条纸条上（不能把一个单词拆开写到两条纸条上）。
// 因为第二条纸条的空间非常宝贵，请你帮 Kostya 选一个尽可能大的 x，使得前 x 个单词 s1, s2, …, sx 的总长度不超过 m。
// 输入格式
// 第一行是一个整数 t（1 ≤ t ≤ 1000）—— 测试用例的数量。
// 每个测试用例的第一行包含两个整数 n 和 m（1 ≤ n ≤ 50；1 ≤ m ≤ 500）—— 单词总数，以及第一条纸条最多能容纳的字符数。
// 接下来 n 行，每行一个单词 si，只包含小写拉丁字母，且每个单词的长度不超过 10。
// 输出格式
// 对于每个测试用例，输出一个整数 x，表示最多能写在第一条纸条上的单词数量，使得这前 x 个单词的总长度不超过 m。
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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> vec;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        vec.push_back(a);
    }
    int total = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].size() + total <= m) {
            total += vec[i].size();
            res++;
        } else {
            break;
        }
    }
    cout << res << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}