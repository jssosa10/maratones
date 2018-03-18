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
int n,res = 0;
int main(){
	scanf("%d",&n);
	for(int i = 1; i<n; i++){
		int x = n-i;
		if(x%i==0)
			res++;	
	}
	printf("%d\n",res);
	return 0;
}

