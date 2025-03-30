#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int slowIndex = 0;
    for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
        if(val != nums[fastIndex]){
            nums[slowIndex] = nums[fastIndex];
        }
    }
    return slowIndex;
}

int main(){
    vector<int> nums;
    int val;
    vector<int> result;

    int k =
}