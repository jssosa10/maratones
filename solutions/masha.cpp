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
int v1,v2,v3,vm;
int main(){
	scanf("%d%d%d%d",&v1,&v2,&v3,&vm);
	int maxv1= 2*v1, maxv2= 2*v2, maxv3 = min(vm*2,v3*2); 
	int minv1 = max(2*vm+1,v1), minv2=max(2*vm+1,v2), minv3= max(v3,vm);
	for(int i = minv1; i<=maxv1;i++)
		for(int j = minv2; j<=maxv2;j++)
			for(int k = minv3; k<=maxv3; k++)
				if(i>j&&j>k){
					printf("%d\n%d\n%d\n",i,j,k);
					return 0;
				}
	printf("-1\n");
	return 0;
}

