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
int a[55];
int t,n;
int main(){
	int c =4;
	a[1]=1; a[2]=3;
	for(int i = 3; i<50; i+=2){
		a[i]=a[i-1]+c;
		a[i+1]=a[i]+c;
		c+=2;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}

