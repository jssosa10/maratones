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
int t,n,f[100005],g[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i<n; i++)
			scanf("%d",f+i);
		for(int i = 0; i<n; i++)
			scanf("%d",g+i);
		int res = 0;
		bool pudo = true;
		for(int i = 0; i<n && pudo; i++)
			if(g[i]<f[i])
				pudo =false;
		if(pudo)
			res+=1;
		pudo = true;
		for(int i = 0; i<n && pudo; i++)
			if(g[n-1-i]<f[i])
				pudo =false;
		if(pudo)
			res+=2;
		if(res==3)
			printf("both\n");
		if(res==2)
			printf("back\n");
		if(res==1)
			printf("front\n");
		if(res==0)
			printf("none\n");

	}
	return 0;
}

