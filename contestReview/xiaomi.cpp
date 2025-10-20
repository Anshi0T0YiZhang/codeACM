#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findSecondMax(vector<int>& arr){
    int max1 = INT_MIN, max2 = INT_MIN;
    for(int num : arr){
        if(num > max1){
            max2 = max1;
            max1 = num;
        }
        else if(num > max2 && num != max1){
            max2 = num;
        }
    }
    return max2;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int secondMax = findSecondMax(arr);
    cout << "the second max is:" << secondMax << endl;
    return 0;
}