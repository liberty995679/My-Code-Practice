//雅典的七个男孩和七个女孩被带到米诺斯国王面前。邪恶的国王大笑着说："希望你们在克里特岛过得愉快。
//随着 "哐当 "一声巨响，他们身后的大门关上了，黑暗笼罩了大地。吓坏了的孩子们挤在一起。在远处，他们听到了吼叫声、邪恶的咆哮声。
//他们勇敢地向前迈进，走向厄运。
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

//也许你还记得牛头怪的故事？从牛头怪手中救出孩子们的英雄却鲜为人知：他的名字叫特修斯。
//这个问题只是一个关于 "theseus "的单词搜索（横向、纵向、对角线）。当你搜索一个单词时，你应该只向前走。

void solve(){
    int n;
    cin >> n;
    string s;
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j];
        }
    }
    string target = "theseus";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //横向 
            if (i <= n - 7) {
                string a = "";
                for (int k = 0; k < 7; k++) {
                    a += g[i + k][j];
                }
                if (a == target) {
                    cout << "YES" << enl;
                    return;
                }
            }
            //纵向
            if (j <= n - 7) {
                string a = "";
                for (int k = 0; k < 7; k++) {
                    a += g[i][j + k];
                }
                if (a == target) {
                    cout << "YES" << enl;
                    return;
                }
            }
            //斜向
            if (i <= n - 7 && j <= n - 7) {
                string a = "";
                for (int k = 0; k < 7; k++) {
                    a += g[i + k][j + k];
                }
                if (a == target) {
                    cout << "YES" << enl;
                    return;
                }
            }
        }
    }
    cout << "NO" << enl;
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