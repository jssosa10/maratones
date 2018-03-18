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
int t,n,a[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i<n; i++)
			scanf("%d",a+i);
		sort(a,a+n);
		int r = 0;
		for(int i=1; i<n; i++){
			if(a[i]==a[i-1])
				r++;
		}
		printf("%d\n",r);
	}
	return 0;
}

