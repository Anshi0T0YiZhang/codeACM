#include <iostream>
#include <vector>
#include <sstream> //字符串流处理
#include <cassert> //断言处理

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    //哈希表
    unordered_set<int, int> hash_set;
}