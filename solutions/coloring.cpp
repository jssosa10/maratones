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
int color[10005],parent[10005],n;
vector<int> adj[10005];
int dfs(int init){
	int res = 0;
	for(vector<int>::iterator it= adj[init].begin(); it!= adj[init].end(); ++it){
		int h = *it;
		if(parent[init]!=h){
			parent[h]=init;
			res+=dfs(h);
		}
	}
	if(color[parent[init]]!=color[init]){
		res++;
		//printf("entro %d con p %d\n",init, parent[init]);
	}
	//printf("%d %d\n",init, res);
	return res;


}
int main(){
	scanf("%d",&n);
	for(int i=2; i<=n; i++){
		int v;
		scanf("%d",&v);
		adj[i].push_back(v);
		adj[v].push_back(i);
	}

	for(int i  = 1; i<=n;i++ ){
		scanf("%d",&color[i]);
	}

	color[0]=0;
	parent[1]=0;

	printf("%d",dfs(1));

	return 0;
}

