//抓青蛙，每个青蛙都从坐标0开始按照固定的跳跃长度进行跳跃
//只放一个陷阱坐标，范围在1-n，输出能抓住青蛙数量最多的一个坐标
#include <iostream>
#include <vector>

using namespace std;

void solve (vector<int> a, int n) {
    vector<int> frog_count(n + 1, 0); // 统计每个步长出现的频率
    for(int i = 0; i < n; ++i) {
        if (a[i] <= n) {
            frog_count[a[i]]++;
        }
    }
    int max = 0;
    for (int p = 1; p <= n; ++p) { //枚举每一个可能放陷阱的位置
        int res = 0;    //统计在当前位置能抓几只
        for (int j = 1; j * j <= p; j ++) { //j是p的因子
            if (p % j == 0) {
                res += frog_count[j];
                if (j != p / j) res += frog_count[p / j];
            }
        }
        if (res > max) max = res;
    }
    cout << max << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0); //青蛙跳跃长度
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(a, n);
    }
    return 0;
}
