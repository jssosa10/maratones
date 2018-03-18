#include <bits/stdc++.h>
using namespace std;
vector<int> g[21];
int s,d,n,x,y;
int bfs(int s, int d){
	int cnt =0 ,isV[21],parent[21];
	for(int i=0; i<21; i++){
		isV[i]=0;
	}
	queue<int>q;
	q.push(s);
	isV[s]=1;
	parent[s]=s;
	while(!q.empty()){
		int u =q.front();
		for(int i =0; i<g[u].size();i++){
			int v = g[u][i];
			if(!isV[v]){
				isV[v]=1;
				q.push(v);
				parent[v]=u;
			}
		}
		q.pop();
	}
	while(s!=d){
		d=parent[d];
		cnt++;
	}
	return cnt;
}
int main(){
	int t = 0;
	while(scanf("%d",&x)!=EOF){
		int j=0,i,k;
		for(i=0,j++;i<x;i++){
			scanf("%d",&y);
			g[j].push_back(y);
			g[y].push_back(j);
		}
		for(i=1;i<19;i++){
			scanf("%d",&x);
			for(k=0,j++;k<x;k++){
				scanf("%d",&y);
				g[j].push_back(y);
				g[y].push_back(j);
			}
		}
		if(j==19){
			scanf("%d",&n);
			printf("Test Set #%d\n", ++t);
			for(int i =0;i<n;i++){
				scanf("%d%d",&s,&d);
				printf("%2d to %2d: %d\n",s,d,bfs(s,d));	
			}
			printf("\n");
			for(int i = 0; i<21;i++){
				g[i].clear();
			}
		}
	}
	return 0;
}