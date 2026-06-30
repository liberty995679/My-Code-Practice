//给定一个大小为 n 的数组 a 和一个整数 k。你可以执行以下操作任意次数：
//选择两个整数 l 和 r（1≤l≤r≤|a|），使得 r−l+1≥k。
//然后，选择一个下标 i（l≤i≤r），使得 a_i 是子数组 [a_l, a_{l+1}, …, a_r] 中的第 k 小元素。如果有多个可能的 i，你可以任选一个。例如，考虑 a=[1,2,2,1,3]，l=1，r=5，k=3，i 的可能候选下标是 2 和 3。
//然后，从 a 中删除 a_i，并将数组的剩余部分拼接起来。
//判断在任意次操作后，是否有可能得到一个回文数组*。注意空数组被视为回文。
//*如果对于每个 1≤i≤m，都有 b_i = b_{m+1−i}，则数组 b=[b_1,b_2,…,b_m] 是回文。
//Input
//每个测试包含多组测试用例。第一行给出测试用例的数量 t（1≤t≤10^4）。接下来是各测试用例的描述。
//第一行给出两个整数 n 和 k（1≤k≤n≤2·10^5）。
//第二行给出 n 个整数 a_1,a_2,…,a_n（1≤a_i≤n）——表示数组 a。
//保证所有测试用例中 n 的总和不超过 2·10^5。
//Output
//对于每个测试用例，如果可以创建回文数组，输出 YES，否则输出 NO。大小写不敏感，例如 yEs、yes、Yes、YES 都视为肯定回答。
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> cnt;
    if (k == 1) {
        cout << "YES" << enl;
        return;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    int cur = b[k - 2]; //就是第k - 1小的元素, 因为是0st 所以是k - 1个元素永远删不掉
    vector<int> res;
    for (int i: a) {
        if (i <= cur) { //> cur 的我们已经“假装全删了”（没放进 res）
            res.push_back(i);
        }
    }
    int l = 0; int r = res.size() - 1;
    int space = res.size() - (k - 1); //还能删除多少
    bool flag = true;
    while (l < r) {
         if (res[l] != res[r]) {
            if (space == 0) {
                flag = false; 
                break;
            }
            if (res[l] == cur) {  //< cur 的不能删 唯一还能操作的就是 = cur
                l++;
                space--;
            } else if (res[r] == cur) {
                r--;
                space--;
            } else {
                flag = false;
                break;
            }
            continue;
        }
        l++;
        r--;
    }
    if (flag) cout << "YES" << enl;
    else cout << "NO" << enl;
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