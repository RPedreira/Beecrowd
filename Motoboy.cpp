#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n)
    {
        int p, tempo, pizzas;
        cin >> p;
        int mochila[n + 1][p + 1];
        for(int i = 0; i <= n; i++)
            mochila[i][0] = 0;
        for(int i = 0; i <= p; i++)
            mochila[0][i] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> tempo >> pizzas;
            for(int j = 1; j <= p; j++)
            {
                mochila[i][j] = mochila[i - 1][j];
                if(pizzas <= j)
                    mochila[i][j] = max(mochila[i][j], tempo + mochila[i - 1][j - pizzas]);
            }
        }
        cout << mochila[n][p] << " min." << endl;
    }
}