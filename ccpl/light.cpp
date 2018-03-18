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
int vis[10005];
int n,m;
int t;
vector<int> g[10005], ts;
void dfs(int node){
	vis[node]=1;
	for(int i = 0; i<g[node].size(); i++){
		int v = g[node][i];
		if(!vis[v])dfs(v);
	}
	ts.push_back(node);
	return;
}
int main(){
	scanf("%d",&t);
	for(int i = 1; i<=t; i++){
		scanf("%d%d",&n,&m);
		ts.clear();
		for(int j =1; j<=n; j++)
			g[j].clear();
		memset(vis,0,sizeof(vis));		
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
		}
		for(int j = 1; j<=n; j++){
			if(!vis[j])dfs(j);
		}
		memset(vis,0,sizeof(vis));
		int cc = 0;
		for(int j = ts.size()-1; j>=0; j--){
			if(!vis[ts[j]]){
				cc++;
				dfs(ts[j]);
			}
		}
		printf("Case %d: %d\n",i,cc);

	}
	return 0;
}

