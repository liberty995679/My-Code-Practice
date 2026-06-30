//考虑一个数字列表，具有两种操作：
//插入数字 — 将指定的数字添加到列表的末尾。
//删除数字 — 从列表中删除指定数字的第一次出现。如果列表中不包含指定的数字，则不进行任何更改。
//例如：将数字 4 插入到列表 [1, 2, 1] 的结果是列表 [1, 2, 1, 4]。
//如果我们从这个列表中删除数字 1，我们得到列表 [2, 1, 4]，但如果我们从列表 [1, 2, 1, 4] 中删除数字 3，列表保持不变。
//如果列表至少包含两个相等的数字，则该列表是同质的；如果列表至少包含两个不同的数字，则该列表是异质的。
//例如：列表 [2, 2] 是同质的，列表 [2, 1, 4] 是异质的，列表 [1, 2, 1, 4] 是两者皆是，而空列表既不是同质的也不是异质的。
//编写一个程序，处理空列表上的若干插入和删除操作，并在每次操作后确定列表的同质性和异质性。
//输入
//输入文件的第一行包含一个整数 n — 要处理的操作数量 (1 ≤ n ≤ 100 000)。
//接下来的 n 行每行包含一个操作描述。操作描述由一个单词“insert”或“delete”组成，后跟一个整数 k — 操作参数 (−10^9 ≤ k ≤ 10^9)。
//输出
//对于每个操作，输出一行，包含一个单词，描述操作后列表的状态：
//“both” — 如果列表既是同质的又是异质的。
//“homo” — 如果列表是同质的，但不是异质的。
//“hetero” — 如果列表是异质的，但不是同质的。
//“neither” — 如果列表既不是同质的也不是异质的。
#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	unordered_map<int, int> mp;
	int cnt = 0;
	int repeated = 0;
	for (int i = 0; i < n; i++) {
		string s; int k;
		cin >> s >> k;
		if (s == "insert") {
			mp[k]++;
			if (mp[k] == 1) {
				cnt++;
			} 
			if (mp[k] == 2) {
				repeated++;
			}
		} else { 
			if (mp[k] > 0) {
				if (mp[k] == 2) repeated--;
				if (mp[k] == 1) cnt--;
				mp[k]--;	
			}
		}
		if (repeated >= 1 && cnt >= 2) {
			cout << "both" << enl;
		} else if (repeated >= 1) {
			cout << "homo" << enl;
		} else if (cnt >= 2) {
			cout << "hetero" << enl;
		} else {
			cout << "neither" << enl;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}