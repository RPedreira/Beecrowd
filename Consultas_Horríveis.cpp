#include <bits/stdc++.h>
using namespace std;

long long int comp(long long int a, long long int b)
{
    return a + b;
}

class SegmentTree {
    private:
    vector <long long int> st, lazy;
    long long int size;
    #define left(p) (p << 1)
    #define right(p) ((p << 1) + 1)
    void push(long long int p, long long int l, long long int r)
    {
        if(l != r)
        {
            lazy[right(p)] += lazy[p];
            lazy[left(p)] += lazy[p];
        }
        st[p] += (r - l + 1) * lazy[p];
        lazy[p] = 0;
    }
    long long int query(long long int p, long long int l, long long int r, long long int a, long long int b)
    {
        push(p, l, r);
        if(a > r || b < l)
            return 0;
        if(l >= a && r <= b)
            return st[p];
        long long int p1 = query(left(p), l, (l+r)/2, a, b);
        long long int p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
    void update(long long int p, long long int l, long long int r, long long int a, long long int b, long long int k)
    {
        push(p, l, r);
        if(a > r || b < l)
            return;
        else if(l >= a && r <= b)
        {
            lazy[p] = k;
            push(p, l, r);
        }
        else
        {
            update(left(p), l, (l+r)/2, a, b, k);
            update(right(p), (l+r)/2+1, r, a, b, k);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    public:
    SegmentTree(long long int sz)
    {
        size = sz;
        st.assign (4*size , 0);
        lazy.assign (4*size , 0);
    }
    long long int query(long long int a, long long int b)
    {
        return query(1, 0, size -1, a, b);
    }
    void update(long long int a, long long int b, long long int k)
    {
        update(1, 0, size -1, a, b, k);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;
        SegmentTree tree(n);
        for(int i = 0; i < c; i++)
        {
            long long int op, a, b, v;
            cin >> op;
            if(op == 0)
            {
                cin >> a >> b >> v;
                tree.update(a - 1, b - 1, v);
            }
            else
            {
                cin >> a >> b;
                cout << tree.query(a - 1, b - 1) << endl;
            }
        }
    }
}