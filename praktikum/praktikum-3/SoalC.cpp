#include <bits/stdc++.h>
#include <queue>
using namespace std;


int main() {
  int n, m;
  cin >> n >> m;
  string src, dst;
  cin >> src >> dst;
  unordered_map<string, int> dist;
  unordered_map<string, vector<pair<string, int>>> adj;
  unordered_map<string, bool> visited;
  for(int i = 0; i < m; i++) {
    string u, v;
    int w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  for(auto &[key, value] : adj) {
    dist[key] = 0;
  }
  dist[src] = INT_MAX;
  priority_queue<pair<int, string>> pq;
  pq.push({dist[src], src});
  visited[src] = true;
  while(!pq.empty()) {
    auto [w, curr] = pq.top();
    pq.pop();
    if(w < dist[curr]) {
      continue;
    }
    if(curr == dst) {
      break;
    }
    for(auto &[next, cost] : adj[curr]) {
      int potential = min(dist[curr], cost);
      if(potential > dist[next]) {
        dist[next] = potential;
        pq.push({dist[next], next});
      }
    }
  }
  cout << dist[dst];
}
