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
        hashSpace[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums;
    int k, numSize;
    cin >> numSize;
    for(int n = 0; n < numSize; n++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> k;
    if(containsNearbyDuplicate(nums, k))
        printf("True");
    else
        printf("False");
}
