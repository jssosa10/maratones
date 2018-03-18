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
#define cu pair<pair<int,int>, int>
#define pb push_back
#define ff first
#define ss second
int n,t=1,dp[100];
vector<cu> v;
bool vis[100];
bool can(cu s, cu g){
	return (s.ff.ff<g.ff.ff && s.ff.ss<g.ff.ss) ||(s.ff.ff<g.ff.ss&&s.ff.ss<g.ff.ff);
}
int  dfs(int node){
	int mm = 0;
	vis[node]=true;
	for(int i = 0; i<v.size(); i++){
		if(can(v[i],v[node])){
			if(dp[i]!=-1||vis[i]){
				mm = max(mm,dp[i]);
			}
			else{
				mm = max(mm,dfs(i));
			}
		}
	}
	return dp[node]=mm+v[node].second;
}
void DFS(){
	for(int i  =0; i<v.size(); i++){
		if(dp[i]==-1&&!vis[i]){
			dfs(i);
		}
	}
}
int main(){
	while(scanf("%d",&n)&&n){
		memset(vis,0,sizeof(vis));
		memset(dp, -1, sizeof(dp));
		v.clear();
		int x,y,z;
		for(int i = 0; i<n; i++){
			scanf("%d%d%d",&x,&y,&z);
			v.pb({{x,y},z});
			v.pb({{y,z},x});
			v.pb({{z,x},y});
		}
		DFS();
		int r =0;
		for(int i =0; i<v.size(); i++)
			r = max(r,dp[i]);
		printf("Case %d: maximum height = %d\n",t,r);
		t++;
	}
	return 0;
}

