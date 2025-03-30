#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 寻找旋转点（最小值所在位置）
int findRotationIndex(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// 计算中位数，使用偏移量避免数组复制
double findMedian(vector<int>& nums) {
    int n = nums.size();
    int rotationIndex = findRotationIndex(nums);
    
    // 计算中位数索引（相对于原数组）
    int medianIndex1 = (n / 2 + rotationIndex) % n;
    
    if (n % 2 == 1) {
        return nums[medianIndex1];  // 奇数长度，直接返回中间值
    } else {
        int medianIndex2 = (medianIndex1 - 1 + n) % n;
        return (nums[medianIndex1] + nums[medianIndex2]) / 2.0; // 偶数长度，返回两个中间值的均值
    }
}

int main() {
    vector<int> nums = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    cout << "中位数: " << findMedian(nums) << endl;
    return 0;
}