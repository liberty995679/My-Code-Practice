//你可能已经知道，瓢虫阿达是个农夫。她有好几条菜畦，种着各种蔬菜。她可不会在同一条菜畦里种两种一样的蔬菜。阿达有时候会种新蔬菜、收获蔬菜，或者想知道两条不同菜畦之间有什么共同点（具体见输入说明）。
//输入格式
//第一行输入一个整数 1 ≤ Q ≤ 3*105，表示查询的次数。
//接下来 Q 行，每行包含一个查询，格式为 ? x y，其中 0 ≤ x, y ≤ 2*104，而 ? 是以下符号之一：+ - v ^ ! \，含义如下：
//+：在编号为 x 的菜畦里种上种类为 y 的蔬菜（保证同一菜畦不会有重复的蔬菜种类）。
//-：从编号为 x 的菜畦里收获种类为 y 的蔬菜（保证该蔬菜一定存在）。
//v：查询编号为 x 和 y 的两条菜畦里一共有多少种不同的蔬菜。
//^：查询编号为 x 和 y 的两条菜畦里共有多少种相同的蔬菜。
//!：查询编号为 x 和 y 的两条菜畦里有多少种蔬菜只出现在其中一条，而不是两条都有。
//\：查询编号为 x 的菜畦里有多少种蔬菜不在编号为 y 的菜畦里出现。
//输出格式
//对于最后四种查询（v ^ ! \），请输出对应的答案。
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
const char enl = '\n';
bitset<20001> bs[20001];  // 移到 main 外面 全局数据区的空间几乎只受物理内存限制
void solve() {
	int q;
	cin >> q;
	while (q--) {
		cin >> ws;
		char c; int x, y;
		cin >> c >> x >> y;
		if (c == '+') {
			bs[x].set(y);
		}
		if (c == '-') {
			bs[x].reset(y);
		}
		if (c == 'v') {
			auto ans = bs[x] | bs[y];
			cout << ans.count() << enl;
		}
		if (c == '^') {
			auto ans = bs[x] & bs[y];
			cout << ans.count() << enl;
		}
		if (c == '!') {
			auto ans = bs[x] ^ bs[y];
			cout << ans.count() << enl;
		} 
		if (c == '\\') {  
			auto ans = bs[x] & (~bs[y]);  // x 减去 y（差集）
			cout << ans.count() << enl;
		}
	}
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