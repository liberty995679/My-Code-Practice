//输入a和b，判断a是否能转换为b
//有两种方式，乘以2(2*x)或者往右边加一(10*x + 1)
//输出NO或者YES , 输出转换过程的次数和所有数
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
const int MAXIN = 1e5 + 1;
vector<int> adj[MAXIN];
int a, b;
bool flag = false;
stack<int> st;
void dfs(int b) {
    if (b == a) {
        st.push(b);
        flag = true;
        return;
    }
    if (b < a) return;   //剪枝
    if (b % 10 == 1) {
        int x = (b - 1) / 10;
        st.push(b);
        dfs(x);
        if (flag) return;  //找到了则返回
        st.pop();   //回溯
    } if (b % 2 == 0) {
        int x = b / 2;
        st.push(b);
        dfs(x);
        if (flag) return;
        st.pop();
    }
}

void solve(int a, int b) {
    dfs(b);
    if (flag) {
        cout << "YES" << endl;
        cout << st.size() << endl;
        while (!st.empty()) {
            int top = st.top();
            cout << top << ' ';
            st.pop();
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    solve(a, b);
    return 0;
}