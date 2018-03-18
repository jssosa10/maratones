#include <bits/stdc++.h>
using namespace std;
int T,l,n,act,maxmin,maxmax;
int main(){
	scanf("%d",&T);
	while(T--){
		maxmin = maxmax=0;
		scanf("%d %d",&l,&n);
		for(int i = 0; i<n; i++){
			scanf("%d",&act);
			if(act>l/2){
				maxmin = max(l-act,maxmin);
				maxmax = max(act,maxmax);
			}
			else{
				maxmin = max(act,maxmin);
				maxmax = max(l-act,maxmax);
			}
		}
		printf("%d %d\n",maxmin,maxmax);
	}
	return 0;
}