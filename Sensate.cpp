#include <bits/stdc++.h>
using namespace std;

int poder[10000], pai[10000], ranking[10000], poderMax[10000];

class UnionFind
{
    public:
    map <string, int> index;
    UnionFind(int n)
    {
        for(int i = 0; i < n; i++)    
        {
            pai[i] = i;
            ranking[i] = 0;
        }
    }
    int findSet(int i)
    {
        return pai[i] == i ? i : pai[i] = findSet(pai[i]);
    }
    
    void unionSet(string n1, string n2)
    {
        int p1 = findSet(index[n1]);
        int p2 = findSet(index[n2]);
        if(p1 == p2)
            return;
        if(ranking[p1] > ranking[p2])
        {
            pai[p2] = p1;
            poderMax[p1] = max(poderMax[p1], poderMax[p2]);
        }
        else
        {
            pai[p1] = p2;
            poderMax[p2] = max(poderMax[p1], poderMax[p2]);
            if(ranking[p1] == ranking[p2])
                ranking[p2]++;
        }
    }
};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    UnionFind u(n);
    for(int  i = 0; i < n; i++)
    {
        string name;
        int power;
        cin >> name >> power;
        u.index[name] = i;
        poder[i] = power;
        poderMax[i] = power;
    }

    for(int i = 0; i < m; i++)
    {
        string n1, n2;
        cin >> n1 >> n2;
        u.unionSet(n1, n2);
    }
    
    for(int i = 0; i < q; i++)
    {
        string name;
        cin >> name;
        if(poder[u.index[name]] >= 5 || poderMax[u.findSet(u.index[name])] <= 5)
            cout << "S\n";
        else
            cout << "N\n";
    }
}