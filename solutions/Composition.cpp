#include<bits/stdc++.h>
using namespace std;
const int maxn = 35;
int dp[maxn],T,t,n,m,k;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&t,&n,&m,&k);
		dp[0]=1;
		for(int i =1; i<=n; i++){
			for(int j=1; j<=i;j++){
				if(j%k!=m){
					dp[i]+=dp[i-j];
				}
			}
		}
		printf("%d %d\n",t,dp[n]);
	}
	return 0;
}