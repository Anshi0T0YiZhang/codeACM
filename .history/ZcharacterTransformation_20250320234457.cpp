/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string convert(string s, int numsRow){
    int len = s.length(), r = numsRow;
    if(numsRow == 1 || len > numsRow){
        return s;
    }

    vector<string> matrix(r);
    for(int i = 0, t = 2*r - 2, x = 0; i < len; i++){
        matrix[x] += s[i];
        i % t <= r - 1 ? x++ : x--;
    }

    string ans;
    for(auto &row : matrix){
        ans += row;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int numRows;
    cin >> numRows;
    string ans = convert(s, numRows);
    cout << ans << endl;
    return 0;
}

//Segmentation fault
//没有正确初始化matrix ---> matrix(r)