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
long long n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	set<long long> x;
	
	for(long long i = 1LL; i<=k; i++){
		if(x.find(n%i)==x.end()){
			x.insert(n%i);

		}
		else{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}

