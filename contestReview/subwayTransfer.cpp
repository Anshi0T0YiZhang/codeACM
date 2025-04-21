#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

typedef pair<string, int> State; // (station, line_index)

struct StateHash {
    size_t operator()(const State& s) const {
        return hash<string>()(s.first) ^ hash<int>()(s.second);
    }
};

struct StateEqual {
    bool operator()(const State& a, const State& b) const {
        return a.first == b.first && a.second == b.second;
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // 忽略第一行后的换行
    
    vector<vector<string>> stations(N);
    unordered_map<string, vector<int>> station_lines;
    vector<unordered_map<string, int>> station_pos(N);
    
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string station;
        int pos = 0;
        while (iss >> station) {
            stations[i].push_back(station);
            station_lines[station].push_back(i);
            station_pos[i][station] = pos;
            pos++;
        }
    }
    
    string start, end;
    cin >> start >> end;
    
    if (station_lines.find(start) == station_lines.end() || station_lines.find(end) == station_lines.end()) {
        cout << "NA" << endl;
        return 0;
    }
    
    // Dijkstra准备
    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> pq;
    unordered_map<State, int, StateHash, StateEqual> dist;
    unordered_map<State, State, StateHash, StateEqual> prev;
    
    for (int line : station_lines[start]) {
        State st = {start, line};
        pq.push({0, st});
        dist[st] = 0;
    }
    
    State end_state;
    bool found = false;
    
    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();
        
        if (u.first == end) {
            end_state = u;
            found = true;
            break;
        }
        
        if (dist[u] < current_cost) continue;
        
        // 处理同一线路内的相邻站点
        int line = u.second;
        int pos = station_pos[line][u.first];
        vector<string> line_stations = stations[line];
        
        // 前一个站点
        if (pos > 0) {
            string prev_station = line_stations[pos - 1];
            State v = {prev_station, line};
            if (dist.find(v) == dist.end() || dist[v] > current_cost) {
                dist[v] = current_cost;
                pq.push({current_cost, v});
                prev[v] = u;
            }
        }
        // 后一个站点
        if (pos < line_stations.size() - 1) {
            string next_station = line_stations[pos + 1];
            State v = {next_station, line};
            if (dist.find(v) == dist.end() || dist[v] > current_cost) {
                dist[v] = current_cost;
                pq.push({current_cost, v});
                prev[v] = u;
            }
        }
        
        // 处理换乘到其他线路
        for (int other_line : station_lines[u.first]) {
            if (other_line == line) continue;
            State v = {u.first, other_line};
            int new_cost = current_cost + 1;
            if (dist.find(v) == dist.end() || dist[v] > new_cost) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
                prev[v] = u;
            }
        }
    }
    
    if (!found) {
        cout << "NA" << endl;
        return 0;
    }
    
    // 回溯路径
    vector<string> path;
    State current = end_state;
    string current_station = current.first;
    int current_line = current.second;
    path.push_back(current_station);
    
    while (prev.find(current) != prev.end()) {
        State parent = prev[current];
        if (parent.second != current.second) {
            path.push_back(parent.first);
        }
        current = parent;
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    
    // 去重连续的相同站点（换乘点）
    vector<string> simplified;
    simplified.push_back(path[0]);
    for (size_t i = 1; i < path.size(); ++i) {
        if (path[i] != simplified.back()) {
            simplified.push_back(path[i]);
        }
    }
    
    // 输出路径
    cout << simplified[0];
    for (size_t i = 1; i < simplified.size(); ++i) {
        cout << "-" << simplified[i];
    }
    cout << endl;
    
    // 计算票价
    int transfers = simplified.size() - 2;
    cout << 2 + transfers << endl;
    
    return 0;
}
/*
输入:3
A B C D F
C E G H
B G I J
A J
输出:A-B-J
3
*/