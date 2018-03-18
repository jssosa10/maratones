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
long long a,b,x,y,z;
int main(){
	scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&z);
	long long res = 0;
	res += max(0LL,2*x+y-a);
	res += max(0LL, 3*z+y-b);
	printf("%lld\n",res);
	return 0;
}

