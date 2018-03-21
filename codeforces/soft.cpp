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
int n,k,l,c,d,p,nl,np;
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	int ll = l*k;
	int sl = c*d;
	int res = min(sl/n,min(ll/(nl*n),p/(np*n)));
	printf("%d\n",res);
	return 0;
}

