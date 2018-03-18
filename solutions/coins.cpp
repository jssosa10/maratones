#include <bits/stdc++.h>
using namespace std;
int T,M,act,sum,data[105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&M);
			sum = 0;
			for(int i =1; i<=M; i++){
				scanf("%d",&act);
				data[i]=act;
				sum+=act;
			}
			//printf("%d\n",sum);
			int rs = 0;
			int medio = (sum/2);
			int dp[M+1][medio+1];
			for (int i = 0; i < M+1; ++i)
			{
				for (int j = 0; j < medio+1; ++j)
				{
					dp[i][j]=0;
				}
			}
			for(int i = 1; i<=M; i++){
				for(int j = 1;j<=medio;j++){
					if(data[i]<=j)dp[i][j]=max(dp[i-1][j-data[i]]+data[i],dp[i-1][j]);
					else dp[i][j]=dp[i-1][j];
				}
			}
			rs = dp[M][medio];
			printf("%d\n",abs(sum-2*rs));
		
	}
}