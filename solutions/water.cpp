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
int t,n,k,x[205];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(x,0,sizeof(x));
		scanf("%d %d",&n,&k);
		int y;
		for(int i = 0; i<k; i++){
			scanf("%d",&y);
			x[y]=1;
		}
		int ttt =1;
		bool ter = false;
		while(!ter){
			//printf("entro\n");
			bool enc = false;
			int yy[205];
			for(int i = 1; i<=n; i++){
				if(x[i]==0){
					enc =true;
				}
				yy[i]=x[i];
				if(i>0)
					yy[i]|=x[i-1];
				if(i<n)
					yy[i]|=x[i+1];
				//printf("%d\n",x[|i]);
			}
			for(int i = 1; i<=n; i++){
				x[i]=yy[i];
			}
			if(enc)
				ttt++;
			else
				ter = true;
		}
		printf("%d\n",ttt);
	}

	return 0;
}

