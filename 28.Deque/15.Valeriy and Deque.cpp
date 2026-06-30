#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    int n, q, num;
    scanf("%d %d", &n, &q);
    deque<int> dq1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        dq1.push_back(num);
    }
    vector<pair<int, int>> qianmian; //保存前面n-1的数据
    deque<int> ddqq =dq1;
    for (int i = 0; i < n - 1; i++) {
        int q1 = ddqq.front();
        ddqq.pop_front();
        int q2 = ddqq.front();
        ddqq.pop_front();
        if (q1 > q2) {
            ddqq.push_front(q1);
            ddqq.push_back(q2);
        } else {
            ddqq.push_front(q2);
            ddqq.push_back(q1);
        }
        qianmian.push_back({q1, q2});
    }
    int a1 = ddqq.front();
    ddqq.pop_front();
    vector<int> s(ddqq.begin(), ddqq.end()); //把最大的取出来之后进行原顺序存储
    while (q--) {
        long long m;
        long long t = 0;
        int a, b;
        scanf("%lld", &m);
        if (m < n) {
            a = qianmian[m - 1].first;
            b = qianmian[m - 1].second;
            printf("%d %d\n", a, b);
        } else {
            a = a1;
            int idx = (m - n) % (n - 1); 
            b = s[idx];
            printf("%d %d\n", a, b);
        }  
        
    }
    return 0;
}