#include <bits/stdc++.h>
using namespace std;

void DFS(int raiz, int pai, vector<vector<int>> &listAdj, vector<bool> &visitado, vector<bool> &nota){
    visitado[raiz] = true;
    for(auto x: listAdj[raiz])
    {
        if(!visitado[x] && x != pai)
        {
            DFS(x, raiz, listAdj, visitado, nota);
        }
    }
    if(pai != -1 && !nota[raiz])
    {
        nota[raiz] = !nota[raiz];
        nota[pai] = !nota[pai];
    }
}

int main(){
    int N, M, ver1, ver2;
    char tower;
    while(cin >> N >> M){
        bool result = true;
        vector<vector<int>> listAdj(N);
        vector<bool> visitado(N, false);
        vector<bool> nota(N);
        for(int i = 0; i < N; i++)
        {
            cin >> tower;
            if(tower == 'A')
                nota[i] = true;
            else
                nota[i] = false;
        }
        while(M--)
        {
            cin >> ver1 >> ver2;
            listAdj[ver1 - 1].push_back(ver2 - 1);
            listAdj[ver2 - 1].push_back(ver1 - 1);
        }
        for(int i = 0; i < N && result; i++)
        {
            if(!visitado[i])
            {
                DFS(i, -1, listAdj, visitado, nota);
                result = result && nota[i];
            }
        }
        if(result)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}