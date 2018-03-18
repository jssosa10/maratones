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
#define pi pair<int,int>
const int N = 1e5+5;
const int inf = 1e9;
int tc;
int n,m,s,t;
vector<pi> g[N];
int dist[N];
int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d%d%d",&n,&m,&s,&t);
		for(int i = 0; i<n; i++)
			g[i].clear();
		for(int i = 0; i<m; i++){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			g[u].push_back({v,c});
			g[v].push_back({u,c});
		}
		for(int i =0 ; i<=n; ++i)
			dist[i]=inf;
		priority_queue<pi,vector<pi>,greater<pi>> pq;
		pq.push({dist[s]=0,s});
		while(!pq.empty()){
			auto now = pq.top(); pq.pop();
			int u = now.second, d = now.first;
			if(d>dist[u]) continue;
			for(auto cur : g[u]){
				int w = cur.second, v = cur.first;
				if(dist[u]+w<dist[v]){
					dist[v]=dist[u]+w;
					pq.push({dist[v],v});
				}
			}
		}
		if(dist[t]==inf) printf("NONE\n");
		else
			printf("%d\n",dist[t]);
	}
	return 0;
}

