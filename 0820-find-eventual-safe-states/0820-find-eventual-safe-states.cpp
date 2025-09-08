#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        std::vector<std::vector<int>> rev_graph(n);
        std::vector<int> out_degree(n, 0);
        
        for (int u = 0; u < n; ++u) {
            out_degree[u] = graph[u].size();
            for (int v : graph[u]) {
                rev_graph[v].push_back(u);
            }
        }
        
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (out_degree[i] == 0) {
                q.push(i);
            }
        }
        
        std::vector<int> safe_nodes;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            safe_nodes.push_back(u);
            
            for (int v : rev_graph[u]) {
                out_degree[v]--;
                if (out_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        std::sort(safe_nodes.begin(), safe_nodes.end());
        
        return safe_nodes;
    }
};