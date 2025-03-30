#include <iostream>
#include <vector>
#include <sstream> //字符串流处理
#include <cassert> //断言处理
#include <unordered_map> //哈希表

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    //哈希表
    unordered_set<Key, Value> hash_set;
}