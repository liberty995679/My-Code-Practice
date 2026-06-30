//差分,计算光顾餐馆的顾客最大人数,输入顾客的到达离开时间
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

struct customer
{
    int arrival;
    int leaving;
};


int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<customer> people(n);
    vector<int> times;   //存时间点
    for (int i = 0; i < n; i++) {   // 离散化差分
        cin >> people[i].arrival >> people[i].leaving;
        times.push_back(people[i].arrival);
        times.push_back(people[i].leaving + 1);  //b+1加入数组
    }
    sort(times.begin(), times.end());   //排序 , 去重
    times.erase(unique(times.begin(), times.end()), times.end());
    int len = times.size();
    map<int, int> index;  // 存数值和坐标
    for (int i = 0; i < len; i++) {
        index[times[i]] = i;
    }
    vector<ll> diff(len + 1);  //差分数组
    for (const auto &i: people) {  //读取
        int apos = index[i.arrival];
        int b_pos = index[i.leaving + 1]; //差分b+1
        diff[apos] += 1;
        diff[b_pos] -= 1;
    }
    ll maxnum = 0;
    ll num = 0;
    for (int i = 0; i < len; i++) {  //从位置0开始计算前缀和
        num += diff[i];
        maxnum = max(maxnum, num);  //更新最大值
    }
    cout << maxnum << endl;
    return 0;
}