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
int n,q,a[100005]={0},pos[32][100005]={{0}};
int main(){
	//printf("%d\n",(1<<31)-1);
	scanf("%d%d",&n,&q);
	for(int i = 1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=0;i<31; i++){
		for(int j = 1; j<=n; j++){
			pos[i][j]=(pos[i][j-1])+((a[j]>>i)&1);
		}
	}
	//printf("%d\n",pos[0][5]);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int k = r-l+1;
		int res = 0;
		for(int i = 30; i>=0; i--){
			int o = pos[i][r]-pos[i][l-1];
			//printf("%d %d\n",o,k);
			if(2*o>=k)
				res = 2*res;
			else
				res= 2*res+1;	
		}
		printf("%d\n",res);
	}
	return 0;
}

