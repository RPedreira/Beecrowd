#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

class UnionFind {
private:
  vector<int> p, rank;

public:
  UnionFind(int N) {
    rank.assign(N + 1, 0);
    p.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
      p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
  bool isAllSameSet(int n) {
    for (int i = 2; i <= n; i++) {
      if (!isSameSet(1, i))
        return false;
    }
    return true;
  }
};

int visited[MAX], scc[MAX], sccCount, timeCount;

void dfs(int u, vector<vector<int>> &graph,
         priority_queue<pair<int, int>> &pq) {
  visited[u] = 1;
  for (int v : graph[u])
    if (!visited[v])
      dfs(v, graph, pq);
  pq.push({timeCount++, u});
}

void makeScc(int u, vector<vector<int>> &reverseGraph) {
  visited[u] = 1;
  scc[u] = sccCount;
  for (int v : reverseGraph[u])
    if (!visited[v])
      makeScc(v, reverseGraph);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> graph(n + 1, vector<int>()),
        reverseGraph(n + 1, vector<int>());
    vector<pair<int, int>> edges;
    priority_queue<pair<int, int>> pq;
    int u, v, type;
    cin >> u >> v >> type;
    for (int i = 2; i <= m; i++) {
      cin >> u >> v >> type;
      if (type == 1) {
        edges.push_back({u, v});
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
      } else {
        graph[u].push_back(v);
        graph[v].push_back(u);
        reverseGraph[u].push_back(v);
        reverseGraph[v].push_back(u);
      }
    }

    bool isolatedNode = false;
    for (int i = 1; i <= n; i++) {
      if (graph[i].empty() && reverseGraph[i].empty()) {
        isolatedNode = true;
        break;
      }
    }

    if (isolatedNode)
      cout << '*' << endl;
    else {
      sccCount = 0;
      timeCount = 0;
      for (int i = 1; i <= n; i++)
        visited[i] = 0;
      for (int i = 1; i <= n; i++)
        if (!visited[i])
          dfs(i, graph, pq);

      for (int i = 1; i <= n; i++)
        visited[i] = 0;
      while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (!visited[u]) {
          sccCount++;
          makeScc(u, reverseGraph);
        }
      }

      if (sccCount == 1)
        cout << '-' << endl;
      else {
        vector<int> leaving(sccCount + 1, 0), entering(sccCount + 1, 0);
        map<pair<int, int>, int> sccEdges;
        UnionFind uf(sccCount);

        for (auto it : edges) {
          if (scc[it.first] != scc[it.second]) {
            leaving[scc[it.first]]++;
            entering[scc[it.second]]++;
            if (sccEdges[{scc[it.first], scc[it.second]}]) {
              leaving[scc[it.second]]++;
              entering[scc[it.first]]++;
            }
            sccEdges[{scc[it.first], scc[it.second]}]++;
            uf.unionSet(scc[it.first], scc[it.second]);
          }
        }

        if (uf.isAllSameSet(sccCount)) {
          int ans = 1;
          for (int i = 1; i <= sccCount; i++) {
            if (leaving[i] + entering[i] == 1)
              ans = 2;
          }
          cout << ans << endl;
        } else
          cout << '*' << endl;
      }
    }
  }
}