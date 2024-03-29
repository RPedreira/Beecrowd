#include <bits/stdc++.h>
using namespace std;

int comp(int a, int b)
{
    return a + b;
}

class SegmentTree {
    private:
    vector <int> st, A;
    int size;
    #define left(p) (p << 1)
    #define right(p) ((p << 1) + 1)
    void build(int p, int l, int r)
    {
        if(l == r)
            st[p] = A[l];
        else
        {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    int query(int p, int l, int r, int a, int b)
    {
        if(a > r || b < l)
            return 0;
        if(l >= a && r <= b)
            return st[p];
        int p1 = query(left(p), l, (l+r)/2, a, b);
        int p2 = query(right(p), (l+r)/2+1, r, a, b);
        return comp(p1, p2);
    }
    void update(int p, int l, int r, int ind , int v)
    {
        if(ind > r || ind < l)
            return;
        else if(l == ind && r == ind)
        {
            A[ind] = v;
            st[p] = A[l];
        }
        else
        {
            update(left(p), l, (l+r)/2, ind , v);
            update(right(p), (l+r)/2+1, r, ind , v);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    public:
    SegmentTree(vector <int> &_A)
    {
        A = _A;
        size = A.size ();
        st.assign (4*size , 0);
        build(1, 0, size -1);
    }
    int query(int a, int b)
    {
        return query(1, 0, size -1, a, b);
    }
    void update(int ind , int v)
    {
        update(1, 0, size -1, ind , v);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, aux;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        a.push_back(aux);
    }
    SegmentTree tree(a);
    char op;
    while(cin >> op >> aux)
    {
        if(op == 'a')
            tree.update(aux - 1, 0);
        else if(aux == 1)
            cout << 0 << endl;
        else
            cout << tree.query(0, aux - 2) << endl;
    }
}