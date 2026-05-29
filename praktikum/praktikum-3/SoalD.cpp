#include <bits/stdc++.h>
using namespace std;

struct Node {
  int parent, allyCount = 1;
  long long totalWealth, wealth;
  string name;
  bool vis = false;
};

vector<Node> adj;
map<string, int> nameToId;  

int find(int root) {
  if(root == adj[root].parent){
    return root;
  }else {
    return adj[root].parent = find(adj[root].parent);
  }
}

bool unite(int rootA, int rootB) {
  rootA = find(rootA);
  rootB = find(rootB);

  if(rootA == rootB) return false;

  if(adj[rootA].wealth < adj[rootB].wealth){
    swap(rootA, rootB);
  }else if(adj[rootA].wealth == adj[rootB].wealth && adj[rootA].name > adj[rootB].name) {
    swap(rootA, rootB);
  }

  adj[rootA].totalWealth += adj[rootB].totalWealth;
  adj[rootA].allyCount += adj[rootB].allyCount;
  adj[rootB].parent = rootA;

  return true;
}


int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    Node node;
    cin >> node.name >> node.wealth;
    nameToId[node.name] = i;
    node.totalWealth = node.wealth;
    node.parent = i;
    adj.push_back(node);
  }
  for(int i = 0; i < m; i++) {
    string u, v;
    cin >> u >> v;
    int idU = nameToId[u];
    int idV = nameToId[v];
    unite(idU, idV);
  }
  priority_queue <pair<long long, string>, vector<pair<long long, string>>, greater<pair<long long, string>>> pq;
  for(int i = 0; i < n; i++) {
    int root = find(i);
    if(!adj[root].vis) {
      adj[root].vis = 1;
      pq.push({-adj[root].totalWealth, adj[root].name});
    }
  }
  while(!pq.empty()) {
    auto [w_total, name] = pq.top();
    int id = nameToId[name];
    cout << adj[id].name << " " << adj[id].totalWealth << " " << adj[id].allyCount << endl;
    pq.pop();
  }

}
