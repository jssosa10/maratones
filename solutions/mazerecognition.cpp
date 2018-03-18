#include <bits/stdc++.h>
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
int a[205][205],ex,ey,visit[205][205],d[205][205][4],us[300];
char ns[300],ST[7];
void dfs(int x, int y){
	char s[7];
	scanf("%s",s);
	visit[x][y]=1;
	int len = strlen(s);
	for (int i = 0; i <len; ++i){
		if(s[i]=='*'){
			ex=x,ey=y;
			continue;
		}
		d[x][y][us[s[i]]]=1;
		int nx = x+dx[us[s[i]]],ny=y+dy[us[s[i]]];
		if(!visit[nx][ny]){
			printf("%c\n", s[i]);
			fflush(NULL);
			dfs(nx,ny);
			printf("%c\n",ns[s[i]]);
			fflush(NULL);
			scanf("%s",ST);
		}
	}
}
queue<pair<int,int> >q;
void bfs(){
	while(!q.empty()) q.pop();
	q.push(make_pair(100,100));
	visit[100][100]=1;
	while(!q.empty()){
		int x = q.front().first,y=q.front().second;
		if(ex==x&&ey==y){
			printf("%d\n",visit[x][y]-1);
			fflush(NULL);
			return;
		}
		q.pop();
		for(int i =0; i<4;i++){
			if(d[x][y][i]){
				int nx = x+dx[i],ny=y+dy[i];
				if(!visit[nx][ny]){
					visit[nx][ny]=visit[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}
void solve(){
	memset(visit,0,sizeof(visit));
	memset(d,0,sizeof(d));
	ex=ey=-1;
	dfs(100,100);
	memset(visit,0,sizeof(visit));
	if(ex==-1&&ey==-1){
		printf("-1\n");
		fflush(NULL);
	}
	else bfs();

}
int main(){
	ns['N']='S';
	ns['S']='N';
	ns['E']='W';
	ns['W']='E';
	us['N']=0;
	us['S']=1;
	us['E']=2;
	us['W']=3;
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}