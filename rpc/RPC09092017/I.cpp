#include <bits/stdc++.h>
using namespace std;
const int M = 105;
int uf[M];
int tam[M];
priority_queue<pair<int,pair<int,int> > >arcos;
set<pair<int,pair<int,int> > > arbol;
pair<int,pair<int,int> >arc;
int T,n,m,res,x,y,cap;
int find(int u) {
	return (u == uf[u]) ? u : find(uf[u]);
}
void unionf(int u, int v) {
	int fu = find(u), fv = find(v); 
	if (tam[fu] < tam[fv]) 
		swap(fu, fv); 
	tam[fu] += tam[fv]; 
	uf[fv] = fu;
}
int main(){
	scanf("%d",&T);
	for(int i = 1; i<=T; i++){
		scanf("%d %d",&n,&m);
		while(m--){
			scanf("%d %d %d",&x,&y,&cap);
			arcos.push(make_pair(cap,make_pair(x,y)));
		}
		for(int j = 0; j<n; j++){
			uf[j]=j;
			tam[j]=1;
		}

		while(!arcos.empty()){
			arc = arcos.top();
			arcos.pop();
			if(find(arc.second.first)!= find(arc.second.second)){
				unionf(arc.second.first,arc.second.second);
				arbol.insert(arc);
					
			}
		}
		if(!arbol.empty()){
			arc = *arbol.begin();
			printf("Case #%d: %d\n",i,arc.first);
		}
		else
			printf("Case #%d: %d\n",i,INT_MAX);
		
		arbol.clear();

	}
	return 0;
}