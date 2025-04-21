#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

// 将 IP 字符串转为 uint32_t 整数
uint32_t ipToInt(const string& ip) {
    int a, b, c, d;
    sscanf(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    return ((uint32_t)a << 24) | ((uint32_t)b << 16) | ((uint32_t)c << 8) | d;
}

// 将 uint32_t 整数转为 IP 字符串
string intToIp(uint32_t ip) {
    return to_string((ip >> 24) & 255) + "." +
           to_string((ip >> 16) & 255) + "." +
           to_string((ip >> 8) & 255) + "." +
           to_string(ip & 255);
}

// 区间结构体
struct Interval {
    string start_str, end_str;
    uint32_t start, end;

    int length() const {
        return end - start + 1;
    }
};

// 自定义排序规则
bool cmp(const Interval& a, const Interval& b) {
    if (a.end != b.end) return a.end < b.end;
    if (a.length() != b.length()) return a.length() < b.length();
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals;

    for (int i = 0; i < n; ++i) {
        string s, e;
        cin >> s >> e;
        Interval iv;
        iv.start_str = s;
        iv.end_str = e;
        iv.start = ipToInt(s);
        iv.end = ipToInt(e);
        if (iv.start > iv.end) swap(iv.start, iv.end);  // 修正起始大于终止的情况
        intervals.push_back(iv);
    }

    // 排序
    sort(intervals.begin(), intervals.end(), cmp);

    // 贪心选择最多不重叠区间
    vector<Interval> result;
    uint32_t last_end = 0;
    for (const auto& iv : intervals) {
        if (result.empty() || iv.start > last_end) {
            result.push_back(iv);
            last_end = iv.end;
        }
    }

    // 输出
    for (const auto& iv : result) {
        cout << intToIp(iv.start) << " " << intToIp(iv.end) << endl;
    }

    return 0;
}
/*
输入:3
192.168.1.9 192.168.1.12
192.168.1.1 192.168.1.10 
192.168.1.12 192.168.1.13
输出:192.168.1.1 192.168.1.10
192.168.1.12.192.168.1.13
*/