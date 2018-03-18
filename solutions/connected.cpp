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
int n,m;
vector<int> g[200005];
bool vis[200005];
void dfs(int i){
	vis[i]=true;
	for(vector<int>:: iterator it = g[i].begin(); it!=g[i].end(); ++it){
		int k = *it;
		if(!vis[k])
			dfs(k);
	}
}
int DFS(){
	int res =0;
	for(int i =1; i<=n; i++){
		if(!vis[i]){
			res++;
			dfs(i);
		}
	}
	return res;
	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i =0; i<m; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int comps = DFS();
	//printf("%d\n",comps);
	if(comps>1){
		printf("1\n");
		printf("%d\n",n);
	}
	else{
		int o = 0;
		for(int i =1; i<=n; i++){
			if(g[i].size()==n-1)
				o++;
		}
		if(o<n){
			printf("%d\n",o+1);
			printf("1");
			for(int i =1;i<o; i++)
				printf(" 1");
			printf(" %d\n",n-o);

		}
		else{
			printf("%d\n",o);
			printf("1");
			for(int i = 1; i<o; i++){
				printf(" 1");
			}
			printf("\n");
		}

	}
	return 0;
}

