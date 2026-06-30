//这是一道编程题的描述，以下是中文翻译：
//编写一个程序，从整数序列中移除所有重复项，并打印输入序列中出现的唯一整数列表，以及每个整数的出现次数。
//输入
//输入文件将包含一个整数序列（正数、负数和/或零）。输入文件可能任意长。
//输出
//程序的输出将是一系列有序对（ordered pairs），用换行符分隔。
//每对的第一个元素必须是来自输入文件的整数。
//第二个元素是该特定整数在输入文件中出现的次数。
//每对中的元素之间用空格分隔。
//整数的输出顺序应与它们在输入文件中首次出现的顺序一致。
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
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int x;
    map<int, int> mp;
    vector<int> order;
    while (cin >> x) {
        if (mp.find(x) == mp.end()) order.push_back(x);
        mp[x]++;
    }
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << ' ' << mp[order[i]] << enl;
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