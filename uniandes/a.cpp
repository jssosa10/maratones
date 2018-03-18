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
vector<int> g[50000];
bool vis[50000];
int main(){
	while(scanf("%d %d",&n,&m)&&n+m){
		memset(vis,0,sizeof(vis));
		for(int i = 0; i<m; i++){
			int k;
			scanf("%d",&k);
			vector<int> v;
			int x;
			while(k--){
				scanf("%d",&x);
				v.push_back(x);
			}	
			for(int i =1; i<v.size(); i++)
				unionf(v[0],v[i]);
		}
		printf("%d\n",tam[find(0)]);
	}
	return 0;
}

