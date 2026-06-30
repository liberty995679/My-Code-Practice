//比较器用于比较两个对象。在这个挑战中，你需要创建一个比较器并用它来对数组进行排序。编辑器下方提供了 Player类，它有两个字段：
//name：一个字符串。
//score：一个整数。
//给定一个由 Player对象组成的数组，编写一个比较器，按分数降序对其进行排序。如果两个或更多玩家分数相同，则按名字升序（字母顺序）对这些玩家进行排序。为此，你必须创建一个实现 Comparator接口的 Checker类，然后编写一个 int compare(Player a, Player b)方法来实现 Comparator.compare(T o1, T o2)方法。简而言之，在升序排序中，比较器函数在 o1 < o2时返回负数，在 o1 == o2时返回 0，在 o1 > o2时返回正数。
//声明一个 Checker类，按照上述方式实现比较器方法。它应首先按分数降序排序，然后按名字升序排序。代码模板会读取输入，创建 Player对象的列表，使用你的方法对数据进行排序，并正确打印结果。
//示例
//将列表排序为：aleksa 150, amy 100, david 100, aakansha 75, heraldo 50。首先按分数降序排序，然后按名字升序排序。
//输入格式
//第一行包含一个整数 n，表示玩家数量。
//接下来的 n行，每行包含一个玩家的 name和 score，分别为一个字符串和一个整数。
//约束条件
//两个或更多玩家可以有相同的名字。
//玩家名字由小写英文字母组成。
//输出格式
//你不需要负责向标准输出打印任何内容。解决方案中的锁定代码模板会实例化一个 Checker对象，用它来排序 Player数组，并打印每个排序后的元素。
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
using ll = long long;
const char enl = '\n';

struct player{
	string name;
	int score;
};

void solve() {
	int n;
	cin >> n;
	vector<player> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].score;
	}
	sort(arr.begin(), arr.end(), [](const player& a, const player& b){
		if (a.score != b.score) return a.score > b.score;
		return a.name < b.name;	
	});
	for (auto &i:arr) {
		cout << i.name << ' ' << i.score << enl;
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