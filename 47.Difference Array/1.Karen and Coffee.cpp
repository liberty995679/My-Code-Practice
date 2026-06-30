//差分，喝咖啡，在a和b的温度之间的可接受的咖啡数量
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 2e5 + 3;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> diff(MAX);
    vector<int> a(MAX);
    vector<int> prefix(MAX);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        diff[r + 1] -= 1;  //差分记录变化量
    }
    for (int i = 1; i < MAX; i++) {
        a[i] = a[i - 1] + diff[i];   //还原数组
        prefix[i] = prefix[i - 1] + (a[i] >= k ? 1: 0); //判断数量是否达标，再前缀和+1
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
    return 0;
}