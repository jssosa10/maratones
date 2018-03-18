/*
 * I won't be broken
 * I won't be tortured
 * I won't be beaten down
 * I have the answer
 * I can take the pressure
 * I will turn it all around
 * Lift me up above this
 * The flames and the ashes
 * Lift me up and help me to fly away
*/
#include <bits/stdc++.h>
using namespace std;
int n,d,arr[105],dp[105];
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&d);
	char c[n];
	scanf("%s",c);
	for (int i = 0; i < n; ++i) {
		if(c[i]=='1')
			arr[i]=1;
		else
			arr[i]=0;
	}
	dp[0]=0;
	for(int i =1; i<n; i++){
		int minn = 1e9;
		for(int j =d; j>=1; j--){
			if(i-j>=0&&arr[i-j]==1)
				minn = min(minn,dp[i-j]);
		}
		dp[i]=minn+1;
	}
//	for(int i=0; i<n; i++){
//		printf("%d\n",dp[i]);
//	}
	if(dp[n-1]>=1e9)printf("-1\n");
	else printf("%d\n",dp[n-1]);
	return 0;
}

