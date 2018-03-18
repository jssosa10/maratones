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
int t,n,c;
double a[1000005],d,s;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i  =0; i<n; i++)
			scanf("%lf",a+i);
		scanf("%d%lf%lf",&c,&d,&s);
		double mx = 0;
		for(int i  =0; i<n; i++)
			mx = max(mx,a[i]);
		double res = (c-1)*mx;
		printf("%.9f",res);

	}

	return 0;
}

