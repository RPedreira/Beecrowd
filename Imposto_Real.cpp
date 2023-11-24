#include <bits/stdc++.h>
using namespace std;

long long int dfs(vector<vector<pair<int, long long int>>> &graph, vector<long long int> &impostos, long long int c, int pai, long long int dist, int atual){
    if(graph[atual].size() == 1)
    {
        impostos[pai] += impostos[atual];
        return 2 * (dist * (ceil((float)impostos[atual] / (float)c)));
    }
    else
    {
        long long int ans = 0;
        for(int i = 0; i < graph[atual].size(); i++)
        {
            if(graph[atual][i].first != pai)
                ans += dfs(graph, impostos, c, atual, graph[atual][i].second, graph[atual][i].first);
        }
        impostos[pai] += impostos[atual];
        return ans + (2 * (dist * (ceil((float)impostos[atual] / (float)c))));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, c, ans = 0;
    cin >> n >> c;
    vector<vector<pair<int, long long int>>> graph(n + 1);
    vector<long long int> impostos(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> impostos[i];
    for(int i = 1; i < n; i++)
    {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for(int i = 0; i < graph[1].size(); i++)
        ans += dfs(graph, impostos, c, 1, graph[1][i].second, graph[1][i].first);
    cout << ans << endl;
}