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
long long n, k;
int sol(long long i){
	int p = 0;
	while(i){
		i = i>>1;
		p++;
	}

	return p;
}
int main(){
	scanf("%lld%lld",&n,&k);
	int s = sol(n);
	long long res  =(long long)pow(2,s/1.0)-1;
	if(k>1)
		printf("%lld",res);
	else
		printf("%lld",n);
	return 0;
}

