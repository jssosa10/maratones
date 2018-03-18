#include <bits/stdc++.h>
using namespace std;
int n,x,a[100010],b[100010];
int main(){
	scanf("%d",&n);
	while(n){
		for(int i = 1; i<=n; i++){
			scanf("%d",&a[i]);
		}
		for(int i =1; i<=n; i++){
			scanf("%d",&x);
			b[x]=i;
		}
		int ans =0;
		for(int i =1;i<=n; i++){
			int minn = b[a[i]],maxn=b[a[i]];
			for(int j = i+1; j<=n; j++){
				minn = min(minn,b[a[j]]);
				maxn = max(maxn,b[a[j]]);
				if(maxn-minn==j-i){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}