#include <iostream>
#include <vector>
#include <sstream> //字符串流处理
#include <cassert> //断言处理

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (nums[fastIndex] != val) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}

int main() {
    vector<int> nums;
    int val;
    string line;
    
    // 读取数组
    getline(cin, line); //读取一行输入
    istringstream iss(line); //将字符串转换为流
    int num;
    while (iss >> num) { //cong'liu
        nums.push_back(num);
    }
    
    // 读取val
    cin >> val;
    
    int k = removeElement(nums, val);
    
    // 示例验证
    cout << "k = " << k << ", nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        if (i < k) cout << nums[i];
        else cout << "_";
        if (i != nums.size()-1) cout << ",";
    }
    cout << "]" << endl;
}
