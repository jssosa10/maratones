#include<bits/stdc++.h>
using namespace std;
const int mod = 1001113;
long long dp[111][111];
int t,n,v;
int main(){
	for(int i=1; i<=100;i++){
		dp[i][0]=dp[i][i-1]=1;
		for(int j=1;j<i-1;j++){
			dp[i][j]=((dp[i][j])%mod+((dp[i-1][j]%mod)*((j+1)%mod))%mod)%mod;
			//if(dp[i][j]>=mod)dp[i][j]-=mod;
			dp[i][j]=((dp[i][j])%mod+((dp[i-1][j-1]%mod)*((i-j)%mod))%mod)%mod;
			//dp[i][j]+=((dp[i-1][j-1])%mod*((i-j)%mod))%mod;
			//if(dp[i][j]>=mod)dp[i][j]-=mod;
		}
	}
	scanf("%d",&t);
	while(t--){
		int c;
		scanf("%d %d %d",&c,&n,&v);
		printf("%d %lld\n",c,dp[n][v]);
	}
}