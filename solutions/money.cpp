#include <bits/stdc++.h>
using namespace std;
const int M = 10005;
bool visitado[M];
int val[M];
vector<int> g[M];
int x,y,n,m,v,T,res;
int dfs(int i){
	int res = val[i];
	visitado[i]=true;
	for(vector<int>::iterator it = g[i].begin(); it!=g[i].end(); ++it){
		if(!visitado[*it])
		res+=dfs(*it);
	}
	return res; 
}
int DFS(){
	int act = 0;
	for(int i = 0; i<n && act==0; i++){
		if(!visitado[i])
		act+=dfs(i);
	}
	return act;
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(visitado,false,sizeof(visitado));
		scanf("%d %d",&n,&m);
		for(int i = 0; i<n;i++){
			scanf("%d",&v);
			val[i]=v;
		}
		while(m--){
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(DFS()){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("POSSIBLE\n");
		}
		for (auto& v : g) {
               v.clear();
            }
	}
	return 0;
}