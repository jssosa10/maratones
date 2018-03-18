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
int n,m,x,y,w[1005],b[1005],wss[1005],bs[1005],dp[2][1005];
char g[1005][1005];
int getw(int ini, int f){
	return wss[f]-wss[ini];
}
int  getb(int ini,int f){
	return bs[f]-bs[ini];
}
int gett(int wb,int i){
	if(i==0)return 0;
	else if(dp[wb][i]!=-1)return dp[wb][i];
	else{
		int minn = 1e9;
		for(int a=x; a<=y&&a<=i; a++){
			if(wb)
				minn = min(minn,gett((wb+1)%2,i-a)+getb(i-a,i));
			else
				minn = min(minn,gett((wb+1)%2,i-a)+getw(i-a,i));
		}
		return dp[wb][i]=minn;
	}
}
int main(){
	memset(w,0,sizeof(w));
	memset(b,0,sizeof(b));
	memset(wss,0,sizeof(wss));
	memset(bs,0,sizeof(bs));
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d%d",&n,&m,&x,&y);
	char s[1005];
	for(int  i =0; i<n; i++){
		scanf("%s",s);
		for(int j = 0; j<m; j++){
			g[i+1][j+1]=s[j];
			if(g[i+1][j+1]=='#')b[j+1]++;
			else w[j+1]++;
		}	
	}
	wss[1]=w[1];
	bs[1]=b[1];
	for(int  i=2; i<=m; i++)
		bs[i]+=b[i]+bs[i-1],wss[i]+=w[i]+wss[i-1];
	printf("%d\n",min(gett(0,m),gett(1,m)));
	return 0;
}

