#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> v[2][N];
int vis[N][N];
void bfs(int a, int b){
	queue<pair<int,int> >q;
	q.push(make_pair(a,b));
	vis[a][b]=vis[b][a]=1;
	while(!q.empty()){
		pair<int,int> e = q.front();q.pop();
		a = e.first;
		b = e.second;
		for(int i=0; i<2;i++){
			for(int j=0; j<(int)v[i][a].size(); j++){
				for(int k=0; k<(int)v[i][b].size(); k++){
					int ka = v[i][a][j];
					int kb = v[i][b][k];
					if(vis[ka][kb]==0){
						vis[ka][kb]=vis[kb][ka]=1;
						q.push(make_pair(ka,kb));
					}
				}
			}
		}

	}
}
int T,id,n;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&id,&n);
		for (int i = 0; i < 2; i++){
			for (int j = 0; i < n; j++){
				v[i][j].clear();
			}
		}
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			v[0][x].push_back(i);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			v[1][x].push_back(i);
		}
		for(int i=0;i<n;i++){
			if(vis[i][i]==0)bfs(i,i);
		}
		int flag = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if(vis[i][j]==0){
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
		printf("%d %s\n",id,(flag==1?"NO":"YES") );
	}
	return 0;
}