//根据给的节点判断网络拓扑结构
//bus topology,ring topology,star topology
//如果不是总线，环状，星状，则是未知，unknown topology
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m; //n个节点，m个边
    vector<int> arr(n + 1); //每个点的度
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x]++;
        arr[y]++;
    }
    int cnt1 = 0; int cnt2 = 0; int cntn1 = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 1) cnt1++;
        else if (arr[i] == 2) cnt2++;
        else if (arr[i] == n - 1) cntn1++;
    }
    if (cnt2 == n - 2 && cnt1 == 2) { //头和尾度为1
        cout << "bus topology" << endl;
    } else if (cnt2 == n){   //度为2的数量有n个
        cout << "ring topology" << endl;
    } else if (cntn1 == 1 && cnt1 == n - 1) {
        cout << "star topology" << endl;  //有n-1个度为1
    } else {
        cout << "unknown topology" << endl;
    }
}