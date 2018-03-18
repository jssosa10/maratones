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
#define M 1000005
int a[M], n;
vector<int> primes;
void sieve(){
	memset(a,0,sizeof(a));
	for(int i=2; i<M; i++){
		if(!a[i]){
			primes.push_back(i);
			for(int j = i*2; j<M; j+=i){
				a[j]=1;
			}
		}
	}
}
int main(){
	sieve();
	int c = 1;
	while(scanf("%d",&n)&&n){
		int res = 0;
		for(int i = 0; i<primes.size(); i++){
			if(primes[i]>=n)break;
			int j = upper_bound(primes.begin(),primes.end(), n-primes[i])-primes.begin();
			j--;
			if(j<=i)break;
			res+=(j-i);
		}
		printf("Case %d: %d\n",c++,res);
	}
	return 0;
}

