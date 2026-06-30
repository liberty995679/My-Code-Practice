//八皇后问题变种
//任意两皇后不能互相攻击
//指定其中一个皇后的位置
//找出所有包含这个固定位置的解
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <iomanip>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
using ll = long long;

void put_queen(int x, int y, vector<vector<int>>& attack);
void backtrack(int k, int n,  vector<string>& queen, 
               vector<vector<int>>& attack, vector<vector<string>>& solve1, 
               int fixrow, int fixcol);

vector<vector<string>> solvequeen(int n, int fixrow, int fixcol) {
    vector<vector<int>> attack(n, vector<int>(n, 0));  
    vector<string> queen(n, string(n, '.'));  
    vector<vector<string>> solve1;
    backtrack(0, n, queen, attack, solve1, fixrow, fixcol);
    return solve1;
}

//k 表示当前处理的列(按列递归)
void backtrack(int k, int n, vector<string> &queen, vector<vector<int>> &attack,
               vector<vector<string>> &solve, int fixrow, int fixcol) {
    if (k == n) {  
        solve.push_back(queen);
        return;
    }
    // 如果当前列是固定的列,只能在固定的行放皇后
    if (k == fixcol) {
        if (attack[fixrow][k] == 0) {
            vector<vector<int>> tmp = attack;
            queen[fixrow][k] = 'Q';
            put_queen(fixrow, k, attack);
            backtrack(k + 1, n, queen, attack, solve, fixrow, fixcol);
            attack = tmp;
            queen[fixrow][k] = '.';
        }
        return;
    }
    // 在当前列(k)的每一行(i)尝试放皇后
    for (int i = 0; i < n; i++) {
        if (attack[i][k] == 0) {
            vector<vector<int>> tmp = attack;
            queen[i][k] = 'Q';
            put_queen(i, k, attack);
            backtrack(k + 1, n, queen, attack, solve, fixrow, fixcol);
            attack = tmp;
            queen[i][k] = '.';
        }
    }
}

void put_queen(int x, int y, vector<vector<int>> &attack) {
    int n = attack.size();
    attack[x][y] = 1;
    for (int j = 0; j < n; j++) attack[x][j] = 1;
    for (int i = 0; i < n; i++) attack[i][y] = 1;
    for (int i = 0; i < n; i++) {
        if (x + i < n && y + i < n) attack[x + i][y + i] = 1;
        if (x - i >= 0 && y - i >= 0) attack[x - i][y - i] = 1;
        if (x + i < n && y - i >= 0) attack[x + i][y - i] = 1;
        if (x - i >= 0 && y + i < n) attack[x - i][y + i] = 1;
    }
}

void solve() {
    int t;
    scanf("%d", &t);
    bool first = true;
    while (t--) {
        if (!first) printf("\n");
        first = false;
        int row, col;
        scanf("%d %d", &row, &col);
        row--; col--;  
        vector<vector<string>> ans = solvequeen(8, row, col);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n");
        printf("\n");
        
        int idx = 1;
        for (auto & solution : ans) {
            printf("%2d      ", idx++);  // 注意这里是6个空格
            // 对于每一列,找到皇后所在的行
            bool firstNum = true;
            for (int col = 0; col < 8; col++) {
                for (int row = 0; row < 8; row++) {
                    if (solution[row][col] == 'Q') {
                        if (!firstNum) printf(" ");
                        firstNum = false;
                        printf("%d", row + 1);
                        break;
                    }
                }
            }
            printf("\n");
        }
    }   
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);      
#endif
    solve();
    return 0;
}
