#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
int uf[M];
int tam[M];
pair<int,int> puntos[M];
int x,y,n,T,r,states;
double roads,rails;
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
int dist(pair<int,int> i, pair<int,int> j){
	return (i.first-j.first)*(i.first-j.first)+(i.second-j.second)*(i.second-j.second);
}

int main(){
	scanf("%d",&T);
	for(int t = 1; t<=T; t++){
		priority_queue<pair<int, pair<int,int> > > arcs; 
		rails = 0;
		roads = 0;
		states = 1;
		scanf("%d %d",&n,&r);
		for(int i = 0; i<n;i++){
			scanf("%d %d",&x, &y);
			puntos[i]=make_pair(x,y);
			uf[i]=i;
			tam[i]=1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				arcs.push(make_pair(-dist(puntos[i],puntos[j]),make_pair(i,j)));
			}
		}
		while(!arcs.empty()){
			pair<int,pair<int,int> > p; p = arcs.top();
			arcs.pop();
			if(find(p.second.first)!= find(p.second.second)){
				unionf(p.second.first,p.second.second);
				int act = (-p.first);
				if(act<=(r*r))
					roads+=sqrt(act);
				else{
					states++;
					rails+=sqrt(act);
				}
			}
		}
		printf("Case #%d: %d %d %d\n",t,states,(int)(roads+0.5),(int)(rails+0.5));
	}	
	return 0;
}