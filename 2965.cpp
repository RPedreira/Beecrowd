#include <bits/stdc++.h>
using namespace std;

int altura(vector<vector<int>> &mafia, vector<int> &degree, int index){
    if(mafia[index].empty())
    {
        degree[1]++;
        return 1;
    }
    else
    {
        vector<int>::iterator it = mafia[index].begin();
        int maxHeight = altura(mafia, degree, *it);
        for(++it ;it != mafia[index].end(); it++){
            maxHeight = max(maxHeight, altura(mafia, degree, *it));
        }
        degree[maxHeight + 1]++;
        return maxHeight + 1;
    }
}

int main(){
    int soma = 0, aux;
    int mafiosos, vidente, cont;

    cin >> mafiosos >> vidente;
    vector<vector<int>> mafia(mafiosos + 1);
    vector<int> degree(mafiosos + 1, 0);

    for(int i=2; i <= mafiosos; i++){
        cin >> aux;
        mafia[aux].push_back(i);
    }
    int maxHeight = altura(mafia, degree, 1);

    for(cont = 1; cont <= vidente; cont++)
    {
        if(degree[maxHeight] >= cont)
        {
            soma += maxHeight;
        }
        else
        {
            while(degree[maxHeight] < cont)
                maxHeight--;
            soma += maxHeight;
        }
    }

    cout << soma << endl;
}