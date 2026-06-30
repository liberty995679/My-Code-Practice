//每个时代都有一个天选之子。她将独自对抗吸血鬼、恶魔和黑暗势力。她就是 "杀手"。- 乔斯-韦登
//输入一个长度在 3 到 7的字符串
//输出他的结果 
//一个字符串。如果没有答案，则打印 "none"（不带引号）。
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

//这句话出自著名电视剧《吸血鬼猎人巴菲》（https://en.wikipedia.org/wiki/Buffy_the_Vampire_Slayer）。
//也许你会注意到，"Buffy"、"the"、"vampire "和 "slayer "这四个词的长度是集合{3,5,6,7}中唯一的整数。
//给定字符串 $s$ ，只需将该字符串与相同长度的目标单词 "相加 "即可。
//下面是两个字母相加的方法：
//1.  将两个字母转换为 $[0,25]$ 中的数字。
//2.  将两个数字相加，取模 26。
//3.  将数字转换回字母。
//您可以通过检查 "游客 "+"吸血鬼"="oggqjx"（如示例所示）来验证您的加法运算是否正确。
//最后，如果 $s$ 的长度是 $4$ ，那么答案就是 "无"，因为《吸血鬼猎人巴菲》中没有长度为 4 的单词。

void solve(){
    string s;
    cin >> s;
    vector<string> word = {"","", "", "the", "", "buffy", "slayer", "vampire"};
    int n = s.size();
    if (n == 4) { //长度4没有结果， 因为没字符
        cout << "none" << enl;
        return;
    }
    for (int i = 0; i < n; i++) {
        char str = s[i];
        char c = word[n][i];
        int x = (str - 'a' + c - 'a') % 26;
        char goal = 'a' + x ;
        s[i] = goal;
    }
    cout << s << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}