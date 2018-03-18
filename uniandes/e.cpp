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
char mp [105][105] ;
bool vis [105][105] ;
int n,m;
void dfs(int i,int j ){
	if(!vis[i][j]&&mp[i][j]=='@'){
	vis[i][j]=1;
	dfs(i+(i<n),j);
	dfs(i-(i>0),j);
	dfs(i+(i<n),j+(j<m));
	dfs(i-(i>0),j-(j>0));
	dfs(i-(i>0),j+(j<m));
	dfs(i+(i<n),j-(j>0));
	dfs(i,j+(j<m));
	dfs(i,j-(j>0));
	}
}
int DFS(){
	int res = 0;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			if(!vis[i][j]&&mp[i][j]=='@'){
				res++;
				dfs(i,j);
			}
	return res;

}
int main(){
	while(scanf("%d%d",&n,&m)&&n+m){
		memset(vis,0,sizeof(vis));
		for(int i = 0; i<n; i++)
			scanf("%s",mp[i]);
		printf("%d\n",DFS());
	}
	return 0;
}

