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
long long n;
int main(){
	scanf("%lld",&n);
	long long sum  = n*(n+1)/2;
	if(sum%2==0){
		printf("0\n");
	}
	else
		printf("1\n");
	sum = sum/2;
//	printf("%lld\n",sum);
	vector<int> s;
	for(long long i = n;i>=1;i--){
		if(sum>=i){
			sum-=i;
			s.push_back(i);
		}
	}
	printf("%ld",s.size());
	for(unsigned int i  = 0; i<s.size();i++){
		printf(" %d",s[i]);
	}
	printf("\n");
	return 0;
}

