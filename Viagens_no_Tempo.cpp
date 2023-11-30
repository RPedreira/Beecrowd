#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

#define MAXV 100

int n, m;
int original[MAXV][MAXV], capacity[MAXV][MAXV], maxCap[MAXV];

int bfs(int s, int t, vector<int>& parent, vector<vector<int>> &adj) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, vector<vector<int>> &adj) {
    int flow = 0;
    int new_flow;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            capacity[i][j] = original[i][j];
    vector<int> parent(n);

    while (new_flow = bfs(s, t, parent, adj)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                original[i][j] = 0;
                capacity[i][j] = 0;
                maxCap[i] = 0;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            original[a][b] = c;
            original[b][a] = c;
            maxCap[a] += c;
            maxCap[b] += c;
        }

        int origem = 0;
        for(int i = 1; i < n; i++)
        {
            if(maxCap[i] < maxCap[origem])
                origem = i;
        }

        int ans = INF;

        for(int i = 0; i < n; i++)
        {
            if(i != origem)
                ans = min(ans, maxflow(origem, i, adj));
        }
        cout << ans << endl;
    }
}