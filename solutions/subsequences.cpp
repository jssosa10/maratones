#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5,maxk =12;
int n,k,a[maxn];
long long dp[maxn][maxk],c[maxk][maxn];
void add(int id, int pos, long long val){
	for(int i = pos; i<=n ; i+=i&-i){
		c[id][i]+=val;
	}
}
long long query(int id, int pos){
	long long sum = 0;
	for(int i = pos; i>=1; i -= i & -i){
		sum+=c[id][i];
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&k);
	k++;
	//printf("llego\n");
	for(int i =1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	//printf("agrego\n");
	long long sum =0 ;
	//printf("cacluando con n = %d y k=  %d\n", n,k);
	for(int i =1; i<=n; i++){
		dp[i][1]=1;
		//printf("entrando\n");
		for(int j = 1; j<=k; j++){
			//printf("query \n");
			dp[i][j]+=query(j-1,a[i]);
		}

		//printf("calc\n");
		sum +=  dp[i][k];
		for(int j = 1; j<=k;j++){
			add(j,a[i],dp[i][j]);
		}
	}
	printf("%lld\n",sum);
	return 0;
}