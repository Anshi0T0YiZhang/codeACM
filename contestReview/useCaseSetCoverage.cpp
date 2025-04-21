#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int i, j;
    cin >> i >> j;
    
    vector<int> case_masks(i, 0);
    vector<bool> module_covered(j, false);
    
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
    
    // 检查是否所有模块都被覆盖
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