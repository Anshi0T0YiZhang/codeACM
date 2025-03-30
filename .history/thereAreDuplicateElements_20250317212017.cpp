#include <iostream>
#include <vector>
#include <sstream> //字符串流处理
#include <cassert> //断言处理
#include <unordered_map> //哈希表

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    //哈希表
    unordered_map<int, int> hashSpace;
    for (int i = 0; i < n; i++) {
        if (hashSpace.find(nums[i])!= hashSpace.end() && i - hashSpace[nums[i]] <= k) {
            return true;
            //cout << "find duplicate: " << nums[i] << " at index " << i << endl;
        }
        
    }
    return false;
}

int main() {
    vector<int> nums;
    int k, numSize;
    cin >> numSize;
    for(int n = 0; n < numSize; n++){
        int temp
    }
    cin >> k;
    printf("result: %d\n", containsNearbyDuplicate(nums, k));
}
