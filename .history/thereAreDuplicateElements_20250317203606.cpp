#include <iostream>
#include <vector>
#include <sstream> //字符串流处理
#include <cassert> //断言处理
#include <unordered_map> //哈希表

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    //哈希表
    unordered_map<int, int> hashspace;
    for (int i = 0; i < n; i++) {
        if (hashspace.find(nums[i])!= hashspace.end() && i - hashspace[nums[i]] <= k) {
            return true;
            //cout << "find duplicate: " << nums[i] << " at index " << i << endl;
        }

    }
}