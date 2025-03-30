#include <iostream>
#include <vector>
#include     <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = m; i < m+n; i++){
        nums1[i] += nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
}

int main(){
    int m,n;
    cin >> m >> n;
    
    vector<int> nums1(m+n),nums2(n);
    for(int i; i < m; i++){
        cin >> nums1[i];
    }
    for(int j; j< n; j++){
        cin >> nums2[j];
    }
    for(int x; x< m+n; x++){
        cout << nums1[x] << endl;
    }
    
}