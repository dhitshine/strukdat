#include <bits/stdc++.h>
using namespace std;

bool bisa = 0;
int n, m, a, b;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        edgeCount++;
    }

    int dfs(long start){
        int cnt = 0;
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        
        while(!st.empty()){
            long temp = st.top();
            st.pop();
            cnt++;
            if(temp == b) {
              bisa = 1;
              break;
            }
            if(!visited[temp]){
              visited[temp] = true;
            }

            for(auto vertex:adjList[temp]){
                if (!visited[vertex])
                    st.push(vertex);
            }
        }
        return cnt;
    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto vertex:adjList[temp]){
                if (!visited[vertex]){
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
                }
            }
        }
    }
};

int main() {
  graph g;
  cin >> n >> m;
  g.init(n);

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(u, v);
  }
  cin >> a >> b;
  int ans = g.dfs(a);
  if(bisa) {
    cout << "Ya " << ans;
  }else {
    cout << "Tidak";
  }
  return 0;
}
