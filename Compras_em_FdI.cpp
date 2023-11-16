#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
#define INF 0x3f3f3f3f

pair<int, int> st[4 * MAX];
int lojas[MAX];

pair<int, int> comp(pair<int, int> a, pair<int, int> b)
{
    return {max(a.first, b.first), min(a.second, b.second)};
}

void build(int p, int l, int r)
{
    if(l == r)
        st[p] = {lojas[l], lojas[l]};
    else
    {
        build(left(p), l, (l+r)/2);
        build(right(p), (l+r)/2+1, r);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
}

pair<int, int> query(int p, int l, int r, int a, int b)
{
    if(a > r || b < l)
        return {-INF, INF};
    if(l >= a && r <= b)
        return st[p];
    pair<int, int> p1 = query(left(p), l, (l+r)/2, a, b);
    pair<int, int> p2 = query(right(p), (l+r)/2+1, r, a, b);
    return comp(p1, p2);
}

void update(int p, int l, int r, int ind , int v)
{
    if(ind > r || ind < l)
        return;
    else if(l == ind && r == ind)
    {
        lojas[ind] = v;
        st[p] = {lojas[l], lojas[l]};
    }
    else
    {
        update(left(p), l, (l+r)/2, ind , v);
        update(right(p), (l+r)/2+1, r, ind , v);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
}

int main(){
    int n, q;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &lojas[i]);
        build(1, 0, n - 1);
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            int op, a, b;
            scanf("%d%d%d", &op, &a, &b);
            if(op == 1)
                update(1, 0, n - 1, a - 1, b);
            else
            {
                pair<int, int> ans = query(1, 0, n - 1, a - 1, b - 1);
                printf("%d\n", ans.first - ans.second);
            }
        }
    }
}