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
    cin >> nums;
    cin >> val;

    int k = removeElement(nums, val);

    assert (k == result.size());
    sort(nums.begin(), nums.end(), k);
    for(int i=0; i<actualLength; i++){
        assert nums[i] == result[i];
    }

}