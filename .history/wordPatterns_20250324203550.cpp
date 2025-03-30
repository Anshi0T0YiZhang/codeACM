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
        int i = 0, j = 0;
        while (i < pattern.size() && j < s.size()) {
            if (pattern[i] == 'a') {
                if (m.count('a') == 0) {
                    m['a'] = s.substr(j, s.find(' ', j) - j);
                    j = s.find(' ', j) + 1;
                } else if (m['a']!= s.substr(j, s.find(' ', j) - j)) {
                    return false;
                }
                i++;
                j = s.find(' ', j) + 1;
            } else {
                if (m.count(pattern[i]) == 0) {
                    m[pattern[i]] = s.substr(j, s.find(' ', j) - j);
                    j = s.find(' ', j) + 1;
                } else if (m[pattern[i]] != s.substr(j, s.find(' ', j) - j)) {
                    return false;
                }
                i++;
                j = s.find(' ', j) + 1;
            }