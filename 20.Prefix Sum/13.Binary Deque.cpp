//输入一堆二进制数，只能删除头和尾的数字，计算最小步数使其总和等于s
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {    //把问题看成保留一个连续子数组其和为 s，删除其余元素
        int n, s;
        cin >> n >> s;
        vector<int> num (n);
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        int left = 0;
        int sum = 0;
        int maxnum = -1;
        for (int r = 0; r < n; ++r) {
            sum += num[r];    //向右扩
            while (sum > s) {
                sum -= num[left];  //滑动窗口收缩
                left++;
            } 
            if (sum == s) {  //满足条件，求最大长度
                maxnum = max(maxnum, r - left + 1);
            }
        }
        cout << ((maxnum == -1) ? -1 : n - maxnum) << '\n';
    }
    return 0;
}