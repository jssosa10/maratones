#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+5;
int uf[M];
int tam[M];
int dpt[M];
int par[M][20];
int maxw[M][20];
map<pair<int,int>,int> mp;
priority_queue<pair<int,pair<int,int> > >arcos;
set<pair<int,pair<int,int> > > arbol;
pair<int,pair<int,int> >arc;
vector<pair<int,int> >G[M];
int n,r,x,y,c,q,cost=0;
void dfs_dpt(int u, int fa, int d){
	//printf("Entrando u=%d fa =%d d=%d\n",u,fa,d);
	dpt[u]=d;
	par[u][0]=fa;
	//printf("inicializo %d\n",u);
	for(pair<int,int> p: G[u]){
		int w,v;
		tie(w,v)=p;
		//printf("inicializo u=%d v=%d w=%d fa=%d\n",u,v,w,fa);
		if(v==fa) continue;
		maxw[v][0]=w;
		//printf("llamando\n");
		dfs_dpt(v,u,d+1);
	}
}
int find(int u) {
	return (u == uf[u]) ? u : uf[u]=find(uf[u]);
}
void unionf(int u, int v) {
	int fu = find(u), fv = find(v); 
	if (tam[fu] < tam[fv]) 
		swap(fu, fv); 
	tam[fu] += tam[fv]; 
	uf[fv] = fu;
}
int main(){
	while(scanf("%d %d",&n,&r)==2){
	while(r--){
		scanf("%d %d %d",&x,&y,&c);
		arcos.push({-c,{x,y}});
		if(x<y)swap(x,y);
		mp[{x,y}]=c;
	}
	memset(uf,0,sizeof(uf));
	memset(tam,0,sizeof(tam));
	for(int j = 1; j<=n; j++){
		uf[j]=j;
		tam[j]=1;
	}
	cost = 0;
	while(!arcos.empty()){
		arc = arcos.top();
		arcos.pop();
		int u = arc.second.first;
		int v = arc.second.second;
		int c = -arc.first;

		if(find(u)!= find(v)){
			unionf(u,v);
			G[u].push_back({c,v});
			G[v].push_back({c,u});
			cost+=c;
		}
	}
	memset(par,-1,sizeof(par));
	memset(maxw,0,sizeof(maxw));
	dfs_dpt(1,-1,0);
	for(int i = 0; i+1<20;++i){
		for(int j = 1; j<=n;++j){
			int m = par[j][i];
			if(m==-1)continue;
			par[j][i+1]=par[m][i];
			maxw[j][i+1] = max(maxw[j][i],maxw[m][i]);
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		int best = 0;
		if(y>x)swap(x,y);
		int w = mp[{x,y}];
		int u = x; int v = y;
		if(!(dpt[u]>=dpt[v])){
			swap(u,v);
		}
		for(int i = 20-1; dpt[u]-dpt[v];--i){
			if(dpt[u]-dpt[v]>=1<<i){
				best = max(best,maxw[u][i]);
				u = par[u][i];
			}
		}
		for(int i = 20-1;u!=v && par[u][0]!=par[v][0];--i){
			if(par[u][i]!=par[v][i]){
				best=max(best,maxw[u][i]);
				best=max(best,maxw[v][i]);
				u = par[u][i];
				v = par[v][i];
			}
		}
		if(u!=v){
			best=max(best,maxw[u][0]);
			best=max(best,maxw[v][0]);
		}
		printf("%d\n",cost+w-best);
	}
	for(int i = 0; i<M; i++){
		G[i].clear();
	}
	}

	return 0;
}
