#include <iostream>
#include <vector>
using namespace std;

// 定义“日”字走法的偏移量
const vector<vector<int>> directions = {
    {1, 2}, {2, 1}, {-1, 2}, {-2, 1},
    {1, -2}, {2, -1}, {-1, -2}, {-2, -1}
};

// 记忆化数组，memo[i][j][k] 表示从 (i, j) 出发，剩余长度为 k 时的密码组合数
vector<vector<vector<int>>> memo(4, vector<vector<int>>(4, vector<int>(11, -1))); 

// 深度优先搜索函数
int dfs(int i, int j, int L) {
    // 如果剩余长度为 0 ，说明找到了一种密码组合，返回 1
    if (L == 0) {
        return 1;
    }
    // 如果已经计算过该状态，直接返回结果
    if (memo[i][j][L] != -1) {
        return memo[i][j][L];
    }
    int count = 0;
    // 遍历“日”字走法的 8 个方向
    for (const auto& dir : directions) {
        int newI = i + dir[0];
        int newJ = j + dir[1];
        // 判断新位置是否在 4x4 密码盘内
        if (newI >= 0 && newI < 4 && newJ >= 0 && newJ < 4) {
            count += dfs(newI, newJ, L - 1);
        }
    }
    // 记录当前状态的结果
    memo[i][j][L] = count;
    return count;
}

int psCount(int i, int j, int L) {
    return dfs(i, j, L);
}

int main() {
    int i = 0, j = 0, L = 3;
    int result = psCount(i, j, L);
    cout << "从(" << i << ", " << j << ")出发长度为" << L << "的密码数量为: " << result << endl;
    return 0;
}