#include <bits/stdc++.h>
using namespace std;
int T,N;
bool vis[105];
set<int> tasks[105];
vector<int> g[105];
set<int> dfs(int i){
	set<int> res;
	set<int> act;
	vis[i]=true;
	for(vector<int>::iterator it=g[i].begin(); it!=g[i].end(); ++it){
	    int j = *it;
	    j--;
		if(!vis[j]){
			act = dfs(j);
		}
		else
			act = tasks[j];
		act.insert(j);
		for(set<int>::iterator it = act.begin();it!=act.end(); ++it ){
			res.insert(*it);
		}
	}
	tasks[i]=res;
	return tasks[i];
}
int DFS(){
	int m = 0;
	int pos = 0;
	for(int  i = 0; i<N;i++){
		if(!vis[i]){
			dfs(i);
		}
		
	}
	for(int i  =0; i<N; i++){
		if(m<tasks[i].size()){
			m=tasks[i].size();
			pos = i;
		}
	}
	return pos+1;
}
int main(){
	while(scanf("%d",&N)==1&&N!=0){
		memset(vis,false,sizeof(vis));
		for(int i = 0; i<N; i++){
			scanf("%d",&T);
			for(int j=0;j<T;j++){
				int d;
				scanf("%d",&d);
				g[i].push_back(d);
			}
		}
		printf("%d\n",DFS());
		for(int i  =0; i<N; i++){
			g[i].clear();
		
		}
	}

	return 0;
}