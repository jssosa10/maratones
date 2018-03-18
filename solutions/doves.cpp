#include <bits/stdc++.h>
using namespace std;
const int M = 10005;
vector<int> g[M];
pair<int,int> its[M];
int dfn[M],low[M],state[M],clockdfs,n,m,x,y;
bool pairCompare(const pair<int, int>& firstElem, pair<int, int>& secondElem) {
  if(firstElem.first!=secondElem.first) return firstElem.first>secondElem.first;
  else return firstElem.second<secondElem.second;

}
void dfs(int u, int fa){
	dfn[u]=low[u]=++clockdfs;
	int ch = 0;
	for(int i =0;i<g[u].size();i++){
		int v = g[u][i];
		if(!dfn[v]){
			ch++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) its[u].first++;
		}
		else if(dfn[v]<dfn[u]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(fa<0&&ch==1)its[u].first=1;
}
void DFS(){
	clockdfs = 0;
	memset(dfn,0,sizeof(dfn));
	dfs(0,-1);
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF&&(n+m)){
		for(int i = 0; i<n; i++){
			g[i].clear();
			its[i].first = 1;
			its[i].second = i; 
		}
		while(true){
			scanf("%d %d",&x,&y);
			if(x==y&&y==-1)break;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		DFS();
		sort(its,its+n,pairCompare);
		for(int i = 0; i<m;i++){
			printf("%d %d\n",its[i].second,its[i].first);
		}
		printf("\n");
	}
}