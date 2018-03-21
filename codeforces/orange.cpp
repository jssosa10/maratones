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
int n,k,a[100],rr[1000];
int main(){
	for(int i = 0; i<1000; i++)
		rr[i]=1;
	scanf("%d%d",&n,&k);
	for(int i = 0; i<k; i++){
		scanf("%d",a+i);
		rr[a[i]]--;
	}
	for(int i  = 0;i<k; i++){
		printf("%d",a[i]);
		int r = 1;
		for(int j = 1; j<=n*k && r<n; j++){
			//printf("%d %d %d\n",r,n,rr[j]);
			if(rr[j]>0){
				//printf("entor j = %d\n",j);
				printf(" %d",j);
				r++;
				rr[j]--;
			}
		}
		printf("\n");
	}

	return 0;
}

