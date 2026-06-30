//编写一个程序，读取 n 个物品并对它们进行排序。每个物品具有如下属性：
//{value, weight, type, date, name}
//分别用 {整数, 整数, 大写字母, 整数, 字符串}表示。
//请按以下优先级对物品进行排序：
//先按 value（值）升序排列
//若 value 相同，则按 weight（重量）升序排列
//若 weight 也相同，则按 type（类型）按字典序升序排列
//若 type 也相同，则按 date（日期）升序排列
//若 date 也相同，则按 name（名称）按字典序升序排列
//输入​
//输入数据按以下格式给出：
//n
//v0 w0 t0 d0 s0
//v1 w1 t1 d1 s1
//:
//vn-1 wn-1 tn-1 dn-1 sn-1
//第一行是物品数量 n
//接下来 n 行，每行给出一个物品的属性
//vi wi ti di si分别表示第 i 个物品的 value、weight、type、date 和 name
//输出​
//按排序后的顺序逐行输出每个物品的属性，同一行中相邻属性之间用一个空格分隔。
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

struct item{
	int val;
	int weight;
	string type;
	ll day;
	string name;
};

void solve() {
	int n;
	cin >> n;
	vector<item> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].val >> arr[i].weight >> arr[i].type >> arr[i].day >> arr[i].name;
	}
	sort(arr.begin(), arr.end(), [](const item& a, const item& b){
		if (a.val != b.val) return a.val < b.val;
		if (a.weight != b.weight) return a.weight < b.weight;
		if (a.type != b.type) return a.type < b.type;
		if (a.day != b.day) return a.day < b.day;
		return a.name < b.name;	
	});
	for (auto &i:arr) {
		cout << i.val << ' '<<i.weight << ' '<< i.type<< ' '<< i.day << ' '<< i.name << enl;
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	solve();
    return 0;
}