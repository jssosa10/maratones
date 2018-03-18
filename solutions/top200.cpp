#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
const int inf = 1<<30;
int dp[maxn], w[maxn], T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n,m,a,b;
		scanf("%d%d%d%d",&n,&m,&a,&b);
		dp[0]=0;
		for (int i = 1; i <=n; ++i){
			scanf("%d",w+i);
			int sum = 0,f=0;
			dp[i]=inf;
			for(int j = i; j; --j){
				if(sum > m) f+=w[j];
				sum+=w[j];
				int cost = sum > m ? (sum-m)*a : (m-sum)*b;
				dp[i]=min(dp[i],dp[j-1]+cost);
				if(f>m)break;
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}