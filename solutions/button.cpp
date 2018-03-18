#include <bits/stdc++.h>
using namespace std;
int n,T,t;
struct node{
	int s;
	int v;
}vis[3601];
bool f = false;
int cnt = 0;
int times[20];
void bfs(){
	queue<int>q;
	int now,nxt;
	now =0;
	q.push(now);
	f  =false;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now==t)break;
		for (int i = 0; i <n; ++i){
			nxt = now+times[i];
			if(nxt<0)nxt=0;
			if(nxt>3600)nxt=3600;
			if(!vis[nxt].v)q.push(nxt),vis[nxt].v++,vis[nxt].s=vis[now].s+1;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		for(int i = 0; i<=3600; i++)vis[i].v=0,vis[i].s=0;
		scanf("%d %d",&n,&t);
		for(int i = 0; i<n; ++i){
			int act;
			scanf("%d",&act);
			times[i]=act;
		}
		vis[0].v=1;
		bfs();
		if(!vis[t].v){
			int index = 0;
			int step = 1800;
			for (int i = t; i <= 3600; ++i)
			{
				if(vis[i].v){
					index=i;
					step = vis[i].s;
					break;
				}
			}
			printf("%d %d\n",vis[index].s,index-t);
		}
		else{
			printf("%d %d\n",vis[t].s,0);
		}
	}
	return 0;
}