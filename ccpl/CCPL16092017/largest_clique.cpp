#include <bits/stdc++.h>
using namespace std;
// 0 = blaco 1 = gris 2 = negro; 
int color[1005];
int val[1005];
int T,n,m,x,y,res;
vector<int> g[1005];
int dfs(int i){
	color[i]=1;
	int res = 0;
	for(vector<int>::iterator it = g[i].begin(); it!=g[i].end(); ++it){
		int j = *it;
		if(!color[j])res = max(res,dfs(j));
		else if(color[j]==2) res = max(res,val[j]);
	}
	val[i]=res+1;
	return val[i];
}
int DFS(){
	int res = 0;
	for(int i = 1; i<= n; i++){
		if(color[i]==0){
			dfs(i);
		}
		res = max(res,val[i]);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(val,0,sizeof(val));
		memset(color,0,sizeof(color));
		scanf("%d %d",&n,&m);
		while(m--){
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
		}
		printf("%d\n",DFS());
	}
}