#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

long long int arr[MAXN][MAXN] = {}, dp[MAXN][MAXN] = {}, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	long long int ans;
	while (cin>>N, N){
		memset(arr, 0, sizeof(arr));
		ans = 0;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= i; j++){
				cin>>arr[i][j];
			}
		}

		ans = 0;
		for (int j = 1; j <= N; j++){
			int prefixSum = 0;
			for (int i = j; i <= N; i++){
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j] + prefixSum;
				prefixSum += arr[i][j];
			}
			for (int i = N - 1; i >= j; i--){
				dp[i][j] = max(dp[i + 1][j], dp[i][j]);
			}
			ans = max(ans, dp[j][j]);
		}
		cout<<ans<<endl;
	}
}