#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int visited[100005];
int n,m,T;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(visited,0,sizeof(visited));
		scanf("%d %d",&n,&m);
		while(m--){
			int x,y;
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
		}
		
		printf("%d\n",res );

	}
	return 0;
}
