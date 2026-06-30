//线段树,区间求和，单点更新
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

const int MAXN = 100005;
vector<int> a(MAXN);         // 原始数组
ll tree[4 * MAXN]; // 线段树数组

/**
 * @brief 合并左右子节点的信息
 */
void push_up(int u) {
    tree[u] = tree[u * 2] + tree[u * 2 + 1];
}

/**
 * @brief 构建线段树
 * @param u 当前节点编号
 * @param l 当前节点代表的区间的左端点
 * @param r 当前节点代表的区间的右端点
 */
void build(int u, int l, int r) {
    if (l == r) {
        tree[u] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    push_up(u);
}

/**
 * @brief 单点更新
 * @param u 当前节点编号
 * @param l, r 当前节点的区间
 * @param idx 要更新的原始数组的索引
 * @param val 更新后的值
 */
void update(int u, int l, int r, int idx, int val) {
    if (l == r) {
        tree[u] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(u * 2, l, mid, idx, val);
    } else {
        update(u * 2 + 1, mid + 1, r, idx, val);
    }
    push_up(u);
}

ll query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[u];
    }
    int mid = (l + r) / 2;
    ll sum = 0;
    if (ql <= mid) {
        sum += query(u * 2, l, mid, ql, qr);
    }
    if (qr > mid) {
        sum += query(u * 2 + 1, mid + 1, r, ql, qr);
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;  
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            update(1, 0, n - 1, x, y);
        } else {
            ll res = query(1, 0, n - 1, x, y - 1);
            cout << res << endl;
        }
    }
}