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
int t,n,p,q,d;
int main(){
	scanf("%d",&t);
	while(t--){
		double mx=0,mn=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d%d%d",&p,&q,&d);
			double x = p*(100+d)/100.0;
			x = x*(100-d)/100.0;
		       	mn += x*q;	
			mx += p*q;
		}
		printf("%.5f\n",max(mx-mn,0.0));
	}
	return 0;
}

