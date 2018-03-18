#include <bits/stdc++.h>
using namespace std;
int dist[1030][1030];
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		memset(dist,0,sizeof(dist));
		scanf("%d",&n);
		for(int i = 1; i<n; i++){
			for(int j = i+1; j<=n; j++){
				scanf("%d",&dist[i][j]);
				dist[j][i]=dist[i][j];
			}
		}
		int ans = dist[1][2]-1;
		for(int i = 3; i<=n;i++){
			int minn = 1000000;
			for(int j = 2;j<i;j++){
				minn = min(dist[1][i]+dist[i][j]-dist[1][j],minn);
			}
			ans+=minn/2-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}