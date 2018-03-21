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
#define ll long long
ll n;
bool isl(int x){
	if(x==0)
		return false;
	bool res = true;
	while(x!=0&&res){
		if(x%10!=7&&x%10!=4)
			res = false;
		x/=10;
	}
	return res;
}
bool is(ll x){
	int sum = 0;
	while(x!=0){
		if(x%10==4||x%10==7)
			sum++;
		x/=10;
	}
	return isl(sum);

}
int main(){
	scanf("%lld",&n);
	if(is(n))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
