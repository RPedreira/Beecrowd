#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, apaga, tam;
    while(cin >> n >> apaga && n && apaga)
    {
        tam = n - apaga;
        string s, ans;
        stack<char> pilha;
        cin >> s;
        for(int i = n - 1, j = 0; i >= 0; i--)
        {
            if(j < tam)
            {
                pilha.push(s[i]);
                j++;
            }
            else if(s[i] >= pilha.top())
                pilha.push(s[i]);
        }
        apaga = pilha.size() - tam;
        if(tam <= apaga)
        {
            for(int i = 0; i < tam; i++)
            {
                ans.push_back(pilha.top());
                pilha.pop();
            }
        }
        else
        {
            for(int i = 0; i < apaga; i++)
            {
                ans.push_back(pilha.top());
                pilha.pop();
            }
            while(apaga)
            {
                if(pilha.top() > ans.back() && apaga)
                {
                    while(pilha.top() > ans.back() && apaga)
                    {
                        ans.pop_back();
                        apaga--;
                    }
                    ans.push_back(pilha.top());
                    pilha.pop();
                }
                else if(ans.size() < tam)
                {
                    ans.push_back(pilha.top());
                    pilha.pop();
                }
                else
                {
                    apaga--;
                    pilha.pop();
                }
            }
            while(!pilha.empty())
            {
                ans.push_back(pilha.top());
                pilha.pop();
            }
        }
        cout << ans << endl;
    }
}