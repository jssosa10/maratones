#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+10;
const int N = 1e5+10;
int n,g,T;
int f[N][4];
bool vis[N][2];
void dfs(int u, int x,int dir, int &val){
	if(vis[u][x])return;
	vis[u][x] = true;
	int a = f[u][x], b = f[u][x+2];
	if(dir) swap(a,b);
	if(a==g||b==g||u==g)val =1;
	int id = -1;
	for(int i = 0; i<4; i++)if(f[b][i]==u){
		if(i>=2){
			dfs(b,i-2,1,val);
		}
		else{
			dfs(b,i,0,val);
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&g);
		for(int i =1; i<=n; ++i){
			for (int j = 0; j < 4; ++j){
				scanf("%d",&f[i][j]);
			}
			vis[i][0]=vis[i][1]=0;
		}
		int ans =0;
		for(int i=1; i<=n; ++i){
			for(int j=0; j<2; ++j){
				if(!vis[i][j]){
					int v = 0;
					dfs(i,j,0,v);
					ans+=1-v;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}