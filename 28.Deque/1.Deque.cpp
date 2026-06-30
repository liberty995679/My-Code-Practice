//有一个初始为空的整型序列 a=()。处理 Q个查询。
//0 x：将整数 x添加到序列 a的开头。
//1 x：将整数 x添加到序列 a的末尾。
//2：删除序列 a开头的整数。
//3：删除序列 a末尾的整数。
//4 i：设此时 a=(a0,…,an−1)，输出 ai
//约束条件​1≤Q≤5×1e5 0≤x≤1e9
//当查询 2、3 或 4 到来时，序列 a不为空。
//当查询 4 到来时，0≤i<∣a∣成立。
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int a, n;
    queue<int> q;
    for (int i = 0; i < t; i++) {
        cin >> a;
        if (a == 1)  {
            cin >> n;
            q.push(n);
        } else if (a == 2) {
            if (!q.empty()) {
                q.pop();
            }
        } else {
            if (!q.empty()) {
                cout << q.front() << '\n';
            } else {
                cout << "Empty!" << '\n';
            }
        }
    }
    return 0;
}