#include <bits/stdc++.h>
using namespace std;
int R,C,rl,rg,rm,cl,cg,cm;
set<pair<pair<int,int>,pair<int,int> > visitado;
queue <pair<pair<int,int>,pair<int,int> > > q;
int bfs(pair<pair<int,int>, pair<int,int> > p){
	q.push(p);
	visitado.insert(p);
	while(!q.empty()){
		p = q.pop();

	}
}
int main(){
	while(scanf("%d %d", &R,&C)!=EOF){
		char maze[R][C];
		scanf("%d %d %d %d %d %d",&rl,&rg,&rm,&cl,&cg,&cm);
		for(int i = 0;i<R;i++){
			scanf("%s",maze[i]);
		}
		int res = bfs(make_pair(make_pair(rg,cg),make_pair(rm,cm)));
		if(visitado[rm][cm][rm][cm])printf("NO LOVE");
		else printf("%d\n",res);
	}
}