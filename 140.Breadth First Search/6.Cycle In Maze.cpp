//给一个图,从起点 X 出发,走恰好 k 步
//最后回到 X,路径必须是字典序最小的。
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <map>
#include <set>
using namespace std;
using ll = long long; 
vector<vector<char>> g;                    // 地图:存储每个格子的状态('.' 空地, '*' 障碍, 'X' 起点)
vector<vector<pair<int, int>>> parent;     // (未使用)存储父节点
vector<vector<int>> dis;                   // dis[i][j] = 从起点到(i,j)的最短距离
queue<pair<int, int>> que;                 // BFS队列
int dx[4] = {1, 0, 0, -1};                 // 四个方向的x偏移:下、左、右、上
int dy[4] = {0, -1, 1, 0};                 // 四个方向的y偏移:下、左、右、上
char zidian[4] = {'D', 'L', 'R', 'U'};     // 对应方向的字符:按字典序排列
int n, m, k;                               // n行 m列,需要走k步
int startx, starty;                        // 起点坐标
// ========== BFS:计算起点到所有点的最短距离 ==========
void bfs() {
    que.push({startx, starty});            // 起点入队
    dis[startx][starty] = 0;               // 起点到自己的距离为0
    
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int u = p.first;                   
        int v = p.second;                  
        for (int i = 0; i < 4; i++) {
            int u1 = u + dx[i];           
            int v1 = v + dy[i];            
            if (u1 < 0 || u1 >= n || v1 < 0 || v1 >= m) continue;
            if (g[u1][v1] != '*' && dis[u1][v1] == -1) {
                que.push({u1, v1});        // 新位置入队
                dis[u1][v1] = dis[u][v] + 1;  // 更新最短距离
            }
        }
    }
}
// 参数:(x,y)当前位置, step剩余步数, path当前路径
bool dfs(int x, int y, int step, string& path) {
    // 终止条件:步数用完
    if (step == 0) {
        // 检查是否回到起点
        return (x == startx && y == starty);
    }
    // 按字典序(D, L, R, U)尝试四个方向
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];                
        int ty = y + dy[i];               
        // 1. 边界检查
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        // 2. 检查新位置是否能到达起点(dis=-1表示不可达)
        if (dis[tx][ty] == -1) continue;
        // 3. 检查新位置是否是障碍
        if (g[tx][ty] == '*') continue;
        // 4. 计算走这一步后的剩余步数
        int remain = step - 1;
        // 5. 奇偶性检查
        // remain - dis[tx][ty] = 多余的步数
        // 多余步数必须是偶数,才能通过"来回走"消耗掉
        // 例如:最短距离3步,剩余5步,多2步可以来回走消耗
        //      最短距离3步,剩余4步,多1步无法消耗
        if ((remain - dis[tx][ty]) % 2 == 1) continue;
        // 6. 步数充足性检查
        // 剩余步数必须>=最短距离,否则走不回起点
        if (remain < dis[tx][ty]) continue;
        // === 尝试这个方向 ===
        path += zidian[i];                 // 将方向字符加入路径
        // 递归搜索:从新位置继续走
        if (dfs(tx, ty, step - 1, path)) {
            return true;                   // 找到解,立即返回
        }
        // 回溯:这个方向走不通,撤销选择
        path.pop_back();
    }
    // 所有方向都走不通
    return false;
}
void solve() {
    cin >> n >> m >> k;
    g.assign(n, vector<char>(m));          // 地图
    dis.assign(n, vector<int>(m, -1));     // 距离数组,初始化为-1(未访问)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'X') {          // 找到起点
                startx = i;
                starty = j;
                g[i][j] = '.';            
            }
        }
    }
    // 检查起点周围是否有可走的格子
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int tx = startx + dx[i];
        int ty = starty + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        if (g[tx][ty] == '.') flag = true;  // 找到至少一个可走的邻居
    }
    // 不可能的情况:
    // 1. k是奇数:从起点出发走奇数步无法回到起点
    // 2. 起点被困:周围都是障碍或边界
    if (k % 2 == 1 || !flag) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    // 第一步:BFS计算起点到所有点的最短距离
    bfs();
    // 第二步:DFS贪心构造字典序最小的路径
    string ans = "";
    if (dfs(startx, starty, k, ans)) {
        cout << ans << endl;               
    } else {
        cout << "IMPOSSIBLE" << endl;      
        return;
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