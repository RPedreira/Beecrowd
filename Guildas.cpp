#include <bits/stdc++.h>
using namespace std;

int scores[100000], p[100000], ranking[100000];

class UnionFind {
    public:
    UnionFind(int N) {
        for (int i = 0; i < N; i++)
        {
            p[i] = i;
            ranking[i] = 0;
        }
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // Se forem de conjuntos disjuntos
            int x = findSet(i), y = findSet(j);
            if (ranking[x] > ranking[y])
            {
                p[y] = x;
                scores[x] += scores[y];
            }
            else
            {
                p[x] = y;
                scores[y] += scores[x];
                if (ranking[x] == ranking[y])
                    ranking[y]++;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while(cin >> n >> m && n && m)
    {
        int q, a, b, ans = 0;
        UnionFind u(n);
        for(int i = 0; i < n; i++)
            cin >> scores[i];
        for(int i = 0; i < m; i++)
        {
            cin >> q >> a >> b;
            if(q == 1)
                u.unionSet(a - 1, b - 1);
            else if(u.findSet(0) == u.findSet(a - 1))
            {
               
                if(scores[u.findSet(a - 1)] > scores[u.findSet(b - 1)])
                    ans++;
            }
            else if(u.findSet(0) == u.findSet(b - 1))
            {
                if(scores[u.findSet(b - 1)] > scores[u.findSet(a - 1)])
                    ans++;
            }
        }
        cout << ans << endl;
    }
}
