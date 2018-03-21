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
int n,a[105],b[105];
int main(){
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d",a+i);
		b[a[i]-1]=i+1;
	}
	printf("%d",b[0]);
	for(int i = 1; i<n;i++)
		printf(" %d",b[i]);
	printf("\n");
	return 0;
}

