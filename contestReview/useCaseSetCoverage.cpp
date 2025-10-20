#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int i, j;
    cin >> i >> j; 
    // i为测试用例个数，j为模块个数; 行为测试用例个数，列为模块个数
    
    vector<int> case_masks(i, 0); // 记录每个测试用例的覆盖情况
    vector<bool> module_covered(j, false); // 记录每个模块是否被测试用例覆盖
    
    for (int idx = 0; idx < i; ++idx) {
        int mask = 0;
        for (int m = 0; m < j; ++m) {
            int bit;
            cin >> bit;
            if (bit == 1) {
                mask |= (1 << m);
                module_covered[m] = true;
            }
        }
        case_masks[idx] = mask;
    }
    
    // 检查是否所有模块都被覆盖,若存在未被覆盖的模块, 直接输出 -1 并结束程序
    // 行为全0
    for (bool covered : module_covered) {
        if (!covered) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    int target = (1 << j) - 1;
    int max_mask = 1 << i;
    vector<int> dp(max_mask, 0);
    
    for (int mask = 1; mask < max_mask; ++mask) {
        int lb = mask & -mask;
        int idx = __builtin_ctz(lb);
        dp[mask] = dp[mask ^ lb] | case_masks[idx];
    }
    
    // 枚举k从1到i，寻找最小的k
    for (int k = 1; k <= i; ++k) {
        int mask = (1 << k) - 1;
        while (mask < max_mask) {
            if (dp[mask] == target) {
                cout << k << endl;
                return 0;
            }
            int c = mask & -mask;
            int r = mask + c;
            mask = (((r ^ mask) >> 2) / c) | r;
        }
    }
    
    cout << -1 << endl;
    return 0;
}
/*
输入:3 2
     1 0
     1 0
     1 0
输出:-1
*/