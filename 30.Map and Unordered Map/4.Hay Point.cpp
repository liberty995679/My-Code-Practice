//这是一道编程题的描述，以下是中文翻译：
//每个员工都有一份职位描述，其中包含几段描述工作职责的文字。员工的职位描述，结合资历等其他因素，被用来确定其薪资。
//Hay Point 系统将人力资源部门从对员工价值做出主观判断的任务中解放出来；它只需扫描职位描述，寻找表明职责的单词和短语即可。具体来说，那些表明掌控大额预算或管理大量人员的职位描述，会在 Hay Point 系统中产生高分。
//你需要实现 Hay Point 系统的一个简化版本。
//你会得到一个 Hay Point 字典和若干份职位描述。对于每一份描述，你需要根据该系统计算相关的薪资。
//输入的第一行包含 2 个正整数：
//m≤ 1000，Hay Point 字典中的单词数量。
//n≤ 100，职位描述的数量。
//接下来是 m行；每行包含：
//一个单词（最多 16 个小写字母的字符串），
//一个美元数值（0 到 1,000,000 之间的实数）。
//在字典之后，是接下来的 n份职位描述。每份描述由一行或多行文本组成。为了方便起见，文本已转换为小写，并且除了字母、数字和空格外没有其他字符。
//每份描述都以包含一个句号（.）的行结束。
//对于每一份职位描述，打印对应的薪资，该薪资计算为描述中出现的所有单词的 Hay Point 值之和。未出现在字典中的单词值为 0。
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
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < m; i++) {
        string s; int c;
        cin >> s >> c;
        mp[s] = c;
    }
    for (int i = 0; i < n; i++) {
        string s;
        int sum = 0;
        while (cin >> s) {
            if (s == ".") break;
            if (mp.find(s) != mp.end()) sum += mp[s];
        }
        cout << sum << enl;
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