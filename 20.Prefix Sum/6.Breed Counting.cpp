//根据牛的种类进行分类，并计算他们在不同区间的数量
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    freopen("bcount.in", "r", stdin);  //输入来自 bcount.in
    freopen("bcount.out", "w", stdout); //输出写到 bcount.out
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> num(n + 1);
    vector<int> sum1(n + 1, 0);
    vector<int> sum2(n + 1, 0);
    vector<int> sum3(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        sum3[i] = sum3[i - 1];
        if (num[i] == 1) sum1[i]++;
        else if (num[i] == 2) sum2[i]++;
        else sum3[i]++;
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        int res1 = sum1[r] - sum1[l - 1];
        int res2 = sum2[r] - sum2[l - 1];
        int res3 = sum3[r] - sum3[l - 1];
        cout << res1 << ' ' << res2 << ' ' << res3 << '\n';
    }
    return 0;
}
