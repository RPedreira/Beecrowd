#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int main(){
    int O, D, K, aux;
    while(cin >> O >> D >> K)
    {
        if(O == 0 && D == 0 && K == 0) break;
        vector <int> canais(MAX + 1, 0);
        while(K--)
        {
            cin >> aux;
            canais[aux] = -1;
        }
        queue <int> BFS;
        BFS.push(O);
        canais[O] = 1;
        while(!BFS.empty() && canais[D] == 0)
        {
            int c = BFS.front();
            BFS.pop();
            if(c - 1 > 0 && canais[c - 1] == 0)
            {
                canais[c - 1] = canais[c] + 1;
                BFS.push(c - 1);
            }
            if(c + 1 <= MAX && canais[c + 1] == 0)
            {
                canais[c + 1] = canais[c] + 1;
                BFS.push(c + 1);
            }
            if(c%2 == 0 && canais[c / 2] == 0)
            {
                canais[c / 2] = canais[c] + 1;
                BFS.push(c / 2);
            }
            if(c <= 50000 && canais[c * 2] == 0)
            {
                canais[c * 2] = canais[c] + 1;
                BFS.push(c * 2);
            }
            if(c < 33334 && canais[c * 3] == 0)
            {
                canais[c * 3] = canais[c] + 1;
                BFS.push(c * 3);
            }
        }
        if(canais[D] == 0)
            cout << -1 << endl;
        else
            cout << canais[D] - 1 << endl;
    }
}