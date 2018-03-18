#include <bits/stdc++.h>
using namespace std;
int T,n,m,p[105];
vector<int> g[105];
int calc(int n, int &res){
	res+=p[n];
	int pos = -1;
	int mx = 0;
	for(vector<int>::iterator it = g[n].begin(); it!=g[n].end();++it){
		int d = *it;
		if(p[d]>mx){
			mx = p[d];
			pos = d;		
		}
	}
	if(pos!=-1)
	return calc(pos,res);
	else return n;
}
int main(){
	scanf("%d",&T);
	for(int i = 1; i<=T; ++i){
		scanf("%d%d",&n,&m);
		for(int j = 0; j<n; ++j){
			scanf("%d",&p[j]);
		}
		for(int j = 0; j<m; ++j){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
		}
		int res = 0;
		int ps = calc(0,res);
		for(int j = 0; j<n; ++j){
			g[j].clear();
		}
		printf("Case %d: %d %d\n",i,res, ps);
	}
	return 0;
}