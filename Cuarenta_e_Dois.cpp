#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k, aux, shifts = 0, ans = 0;
        vector<int> seq;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> aux;
            seq.push_back(aux);
        }
        sort(seq.begin(), seq.end(), greater<int>());
        aux = 1;
        while(2 * aux <= seq[0])
        {
            aux = aux<<1;
            shifts++;
        }
        for(int i = 0; i <= shifts; i++)
        {
            if(n == k)
            {
                aux = seq[0];
                for(int i = 1; i < n; i++)
                    aux &= seq[i];
                ans += aux;
                i = shifts;
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    if(seq[j] >= aux && j == n - 1)
                    {
                        seq[j] -= aux;
                        ans += 1<<(shifts - i);
                    }
                    else if(seq[j] >= aux)
                        seq[j] -= aux;
                    else if(j >= k)
                    {
                        n = j;
                        ans += 1<<(shifts - i);
                    }
                    else
                        break;
                }
                if(n != k)
                    sort(seq.begin(), seq.begin() + n, greater<int>());
                aux = aux>>1;
            }
        }
        cout << ans << endl;
    }
}