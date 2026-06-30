//本题与问题 G 不同。在本题中，你必须输出在至多执行一次操作后，前缀最小值之和的最小可能值。
//给定一个长度为 n 的数组 a，其中元素满足 0≤a_i≤n。你可以至多执行一次如下操作：
//选择两个下标 i 和 j，满足 i<j。执行 a_i:=a_i+a_j，然后令 a_j=0。
//请输出 min(a_1) + min(a_1,a_2) + ... + min(a_1,a_2,...,a_n) 的最小可能值。
//Input
//每个测试包含多组测试用例。第一行给出测试用例的数量 t（1≤t≤10^4）。接下来是各测试用例的描述。
//每个测试用例的第一行给出一个整数 n（2≤n≤2·10^5）——数组 a 的长度。
//每个测试用例的第二行给出 n 个空格分隔的整数 a_1,a_2,…,a_n（0≤a_i≤n）——表示数组 a。
//保证所有测试用例中 n 的总和不超过 2·10^5。
//Output
//对于每个测试用例，在一行中输出一个整数，即 min(a_1) + min(a_1,a_2) + ... + min(a_1,a_2,...,a_n) 的最小可能值。
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    if (a[0] > a[1]) {
        sum = a[0] + a[1];
    } else {
        sum = a[0] * 2;
    }
    cout << sum << enl;
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