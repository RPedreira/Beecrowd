#include <bits/stdc++.h>
using namespace std;

int coef[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while(cin >> n >> m)
    {
        bool res = false;
        set<int> pontuacoes;

        for(int i = 0; i < n; i++)
            cin >> coef[i];
        
        if(n > 1)
        {
            for(int i = 1; i <= m && !res; i++)
            {
                for(int j = 1; j <= m && !res; j++)
                {
                    if(n > 2)
                    {
                        for(int k = 1; k <= m && !res; k++)
                        {
                            int score = (coef[0] * i) + (coef[1] * j) + (coef[2] * k);
                            if(pontuacoes.find(score) != pontuacoes.end())
                                res = true;
                            else
                                pontuacoes.emplace(score);
                        }
                    }
                    else
                    {
                        int score = (coef[0] * i) + (coef[1] * j);
                        if(pontuacoes.find(score) != pontuacoes.end())
                            res = true;
                        else
                            pontuacoes.emplace(score);
                    }
                }
            }
            if(res)
                cout << "Try again later, Denis...\n";
            else
                cout << "Lucky Denis!\n";
        }
        else
            cout << "Lucky Denis!\n";
    }

}