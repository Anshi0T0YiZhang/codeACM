#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <sstream>

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
    string line;
    getline(cin, line);
    istringstream iss(line);

    int num;
    while(iss >> num){
        nums.push_back(num);
    }

    cin >> val;
    cin.ingnore();
    getline(cin, line);
    
    assert (k == result.size());
    sort(nums.begin(), nums.end(), k);
    for(int i=0; i<actualLength; i++){
        assert nums[i] == result[i];
    }

}