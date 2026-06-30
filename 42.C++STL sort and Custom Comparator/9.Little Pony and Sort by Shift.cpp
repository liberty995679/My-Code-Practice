//有一天，暮光闪闪（Twilight Sparkle）对如何将一个整数序列 a
//按非递减顺序排序产生了兴趣。
//作为一只年轻的小马，她唯一能执行的操作是单位循环移位：将序列的最后一个元素移到最前面：
//请帮暮光闪闪计算：她最少需要多少次这样的操作才能将序列排好序？
//输入​
//第一行包含一个整数 n（2 ≤ n ≤ 10⁵）。
//第二行包含 n个整数 a（1 ≤ aᵢ ≤ 10⁵）。
//输出​
//如果无法将序列排序，则输出 −1。
//否则，输出暮光闪闪需要的最少操作次数。
#include <iostream>
#include <algorithm>
#include <sstream>
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
using ll = long long;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> b = arr;
	int pos = 0; int cnt = 0;
	for (int i = 0; i < n; i++)	{
		int j = (i + 1) % n;
		if (arr[i] > arr[j]) {
			cnt++;
			pos = i;
		}
	}
	if (cnt == 1) {  //下降点只有一个，有答案
		cout << n - 1 - pos << enl;
	} else if (cnt == 0){  //升序
		cout << 0 << enl;
	} else {
		cout << -1 << enl;
	}
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	solve();
    return 0;
}