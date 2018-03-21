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
int n,k,a[2005];
int main(){
	scanf("%d%d",&n,&k);
	for(int i  = 0; i<n; i++)
		scanf("%d",a+i);
	int sum = 0;
	for(int i = 0; i<n; i++){
		if(a[i]+k<=5)
			sum++;
	}
	printf("%d\n",sum/3);
	return 0;
}

