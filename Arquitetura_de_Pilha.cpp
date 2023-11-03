#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<long long int> pilha;
    long long int RAM[100] = {0};

    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        if(s[2] == 'd')
        {
            long long int a, b;
            a = pilha.top(); pilha.pop();
            b = pilha.top(); pilha.pop();
            pilha.push(a + b);
        }
        else if(s[2] == 'l')
        {
            long long int a, b;
            a = pilha.top(); pilha.pop();
            b = pilha.top(); pilha.pop();
            pilha.push(a * b);
        }
        else if(s[2] == 'v')
        {
            long long int a, b;
            a = pilha.top(); pilha.pop();
            b = pilha.top(); pilha.pop();
            pilha.push(b / a);
        }
        else if(s[2] == 'b')
        {
            long long int a, b;
            a = pilha.top(); pilha.pop();
            b = pilha.top(); pilha.pop();
            pilha.push(b - a);
        }
        else if(s[2] == 'i')
        {
            cout << pilha.top() << endl;
            pilha.pop();
        }
        else if(s[2] == 'p')
        {
            string aux;
            for(int i = 5; s[i] != '\0'; i++)
                aux.push_back(s[i]);
            int index = stoi(aux);
            RAM[index] = pilha.top();
            pilha.pop();
        }
        else if(s[5] == 'R')
        {
            string aux;
            for(int i = 6; s[i] != '\0'; i++)
                aux.push_back(s[i]);
            int index = stoi(aux);
            pilha.push(RAM[index]);
        }
        else
        {
            string aux;
            for(int i = 5; s[i] != '\0'; i++)
                aux.push_back(s[i]);
            int value = stoi(aux);
            pilha.push(value);
        }
    }
}