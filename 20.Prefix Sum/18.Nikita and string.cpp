//输入一个不超过5000的字符串
//仅包含小写字母 a 和 b
//将一根弦剪成三根弦(可能为空)，头尾包含a中间是b就是完美
//计算最大美丽弦线尺寸
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cntA(n + 1);
    vector<int> cntB(n + 1);
    for (int i = 1; i <= n; i++) {
        cntA[i] = cntA[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
        cntB[i] = cntB[i - 1] + (s[i - 1] == 'b' ? 1 : 0); 
    }
    vector<int> suffix(n + 2);  //表示从第i个字符到末尾中a的数量 (i从1到n)
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + (s[i - 1] == 'a' ? 1 : 0);
    }
    int  ans = 0;
    for (int L = 1; L <= n; L++) {
        for (int R = L; R <= n; R++) {
            int couA = cntA[L - 1];   //头a
            int midB = cntB[R] - cntB[L - 1];  //中间b
            int backA = suffix[R + 1];  //尾巴a
            int total = couA + midB + backA; //总长度
            ans = max(ans, total);
        }
    }
    ans = max(ans, cntA[n]); // 还要考虑只取所有a或只取所有b的情况
    ans = max(ans, cntB[n]);
    cout << ans << endl;
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