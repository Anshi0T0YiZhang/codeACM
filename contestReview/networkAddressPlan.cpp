#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

// 将 IP 字符串转为 uint32_t 整数
uint32_t ipToInt(const string& ip) {
    int a, b, c, d;
    //作用是从 ip 字符串中读取四个用点分隔的整数，并将它们分别存储到变量 a、b、c 和 d 中。
    sscanf(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d); // 注意 sscanf 要求格式化字符串必须以空格分隔; 
    return ((uint32_t)a << 24) | ((uint32_t)b << 16) | ((uint32_t)c << 8) | d;
}

// 将 uint32_t 整数转为 IP 字符串
//3232235777 == 11000000 10101000 00000001 00000001
string intToIp(uint32_t ip) {  
    return to_string((ip >> 24) & 255) + "." +
           to_string((ip >> 16) & 255) + "." +
           to_string((ip >> 8) & 255) + "." +
           to_string(ip & 255);
}

// 区间结构体
/*
start_str：表示IP地址区间的起始地址的字符串形式。
end_str：表示IP地址区间的结束地址的字符串形式。
start：表示IP地址区间的起始地址的32位无符号整数形式。
end：表示IP地址区间的结束地址的32位无符号整数形式。
*/
struct Interval {
    string start_str, end_str;
    uint32_t start, end;

    int length() const {
        return end - start + 1; // 区间长度, 包含多少个
    }
};

// 自定义排序规则
/*
首先按区间结束地址升序排列。
如果结束地址相同，则按区间长度升序排列。
如果结束地址和区间长度都相同，则按区间起始地址升序排列。
*/
bool cmp(const Interval& a, const Interval& b) {
    if (a.end != b.end) return a.end < b.end; // 小的排前面
    if (a.length() != b.length()) return a.length() < b.length(); // 短的排前面
    return a.start < b.start; // 起始地址小的排前面
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
    //在您的代码中，sort 函数用于对 intervals 向量中的 Interval 结构体对象进行排序，使用 cmp 作为自定义的比较函数。

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