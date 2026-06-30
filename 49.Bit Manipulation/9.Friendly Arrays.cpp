//可以选择b数组的任意一个元素使得ai = ai|bj,也可以不选
//而x=a1^a2^...^an, 输出x的最大和最小值
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int> &a, const vector<int> &b) { 
    int x = 0;
    int an = a.size(); int bn = b.size();
    int all_b = 0;
    int minnum = 0; int xora = 0; int xor1 = 0;
    for (int i = 0; i < bn; i++) all_b |= b[i];
    for (int i = 0; i < an; i++) {
        xora ^= (a[i] | all_b);
    }
    for (int i = 0; i < an; i++) {
        xor1 ^= a[i];
    }
    if (an % 2 == 0) minnum = xora;
    else minnum = xor1;
    int maxnum = 0;
    for (int bit = 0; bit < 30; bit++) {
        int cnt = 0;
        for (int i = 0;i < an; i++) {
            if (a[i] & (1 << bit)) cnt++;
        }
        bool flag = false;
        for (int i = 0; i < bn; i++) {
            if (b[i] & (1 << bit)) { //判断bi的bit位是否为1
                flag = true;
                break;
            }
        }
        if (flag) {  //如果是，则可以设置,两个选择全1，或者保持不变
            int op1 = an % 2;    //有n个数，它们的数位都变1，全1，然后判断是否为奇数
            int op2 = cnt % 2;
            if (op1 == 1 || op2 == 1) {
                maxnum |= (1 << bit);
            }
        } else {
            if (cnt % 2 == 1) {
                maxnum |= (1 << bit);
            }
        }
    }
    cout << minnum << ' ' << maxnum << endl;
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < m; j++) cin >> b[j];
        solve(a, b);
    }
    return 0;
}