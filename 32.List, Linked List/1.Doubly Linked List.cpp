//你的任务是实现一个双向链表。
//编写程序，完成以下操作：
//insert x：将键值为 x 的元素插入到链表的头部。
//delete x：删除链表中第一个键值为 x 的元素。如果不存在这样的元素，则不需要执行任何操作。
//deleteFirst：删除链表的第一个元素。
//deleteLast：删除链表的最后一个元素。
//输入​
//输入格式如下：
//n
//command1
//commandn
//第一行给出操作的数量 n。接下来的 n 行，每行给出上述操作之一，格式为：
//insert x
//delete x
//deleteFirst
//deleteLast
//输出​
//在所有操作完成后，按顺序输出链表中所有元素的键值。相邻两个键值之间用一个空格分隔。
//约束条件​
//操作数量 ≤ 2,000,000
//删除类操作（delete、deleteFirst、deleteLast）的数量 ≤ 20
//键值的范围为 0 ≤ 键值 ≤ 10^9
//链表中的元素数量不超过 10^6
//对于 delete、deleteFirst 或 deleteLast 操作，链表中至少有一个元素。
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <bitset>
using namespace std;
const char enl = '\n';

void solve() {
	list<int> lis;
	int q;
	cin >> q;
	while (q--) {
		string s; int x;
		cin >> s;
		auto it = 0;
		if (s == "insert") {
			cin >> x;
			lis.push_front(x);
		} else if (s == "delete") {
			cin >> x;
			auto it = find(lis.begin(), lis.end(), x);
			if (it != lis.end()) {
				lis.erase(it);
			}
		} else if (s == "deleteFirst") {
			if (!lis.empty()) lis.pop_front();
		} else {
			if (!lis.empty()) lis.pop_back();
		}
	}
	bool first = true;
	for (auto x : lis) {
	    if (!first) cout << ' ';
	    cout << x;
	    first = false;
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}