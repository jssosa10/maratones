#include <bits/stdc++.h>
using namespace std;
const int mx = 1000;
int n,m,x,y,t;
//1 gris 0 banco 2 negro
vector<int> g[mx];
int vis[mx];
int dfs(int node, int parent){
	vis[node]=1;
	for(vector<int>::iterator it = g[node].begin(); it!=g[node].end();++it){
		int act = *it;
		if(vis[act]==0){
			int a = dfs(act,node);
			if(a)return 1;
		}
		else if(vis[act]==1 && parent!=act){
			return 1;
		}

	}
	return 0;
}
int DFS(){
	int res = 0;
	for(int i = 0; i<n; ++i){
		if(vis[i]==0){
			res = res|dfs(i,-1);
		}
	}
	return res;
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		for(int i = 0; i<mx; ++i){
			g[i].clear();
		}
		scanf("%d %d",&n,&m);
		int ex = 0;
		for(int i = 0; i<m;++i){
			scanf("%d %d",&x,&y);
			if(g[x].contains(y)) ex =1;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(ex==0){
			printf("%d\n",DFS()); 
		}
		else
			printf("1\n");
		
	}
	return 0;
}