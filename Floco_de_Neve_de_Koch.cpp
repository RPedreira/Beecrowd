#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int lado;
    while(cin >> lado){
        printf("%.2f\n", (float)2*lado*lado*sqrt(3)/5);
    }
}