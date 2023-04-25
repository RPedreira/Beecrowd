#include <bits/stdc++.h>
using namespace std;

int main(){
    int M, N, piso, aux;
    while(cin >> M >> N && M && N)
    {
        bool res = false;
        if(N % 2)
        {
            for(piso = 1; piso * piso <= M && !res; piso += 2)
            {
                if(piso * piso == N) res = true;
                else if(piso * piso < N)
                {
                    aux = piso - 1;
                    if((aux * aux) - (N - (piso * piso)) > 0) res = true;
                }
                else
                {
                    aux = piso + 1;
                    if((aux * aux) + ((piso * piso) - N - 2) <= M) res = true;
                }
            }
        }
        else
        {
            for(piso = 2; piso * piso <= M && !res; piso += 2)
            {
                if(piso * piso == N) res = true;
                else if(piso * piso < N)
                {
                    aux = piso - 1;
                    if((aux * aux) - (N - (piso * piso)) > 0) res = true;
                }
                else
                {
                    aux = piso + 1;
                    if((aux * aux) + ((piso * piso) - N - 2) <= M) res = true;
                }
            }
        }


        if(res) cout << "Let me try!" << endl;
        else cout << "Don't make fun of me!" << endl;
    }
}

