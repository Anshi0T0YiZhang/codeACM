/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        vector<string> words;
        
        
    }
};

int main() {
    Solution s;
    string pattern = "abba";
    string s1 = "dog cat cat dog";
    string s2 = "dog cat cat fish";
    string s3 = "aaaa";
    cout << s.wordPattern(pattern, s1) << endl;
    cout << s.wordPattern(pattern, s2) << endl;
    cout << s.wordPattern(pattern, s3) << endl;
    return 0;
}