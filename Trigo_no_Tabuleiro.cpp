/* ALUNOS:
    RAFAEL DO NASCIMENTO PEDREIRA
    GUSTAVO SILVA ARAÚJO
    PEDRO ELIAS SANTIAGO MATTAR
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        unsigned long long int ans = 1;
        cin >> n;
        if(n == 64)
            ans = ULLONG_MAX;
        else
        {
            ans = ans<<n;
            ans--;
        }
        cout << (ans / 12000) << " kg\n";
    }
}